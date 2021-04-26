void setup() {
  Serial.begin(9600);

}

void loop()
{

  int dout = analogRead(A0);
  Serial.println(dout);

  if(dout < 100)
  {
    Serial.println("I'm Blind");
  }
  else if(dout>100 && dout < 500) //150 condition
  {
    Serial.println("Light's OFF");
  }
else if (dout>500 && dout < 800) //700 condition
{
  Serial.println("Light's ON");
}
  
  delay(300);

}
