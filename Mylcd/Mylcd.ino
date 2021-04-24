#include <LiquidCrystal.h>

LiquidCrystal mylcd(4,5,6,7,8,9);    //(RS,En,D4,D5,D6,D7)

void setup() {

  mylcd.begin(16,2);
  
}

void loop() 
{

  int dout= analogRead(A0);
  float volt = dout*0.00488;
  
 mylcd.setCursor(0,0); 
 mylcd.print("Voltage");
 mylcd.print(volt);


}
