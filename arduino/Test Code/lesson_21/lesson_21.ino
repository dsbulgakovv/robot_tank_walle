/*
  keyestudio Mini Tank Robot V3
  lesson 21
  bluetooth control speed tank
  http://www.keyestudio.com
*/

//Array, used to save data of images, can be calculated by yourself or gotten from modulus tool
unsigned char start01[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
unsigned char front[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0x12, 0x09, 0x12, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char back[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0x48, 0x90, 0x48, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char left[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x44, 0x28, 0x10, 0x44, 0x28, 0x10, 0x44, 0x28, 0x10, 0x00};
unsigned char right[] = {0x00, 0x10, 0x28, 0x44, 0x10, 0x28, 0x44, 0x10, 0x28, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char STOP01[] = {0x2E, 0x2A, 0x3A, 0x00, 0x02, 0x3E, 0x02, 0x00, 0x3E, 0x22, 0x3E, 0x00, 0x3E, 0x0A, 0x0E, 0x00};
unsigned char clear[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char speed_a[] = {0x00, 0x00, 0x00, 0x20, 0x10, 0x08, 0x04, 0x02, 0xff, 0x02, 0x04, 0x08, 0x10, 0x20, 0x00, 0x00};
unsigned char speed_d[] = {0x00, 0x00, 0x00, 0x04, 0x08, 0x10, 0x20, 0x40, 0xff, 0x40, 0x20, 0x10, 0x08, 0x04, 0x00, 0x00};
#define SCL_Pin  A5  //set the pin of clock to A5
#define SDA_Pin  A4  //A4 set data pin to A4

#define ML_Ctrl 4  //define the direction control pin of thel left motor
#define ML_PWM 5   //define the PWM control pins of the left motor
#define MR_Ctrl 2  //define the direction control pin of thel right motor
#define MR_PWM 6   //define the PWM control pin of the right motor
char ble_val;      //used to save the value from Bluetooth
byte speeds = 200;;//the initial speed is 200

void setup() {
  Serial.begin(9600);

  pinMode(ML_Ctrl, OUTPUT);
  pinMode(ML_PWM, OUTPUT);
  pinMode(MR_Ctrl, OUTPUT);
  pinMode(MR_PWM, OUTPUT);

  pinMode(SCL_Pin, OUTPUT);
  pinMode(SDA_Pin, OUTPUT);
  matrix_display(clear); //clear screens
  matrix_display(start01);  //show start image
}

void loop() {
  if (Serial.available() > 0) {
    ble_val = Serial.read();
    Serial.println(ble_val);
  }
  switch (ble_val) {
    case 'F':  //the command to go front
      Car_front();
      break;
    case 'B':  //the command to go back
      Car_back();
      break;
    case 'L':  //the command to turn left
      Car_left();
      break;
    case 'R':  //the command to turn right
      Car_right();
      break;
    case 'S':  //the command to stop
      Car_Stop();
      break;
    case 'Z':  //speed up
      speeds_a();
      break;
    case 'X':  //speed down
      speeds_d();
      break;
  }

}

/***************motor runs***************/
void Car_front() {
  digitalWrite(MR_Ctrl, LOW);
  analogWrite(MR_PWM, speeds);
  digitalWrite(ML_Ctrl, LOW);
  analogWrite(ML_PWM, speeds);
  matrix_display(front);  //show the image of going front
}

void Car_back() {
  digitalWrite(MR_Ctrl, HIGH);
  analogWrite(MR_PWM, speeds);
  digitalWrite(ML_Ctrl, HIGH);
  analogWrite(ML_PWM, speeds);
  matrix_display(back);  //show the image of going back
}

void Car_left() {
  digitalWrite(MR_Ctrl, LOW);
  analogWrite(MR_PWM, speeds);
  digitalWrite(ML_Ctrl, HIGH);
  analogWrite(ML_PWM, speeds);
  matrix_display(left);  //show the image of anticlockwise rotation
}

void Car_right() {
  digitalWrite(MR_Ctrl, HIGH);
  analogWrite(MR_PWM, speeds);
  digitalWrite(ML_Ctrl, LOW);
  analogWrite(ML_PWM, speeds);
  matrix_display(right);  //show the image of clockwise rotation
}

void Car_Stop() {
  digitalWrite(MR_Ctrl, LOW);
  analogWrite(MR_PWM, 0);
  digitalWrite(ML_Ctrl, LOW);
  analogWrite(ML_PWM, 0);
  matrix_display(STOP01);  //show the image of stopping
}

void Car_T_left() {
  digitalWrite(MR_Ctrl, LOW);
  analogWrite(MR_PWM, 255);
  digitalWrite(ML_Ctrl, LOW);
  analogWrite(ML_PWM, 150);
  matrix_display(left);  //show the image of turning left
}

void Car_T_right() {
  digitalWrite(MR_Ctrl, LOW);
  analogWrite(MR_PWM, 150);
  digitalWrite(ML_Ctrl, LOW);
  analogWrite(ML_PWM, 255);
  matrix_display(right);  //show the image of turning right
}

void speeds_a() { //Deceleration function
  matrix_display(speed_a);  //show the image of speeding up
  while (1) {
    Serial.println(speeds);  //show the speed
    if (speeds < 255) { //increase to 255
      speeds++;
      delay(10);  //regulate speed
    }
    ble_val = Serial.read();
    if (ble_val == 'S')break; //receive ‘S’ to stop speeding up
  }
}

void speeds_d() { //Deceleration function
  matrix_display(speed_d);  //show the image of speeding down 
  while (1) {
    Serial.println(speeds);  //show the speed
    if (speeds > 0) { //reduce to 0
      speeds--;
      delay(10);    //adjust the speed 
    }
    ble_val = Serial.read();
    if (ble_val == 'S')break; //receive ‘S’ and stop accelaration
  }
}

//this function is used for the display of dot matrix 
void matrix_display(unsigned char matrix_value[])
{
  IIC_start();  //use the function to start transmitting data
  IIC_send(0xc0);  //select an address
  for (int i = 0; i < 16; i++) //image data have 16 characters
  {
    IIC_send(matrix_value[i]); //data to transmit pictures
  }
  IIC_end();   //end the data transmission of pictures
  IIC_start();
  IIC_send(0x8A);  //show control and select pulse width 4/16
  IIC_end();
}

//the condition that data starts transmitting
void IIC_start()
{
  digitalWrite(SDA_Pin, HIGH);
  digitalWrite(SCL_Pin, HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin, LOW);
  delayMicroseconds(3);
  digitalWrite(SCL_Pin, LOW);
}

//the sign that transmission of data ends
void IIC_end()
{
  digitalWrite(SCL_Pin, LOW);
  digitalWrite(SDA_Pin, LOW);
  delayMicroseconds(3);
  digitalWrite(SCL_Pin, HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin, HIGH);
  delayMicroseconds(3);
}

//transmit data
void IIC_send(unsigned char send_data)
{
  for (byte mask = 0x01; mask != 0; mask <<= 1) //ecah character has 8 digits, which is detected one by one
  {
    if (send_data & mask) { //set high or low levels in light of each bit(0 or 1)
      digitalWrite(SDA_Pin, HIGH);
    } else {
      digitalWrite(SDA_Pin, LOW);
    }
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, HIGH); //pull up the clock pin SCL_Pin to end the transmission of data
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, LOW); //pull down the clock pin SCL_Pin to change signals of SDA 
  }
}
