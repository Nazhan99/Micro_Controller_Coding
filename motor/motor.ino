
int in1=7; //connect with AIN1
int in2=8; //connect with AIN2
int pwm=9; //connect with PWMA
int stdby=10; //connect with STBY

void setup() 
{
  Serial.begin(9600); // coding for virtual terminal
  pinMode(in1,OUTPUT);pinMode(in2,OUTPUT);pinMode(pwm,OUTPUT);pinMode(stdby,OUTPUT);
}

void clockwise() //rotate in clockwise
{
 digitalWrite(stdby,HIGH);
 digitalWrite(in1,HIGH);
 digitalWrite(in2,LOW);
 analogWrite(pwm,100);
 delay(5000);
}

void stoprotate()// Stop rotate
{
  digitalWrite(stdby,LOW); 
  delay(1500); // stop 1.5s
}

void anticlockwise() // rotate in anticlockwise
{
  digitalWrite(stdby,HIGH); 
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  analogWrite(pwm,100);
  delay(5000);
}

void loop() 
{
  int dout = analogRead(A0); //read the variable resistor
  int val = map(dout,0,1023,0,255); // map the range of the value of the input voltage and the variable resistor

  Serial.println(val); //display the value on the virtual terminal
 
  clockwise();
  stoprotate();
  anticlockwise();
  stoprotate();
}
