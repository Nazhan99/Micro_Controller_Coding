void setup() {
  for(int pin=8; pin<12; pin++) //loop for pin 8 until pin 11
  {
     pinMode(pin, OUTPUT);
  }

}

void loop() 
{
  for(int i=8; i<12;i++) //LED ON FROM LEFT TO RIGHT/ FROM PIN 8 TO PIN 11
  {
    digitalWrite(i, HIGH); 
    delay(20);
    digitalWrite(i+1, HIGH); 
    delay(20);
    digitalWrite(i+2, HIGH); 
    delay(20);
    digitalWrite(i, LOW); 
    delay(20);
    digitalWrite(i+1, LOW); 
    
  }
  for(int i=11; i>7; i--) //LED ON FROM RIGHT TO LEFT/ FROM PIN 11 TO PIN 8
  {
    digitalWrite(i, HIGH);
    delay(20);
    digitalWrite(i-1, HIGH);
    delay(20);
    digitalWrite(i-2, HIGH);
    delay(20);
    digitalWrite(i, LOW);
    delay(20);
    digitalWrite(i-1, LOW);
  }

}
