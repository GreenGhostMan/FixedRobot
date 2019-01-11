#include "ros_mm.h"
#include <Wire.h>
#include <Adafruit_MotorShield.h>

/* ----------------------------ADAFRUIT MOTOR SHIELD------------------- */
// Create the motor shield object with the default I2C address
// Select which 'port' M1, M2, M3 or M4. 

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *RightMotor = AFMS.getMotor(1);
Adafruit_DCMotor *LeftMotor = AFMS.getMotor(3);
/*----------------------------------------------------------------------*/

// Left encoder
#define Left_Encoder_PinA 3
#define Left_Encoder_PinB 8
volatile long Left_Encoder_Ticks = 0;
volatile bool LeftEncoderBSet;

//Right Encoder
#define Right_Encoder_PinA 2
#define Right_Encoder_PinB 7
volatile long Right_Encoder_Ticks = 0;
volatile bool RightEncoderBSet;
/*-----------------------------------------------------------------------*/
//int count_1;
int count_1 = Right_Encoder_Ticks;
int count_2;
int diff;
int target1 = 165;
int target2 = 330;

void setup() {
  setup_motor_driver();
  Serial.begin(9600);  
  Serial.println("ppr");
  
  RightMotor->run(FORWARD);
  Serial.println(Right_Encoder_Ticks);
}

void loop() { 
  
  int timer_ = 0;
  while(timer_<5000)
  {
    RightMotor->setSpeed(30);
    count_2 = Right_Encoder_Ticks;
    diff = count_2 - count_1;
    if( diff<target2-5 )      {/* pwm and forward direction */ RightMotor->run(FORWARD);}
    else if ( diff>target2+5 )   {/* pwm and backward direction */RightMotor->run(BACKWARD);}
    else                       { /* stop the motor */RightMotor->run(RELEASE);}
    
    delay(10);
    Serial.println(diff);
    timer_ += 10;
  }
  Serial.println(diff);
  
  
  
  
  
}
