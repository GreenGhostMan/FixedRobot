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
int Error;
float Kp = 1.2;
int Speed;
int target = 1000;

void setup() {
  setup_motor_driver();
  setup_serial();
  
  RightMotor->run(FORWARD);
}
int timer_ = 0;

void loop() { 
  
  delay(9000);
  while(timer_<2000)
  {
    count_2 = Right_Encoder_Ticks;
    Error = target - count_2;
    
    
    if( Error > 0 )      {/* pwm and forward direction */
      Speed = Kp * Error; 
      if( Speed > 255) { Speed = 255;}
      RightMotor->setSpeed(Speed);
      RightMotor->run(FORWARD);
    }
    else if( Error < 0 )   {/* pwm and backward direction */
      Speed = -Kp * Error;
      if( Speed > 255) { Speed = 255;}
      RightMotor->setSpeed(Speed);
      RightMotor->run(BACKWARD);
    }
   else { /* stop the motor */RightMotor->run(RELEASE);}

    Serial.println(Right_Encoder_Ticks);
    delay(10); 
    timer_ += 10;
  }
  
  
  
  
}
