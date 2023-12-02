/*
 keyestudio Mini Tank Robot v3.0
 lesson 20.1
 bluetooth test
 http://www.keyestudio.com
*/
char ble_val; //character variable, used to save the value from Bluetooth
void setup() {
  Serial.begin(9600);
}
void loop() {
  if(Serial.available() > 0)  //determine if there is data in serial buffer
  {
    ble_val = Serial.read();  //read the data in the serial buffer
    Serial.println(ble_val);  //print out
  }
}
