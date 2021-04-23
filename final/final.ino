#include<LiquidCrystal.h> //lcd library
#include <SimpleDHT.h> 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //assigning lcd pins (RS,En,D4,D5,D6,D7)


//temperature sensor
const int sensor=A1; // Assigning analog pin A1 to variable 'sensor'
float tempc;  //variable to store temperature in degree Celsius
float vout;  //temporary variable to hold sensor reading

const int buttonPin = 0;     // the number of the pushbutton pin
int buttonState = 0;         // variable for reading the pushbutton status

const int led= 13; //Connect with sounder
int level; // variable for monitoring level

//H-bridge device
int in1=7; //connect with AIN1
int in2=8; //connect with AIN2
int pwm=9; //connect with PWMA
int stdby=10; //connect with STBY

int pinDHT11 = 1;
SimpleDHT11 dht11(pinDHT11); 


void setup()
{
  pinMode(sensor,INPUT); // Configuring pin A1 as input
  pinMode(led, OUTPUT); // initialize the LED pin as an output:
  pinMode(buttonPin, INPUT);// initialize the pushbutton pin as an input:
  pinMode(in1,OUTPUT);pinMode(in2,OUTPUT);pinMode(pwm,OUTPUT);pinMode(stdby,OUTPUT); // configuring the H bridge pins as output
  Serial.begin(9600);
  lcd.begin(20,4); //set lcl (row,column) 
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

void led()  //activate sounder function
{

    digitalWrite(led, HIGH); // turn LED on:
}

void loop() 
{
  
  vout=analogRead(sensor);
  tempc=(vout*500)/1023; // Storing value in Degree Celsius

  byte humidity = 0;
  dht11.read(&temperature, &humidity, NULL);


  lcd.setCursor(0,0); //display on lcd at x=0, y-=0
  lcd.print("Temp(C)= "); //display on lcd
  lcd.print(tempc);
  lcd.setCursor(0,1); 
  lcd.print((int)humidity);
  lcd.println("RH");

digitalWrite(led, LOW);  // turn LED off:
buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
  stoprotate();

  //condition for temperature level
  if((tempc>=0 && tempc<=35) || (humidity>=0 && humidity<80)) //temperature range below 35
  {
      level=1;
  }

  else if(tempc>=36 && tempc<100 || (humidity>=80) )  //temperature range above 35
  {
    level=2;
  }
 
  }
  else //temperature is below 0 or above 100
  {
    level=3;
  }

  switch(level){

    case 1:  //temperature range 0-39
    Serial.println(" level 1");
    lcd.setCursor(0,3);
    lcd.print("LEVEL 1 SAFE      ");
    break;

    case 2:  //temperature range 80-100
    Serial.println(" level 2");
    lcd.setCursor(0,3);
    lcd.print("LEVEL 2 DANGER  ");
    clockwise(); //activate motor fan
    led();  //activate sounder
    break;

    case 3:  //temperature is below 0 or above 100
    Serial.println("Invalid Reading");
    lcd.setCursor(0,3);
    lcd.print("INVALID READING  ");
    break;
  }

}
