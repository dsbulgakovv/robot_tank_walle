/*
  keyestudio Mini Tank Robot V3
  lesson 7.1
  Servo
  http://www.keyestudio.com
*/
#define servoPin 10  //The pin of servo
int pos; //The variable of servo’s angle
int pulsewidth; //The variable of servo’s pulse width
void setup() {
  pinMode(servoPin, OUTPUT);  //Set the pin of servo as output 
  procedure(0); //Set the angle of servo to 0°
}
void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // From 1°to 180°
    // in steps of 1 degree
    procedure(pos);              // Rotate to the angle of 'pos'
    delay(15);                   //Control the speed of rotation
  }
  for (pos = 180; pos >= 0; pos -= 1) { // From 180° to 1°
    procedure(pos);              // Rotate to the angle of 'pos'
    delay(15);
  }
}
//The function controls the servo
void procedure(int myangle) {
  pulsewidth = myangle * 11 + 500;  //Calculate the value of pulse width
  digitalWrite(servoPin, HIGH);
  delayMicroseconds(pulsewidth);   //The time in high level represents the pulse width
  digitalWrite(servoPin, LOW);
  delay((20 - pulsewidth / 1000));  //As the cycle is 20ms, the time left is in low level
}
