/*
  keyestudio Mini Tank Robot V3
  lesson 3.1
  photocell
  http://www.keyestudio.com
*/
int sensorPin = A2;    // A2 is the input pin of photoresistor
int sensorValue = 0;  // save the value of photoresistors
void setup() {
  Serial.begin(9600); //Open the serial port monitor and set the baud rate to 9600
}
void loop() {
  sensorValue = analogRead(sensorPin);  //Read the analog value from the photoresistor sensor
  Serial.println(sensorValue);  //The serial port prints the value of the photoresistor
  delay(500); //Delay in 500ms
}
