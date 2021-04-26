
int n[10] = {1,2,3,4,5,6,7,8,9,10};
int total;

void setup() {
  Serial.begin(9600);

  for (int i=0; i<=9;i++){
    total += n[i];
  }
  Serial.println("Total: ");
  Serial.println(total);
}

void loop() {
  

}
