/*
  keyestudio Mini Tank Robot V3
  lesson 10.2
  Bluetooth
  http://www.keyestudio.com
*/
int LED = 9;
int ble_val; //Integer variable(used to store the value received by Bluetooth)

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}
void loop() {
  if (Serial.available() > 0) //Determine whether there is data in the serial port buffer
  {
    ble_val = Serial.read();  //Read the data in the serial port buffer
    Serial.println("DATA RECEIVED:");
    Serial.println(ble_val);
    if (ble_val == '1') {
      digitalWrite(LED, HIGH);
      Serial.println("led on");
    }
    if (ble_val == '0') {
      digitalWrite(LED, LOW);
      Serial.println("led off");
    }
  }
}
