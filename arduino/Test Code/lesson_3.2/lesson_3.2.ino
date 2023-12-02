/*
  keyestudio Mini Tank Robot V3
  lesson 3.2
  photocell-analog output
  http://www.keyestudio.com
*/
int analogInPin = A2;    // A2 is the input pin of photoresistor
int analogOutPin = 9; // Digital port 9 is the output of PMW
int sensorValue = 0;  // 存放光敏电阻的值的变量
int outputValue = 0;  // Value output to PMW
void setup() {
  Serial.begin(9600); //Open the serial port monitor and set the baud rate to 9600
}
void loop() {
  sensorValue = analogRead(analogInPin); //Read the analog value from the photoresistor sensor
  // Map the analog values 0~1023 to the PWM output values 255~0
  outputValue = map(sensorValue, 0, 1023, 255, 0);
  // Change analog output
  analogWrite(analogOutPin, outputValue);
  //在下一个循环之前等待2毫秒进行模数转换
  //转换器在最后一次读取后稳定下来：
  Serial.println(sensorValue);  //The serial port prints the value of the photoresistor
  delay(2);
}
