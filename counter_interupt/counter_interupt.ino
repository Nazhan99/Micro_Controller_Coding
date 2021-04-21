
int i = 0; // the counter value
volatile int output=0; //state 0 is LED OFF

void setup() 
{
  Serial.begin(9600); //coding for virtual terminal
  pinMode(13,OUTPUT); //connect with LED
  attachInterrupt(digitalPinToInterrupt (3),button3,RISING); // coding for interrupt button
}

void button3() // Interrupt Service Routine function
{
  output=1;  //LED ON
  Serial.println("Interrupt at button 1 executed");
}

void loop() 
{
  output=0; //LED OFF
  Serial.print(" COUNTER: "); //print the counter in the virtual display
  Serial.print(i);
  ++i; //increment of the counter value
  delay(500);
  digitalWrite(13,output); //if button at pin 3 pressed, output = 1
  
}
