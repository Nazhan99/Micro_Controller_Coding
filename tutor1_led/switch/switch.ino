void setup() {
 Serial.begin(9600);
 Serial.println("Please select 1,2 or 3");

}

void loop() {
 if(Serial.available())
 {
  char selection = Serial.read();
  Serial.println(selection);

  switch (selection)
  {
    case 1:
    Serial.println(" You have pressed 1");
    break;

    case 2:
    Serial.println(" You have pressed 2");
    break;

    case 3:
    Serial.println(" You have pressed 3");
    break;

    default :
    Serial.println("Invalid Selection");
  }
 }
}
