/*
  keyestudio Mini Tank Robot V3
  lesson 7.2
  Servo
  http://www.keyestudio.com
*/
#include <Servo.h>
Servo myservo;  // 
int pos = 0;    // Save the variables of angle
void setup() {
  myservo.attach(10);  //Connect the servo with digital port 9
}
void loop() {
  for (pos = 0; pos <= 180; pos += 1) { //From 0°to 180°
    //step length is 1
    myservo.write(pos);              // Rotate to the angle of 'pos'
    delay(15);                       // Wait for 15ms to control speed
  }
  for (pos = 180; pos >= 0; pos -= 1) { //From 180° to 0°
    myservo.write(pos);              // Rotate to the angle of 'pos'
    delay(15);                       // Wait for 15ms to control speed
  }
}
