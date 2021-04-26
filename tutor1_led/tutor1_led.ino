int led1 = 13;
void setup()
{
// initialize the digital pin as an output.
pinMode(led1, OUTPUT);
  int x;
 for(int x=0;x<3;x++){
  loop();
  }
  if(x=3){
  digitalWrite(led1, LOW);
  }
}


void loop()
{
  blink();
}

void blink()
{
digitalWrite(led1, HIGH);
delay(1000);
digitalWrite(led1, LOW);
delay(1000);
}
