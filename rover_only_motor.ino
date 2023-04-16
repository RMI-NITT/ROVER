

#include <MPU6050_tockn.h>
#include <Wire.h>
#include <Servo.h>

Servo myservo1;  // create servo object to control a servo
Servo myservo2;
Servo myservo3;
Servo myservo4;
MPU6050 mpu6050(Wire);
int state = 0;
// char msg;
// SoftwareSerial bt(0,1); /* (Rx,Tx) */	

#define m1f_a 5
#define m1f_b 4
#define m2f_a 3
#define m2f_b 2
#define m1m_a 13
#define m1m_b 12
#define m2m_a 11
#define m2m_b 10
#define m1b_a 7
#define m1b_b 6
#define m2b_a 8
#define m2b_b 9



int s = 80; // rover speed
int s1 = 50;


void setup() {

  
  pinMode(m1f_a, OUTPUT);
  pinMode(m1f_b, OUTPUT);
  pinMode(m2f_a, OUTPUT);
  pinMode(m2f_b, OUTPUT);
  pinMode(m1m_a, OUTPUT);
  pinMode(m1m_b, OUTPUT);
  pinMode(m2m_a, OUTPUT);
  pinMode(m2m_b, OUTPUT);
  pinMode(m1b_a, OUTPUT);
  pinMode(m1b_b, OUTPUT);
  pinMode(m2b_a, OUTPUT);
  pinMode(m2b_b, OUTPUT);
  myservo1.attach(52);
  myservo2.attach(53);
  myservo3.attach(50);
  myservo4.attach(51);
  pinMode(24,OUTPUT);
  digitalWrite(24,HIGH);
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  // bt.begin(9600);	/* Define baud rate for software serial communication */
 

  // while (!Serial);
  // Serial.println(" Receiver")


}

void loop() {
  ////////////////////////////// RECIEVER SECTION /////////////////////////////////////////////////////////////////////////////
  // try to parse packet
 if (Serial.available() > 0) { // Checks whether data is coming from the serial port
    state = Serial.read();
    Serial.println(state); // Reads the data from the serial port
  
     if(state=='F')
     {
      myservo1.write(90);
      myservo2.write(90);
      myservo3.write(90);
      myservo4.write(90);      
      analogWrite(m1f_a,0);
      analogWrite(m1f_b,s); 
      analogWrite(m2f_a,0);
      analogWrite(m2f_b,s);   
      analogWrite(m1m_a,0);
      analogWrite(m1m_b,s); 
      analogWrite(m2m_a,0);
      analogWrite(m2m_b,s);  
      analogWrite(m1b_a,s);
      analogWrite(m1b_b,0); 
      analogWrite(m2b_a,s);
      analogWrite(m2b_b,0);  
      
     }
  if(state=='B')
    {
    myservo1.write(90);
    myservo2.write(90);
    myservo3.write(90);
    myservo4.write(90);   
    analogWrite(m1f_a,s);
    analogWrite(m1f_b,0); 
    analogWrite(m2f_a,s);
    analogWrite(m2f_b,0);   
    analogWrite(m1m_a,s);
    analogWrite(m1m_b,0); 
    analogWrite(m2m_a,s);
    analogWrite(m2m_b,0);  
    analogWrite(m1b_a,0);
    analogWrite(m1b_b,s); 
    analogWrite(m2b_a,0);
    analogWrite(m2b_b,s);  

    }
    if(state=='s'){
    myservo1.write(90);
    myservo2.write(90);
    myservo3.write(90);
    myservo4.write(90);
    analogWrite(m1f_a,0);
    analogWrite(m1f_b,0); 
    analogWrite(m2f_a,0);
    analogWrite(m2f_b,0);   
    analogWrite(m1m_a,0);
    analogWrite(m1m_b,0); 
    analogWrite(m2m_a,0);
    analogWrite(m2m_b,0);  
    analogWrite(m1b_a,0);
    analogWrite(m1b_b,0); 
    analogWrite(m2b_a,0);
    analogWrite(m2b_b,0); 

    }
    if(state=='R')
    {
      analogWrite(m1f_a,0);
      analogWrite(m1f_b,s1); 
      analogWrite(m2f_a,0);
      analogWrite(m2f_b,s1);   
      analogWrite(m1m_a,0);
      analogWrite(m1m_b,s1); 
      analogWrite(m2m_a,0);
      analogWrite(m2m_b,s1);  
      analogWrite(m1b_a,s1);
      analogWrite(m1b_b,0); 
      analogWrite(m2b_a,s1);
      analogWrite(m2b_b,0);
      myservo1.write(60);
      myservo2.write(70);
      myservo3.write(120);
      myservo4.write(110);

    }

    if(state == 'L')
    {
         analogWrite(m1f_a,0);
      analogWrite(m1f_b,s1); 
      analogWrite(m2f_a,0);
      analogWrite(m2f_b,s1);   
      analogWrite(m1m_a,0);
      analogWrite(m1m_b,s1); 
      analogWrite(m2m_a,0);
      analogWrite(m2m_b,s1);  
      analogWrite(m1b_a,s1);
      analogWrite(m1b_b,0); 
      analogWrite(m2b_a,s1);
      analogWrite(m2b_b,0);
      myservo1.write(120);
      myservo2.write(110);
      myservo3.write(60);
      myservo4.write(70);
    }

  }
    mpu6050.update();
  Serial.print("angleX : ");
  Serial.print(mpu6050.getAngleX());
  Serial.print("\tangleY : ");
  Serial.print(mpu6050.getAngleY());
  Serial.print("\tangleZ : ");
  Serial.println(mpu6050.getAngleZ());
  delay(500);
}
