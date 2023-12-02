/*
  keyestudio Mini Tank Robot V3
  lesson 12.1
  Matrix face
  http://www.keyestudio.com
*/
//get the data of smile image from a modulus tool
unsigned char smile[] = {0x00, 0x00, 0x1c, 0x02, 0x02, 0x02, 0x5c, 0x40, 0x40, 0x5c, 0x02, 0x02, 0x02, 0x1c, 0x00, 0x00};

#define SCL_Pin  A5  //set a pin of clock to A5
#define SDA_Pin  A4  //set a data pin to A4

void setup() {
  //set the pin to OUTPUT
  pinMode(SCL_Pin, OUTPUT);
  pinMode(SDA_Pin, OUTPUT);
  //clear screen
  //matrix_display(clear);
}
void loop() {
  matrix_display(smile);  //display the smile image
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
    if (send_data & mask) { // set high or low levels in light of each bit(0 or 1)
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
