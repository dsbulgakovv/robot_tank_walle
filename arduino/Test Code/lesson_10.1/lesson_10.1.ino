/*
  keyestudio Mini Tank Robot V3
  lesson 10.1
  Bluetooth
  http://www.keyestudio.com
*/
char ble_val; //charater varibles, used to save the value from BT

void setup() {
  Serial.begin(9600);
}
void loop() {
  if (Serial.available() > 0) //Determine if there is data in buffer
  {
    ble_val = Serial.read();  //read the data in the serial buffer
    Serial.println(ble_val);  //print out
  }
}
