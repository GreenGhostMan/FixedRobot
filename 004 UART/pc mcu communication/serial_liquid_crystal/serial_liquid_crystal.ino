#include <Messenger.h>
#include <LiquidCrystal.h>
#define MAXSIZE 15   // Max String size
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Messenger Messenger_Handler = Messenger();
char str[MAXSIZE];
int toDec=-1;
bool check = true;

void setup() {  
  setup_crystal();
  setup_serial();
}

void loop() {
  read_from_serial();
  display_crystal();
    
}

