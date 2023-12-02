/*
  keyestudio Mini Tank Robot V3
  lesson 2.2
  pwm-slow
  http://www.keyestudio.com
*/
int LED = 9;  //Define the pin of LED to connect with digital port 9

void setup () {
  pinMode (LED, OUTPUT); //Initialize the LED pin to output mode
}
void loop () {
  for (int value = 0; value < 255; value = value + 1) {
    analogWrite (LED, value); // LED turns on
    delay (30); // Delay in 30ms
  }
  for (int value = 255; value > 0; value = value - 1) {
    analogWrite (LED, value); // LED turns off
    delay (30); // Delay in 30ms
  }
}
