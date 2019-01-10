void setup_serial(){
  Serial.begin(9600);
  Messenger_Handler.attach(OnMsgCompleted);
}

void serial_println(int i){
  if( check == true && i > 0){
    for(int j=0;j<50;j++){
      Serial.println(i);
      i += 1;
      delay(50);
    }
  }
  check = false;
}

void read_from_serial(){
  while(Serial.available()>0){
    int data = Serial.read();
    Messenger_Handler.process(data);
  }
}
void OnMsgCompleted(){
  while( Messenger_Handler.available() ) {
    Messenger_Handler.copyString(str,MAXSIZE);
  }  
  toDec = atoi(str);
  serial_println(toDec);
  //serial_println(toDec);
}

