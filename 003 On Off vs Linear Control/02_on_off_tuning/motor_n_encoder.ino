 void setup_motor_driver(){
  AFMS.begin();

  setup_encoder();
  
  RightMotor->setSpeed(0);
  LeftMotor->setSpeed(0);
  RightMotor->run(FORWARD);
  RightMotor->run(RELEASE);
  LeftMotor->run(FORWARD);
  LeftMotor->run(RELEASE);
 }


void setup_encoder()
{
  // Quadrature encoders
  // Left encoder
  pinMode(Left_Encoder_PinA, INPUT_PULLUP);      // sets pin A as input  
  pinMode(Left_Encoder_PinB, INPUT_PULLUP);      // sets pin B as input
  digitalWrite(Left_Encoder_PinA, HIGH);                // turn on pullup resistor
  digitalWrite(Left_Encoder_PinB, HIGH);
  //Attaching interrupt in Left_Enc_PinA.
  attachInterrupt(digitalPinToInterrupt(Left_Encoder_PinA), do_Left_Encoder, RISING);
  

  // Right encoder
  pinMode(Right_Encoder_PinA, INPUT_PULLUP);      // sets pin A as input
  pinMode(Right_Encoder_PinB, INPUT_PULLUP);      // sets pin B as input
  digitalWrite(Right_Encoder_PinA, HIGH);                // turn on pullup resistor
  digitalWrite(Right_Encoder_PinB, HIGH);
  //Attaching interrupt in Right_Enc_PinA.
  attachInterrupt(digitalPinToInterrupt(Right_Encoder_PinA), do_Right_Encoder, RISING); 

}


//do_Left_Encoder() Definitions
void do_Left_Encoder()
{
   // Test transition; since the interrupt will only fire on 'rising' we don't need to read pin A
  LeftEncoderBSet = digitalRead(Left_Encoder_PinB);   // read the input pin
  Left_Encoder_Ticks -= LeftEncoderBSet ? -1 : +1;
   
}


//do_Right_Encoder() Definitions
void do_Right_Encoder()
{
  
  RightEncoderBSet = digitalRead(Right_Encoder_PinB);   // read the input pin
  Right_Encoder_Ticks += RightEncoderBSet ? -1 : +1; 
  
}
