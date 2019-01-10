#include "ros_mm.h"
#include <Adafruit_MotorShield.h>
#include <Adafruit_PWMServoDriver.h>

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

void setup() {
  setup_motor_driver();
  Serial.begin(9600);  
  Serial.println("Basic Encoder Test:");
  RightMotor->setSpeed(255);
  RightMotor->run(FORWARD);
}

void loop() {
  delay(3000);
  int count1 = Right_Encoder_Ticks;
  delay(1000);
  int count2 = Right_Encoder_Ticks;
  int diff = count1 - count2;
  int rpm = diff*60/330;
  
  
  #Serial.print("Left ");Serial.println(Left_Encoder_Ticks);
  Serial.print("Right rpm ");Serial.println(rpm);
  
  
}
