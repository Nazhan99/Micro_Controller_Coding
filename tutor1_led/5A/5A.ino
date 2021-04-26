#define LED1 13
#define SW1 15
void setup()
{
pinMode(LED1, OUTPUT);
pinMode(SW1, INPUT);
}
void loop()
{
if (digitalRead(SW1) == 0) //button pushed
{
digitalWrite(LED1, HIGH); //LED blinking
delay(50);
digitalWrite(LED1, LOW);
delay(50);
}
else
{
digitalWrite(LED1, 1); //LED off =1
}
}
