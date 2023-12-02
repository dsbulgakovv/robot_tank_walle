/*
  keyestudio Mini Tank Robot V3
  lesson 8.2
  Ultrasonic LED
  http://www.keyestudio.com
*/
int trigPin = 12;    // Pin Trig attach to 12
int echoPin = 13;    // Pin Echo attach to 13
int LED = 9;
long duration, cm, inches;
void setup() {
  //enable the serial port
  Serial.begin (9600);//Set the baud rate to 9600
  //Define input and output
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LED, OUTPUT);
}
void loop() {
  //
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);//At least give 10us high level trigger
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // The time in high level equals the time gap between the transmission and the return of the ultrasonic sound
  duration = pulseIn(echoPin, HIGH);
  //Translate into distance
  cm = (duration / 2) / 29.1;   // Convert to centimetre
  inches = (duration / 2) / 74; // Convert to inch
  //Serial port print it
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  if (cm >= 2 && cm <= 10) {
    digitalWrite(LED, HIGH);//LED is on
  } else {
    digitalWrite(LED, LOW); //LED is off
  }
  delay(50);
}
