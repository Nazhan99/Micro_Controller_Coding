#define LED1 13 //D1
#define LED2 12 //D2
#define LED3 11 //D3
#define SW1 15  //A1
#define SW2 16  //A2
#define SW3 17 //A0
int val = 0;
void setup()
{
pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(LED3, OUTPUT);
pinMode(SW1, INPUT);
pinMode(SW2, INPUT);
pinMode(SW3, INPUT);
}
void loop()
{
val = digitalRead(SW1); 
digitalWrite(LED1, val);
digitalWrite(LED2, digitalRead(SW2));
digitalWrite(LED3, digitalRead(SW3));
}
