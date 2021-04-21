
int i = 0;
volatile int output=0;

void setup() 
{
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  attachInterrupt(digitalPinToInterrupt (3),button3,RISING);
}

void button3() // ISR function
{
  output=1;
  Serial.println("Interrupt at button 1 executed");
}

void button2()
{
  output=0; //turn off led
  Serial.println("interrupt at button 2 executed");
}


void loop() 
{
  Serial.print(" COUNTER: ");
  Serial.print(i);
  ++i;
  delay(500);
  digitalWrite(13,output); //if button at pin 3 pressed, output = 1

}
