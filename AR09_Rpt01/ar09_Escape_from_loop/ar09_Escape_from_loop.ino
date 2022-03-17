void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
 Serial.print("Number =");
 Serial.print(number);
 Serial.print(", ");
 Serial.print(stringValue[0]);
 Serial.print(number,BIN);
 Serial.print(",");
 Serial.print(stringValue[1]);
 Serial.print(number,HEX);
 Serial.print();
 number++;
 if(number>15){
  Serial.print("Mission copleted");
  delay(1000);
  exit(0);
}
delay(1000);

}
