#include<LiquidCrystal.h> //lcd library
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //assigning lcd pins (RS,En,D4,D5,D6,D7)

//temperature sensor
const int sensor=A1; // Assigning analog pin A1 to variable 'sensor'
float tempc;  //variable to store temperature in degree Celsius
float vout;  //temporary variable to hold sensor reading

const int buzzer= 13; //Connect with sounder
int level; // variable for monitoring level

//H-bridge device
int in1=7; //connect with AIN1
int in2=8; //connect with AIN2
int pwm=9; //connect with PWMA
int stdby=10; //connect with STBY

void setup()
{
  pinMode(sensor,INPUT); // Configuring pin A1 as input
  pinMode(in1,OUTPUT);pinMode(in2,OUTPUT);pinMode(pwm,OUTPUT);pinMode(stdby,OUTPUT); // configuring the H bridge pins as output
  Serial.begin(9600);
  lcd.begin(16,2); //set lcl (row,column) 
  delay(500);
}

void clockwise() //rotate in clockwise
{
 digitalWrite(stdby,HIGH);
 digitalWrite(in1,HIGH);
 digitalWrite(in2,LOW);
 analogWrite(pwm,100);
}

void stoprotate()// Stop rotate
{
  digitalWrite(stdby,LOW); 
}

void buzz()  //activate sounder function
{
  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(1000);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(1000);        // ...for 1sec
}

void loop() 
{
  
  vout=analogRead(sensor);
  tempc=(vout*500)/1023; // Storing value in Degree Celsius
  lcd.setCursor(0,0); //display on lcd at x=0, y-=0
  lcd.print("Temp(C)= "); //display on lcd
  lcd.print(tempc);
  delay(1000); //Delay of 1 second for ease of viewing in serial monitor
  stoprotate();

  //condition for temperature level
  if(tempc>=0 && tempc<40) //temperature range 0-39
  {
      level=1;
  }

  else if(tempc>39 && tempc<80)  //temperature range 40-79
  {
    level=2;
  }
  else if(tempc>79 && tempc<=100) //temperature range 80-100
  {
    level=3;
  }
  else //temperature is below 0 or above 100
  {
    level=4;
  }

  switch(level){

    case 1:  //temperature range 0-39
    Serial.println(" level 1");
    lcd.setCursor(0,1);
    lcd.print("LEVEL 1 SAFE      ");
    break;

    case 2:  //temperature range 40-79
    Serial.println(" level 2");
    lcd.setCursor(0,1);
    lcd.print("LEVEL 2 HOT     ");
    break;

    case 3:  //temperature range 80-100
    Serial.println(" level 3");
    lcd.setCursor(0,1);
    lcd.print("LEVEL 3 DANGER  ");
    clockwise(); //activate motor fan
    buzz();  //activate sounder
    break;

    case 4:  //temperature is below 0 or above 100
    Serial.println("Invalid Reading");
    lcd.setCursor(0,1);
    lcd.print("INVALID READING  ");
    break;
  }

}
