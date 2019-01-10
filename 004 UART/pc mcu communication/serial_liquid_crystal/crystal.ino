void setup_crystal(){
  lcd.begin(16, 2);
  lcd.print("PID Tunning!");
  //lcd.setCursor(0,1);
}

void display_crystal(){
  lcd.setCursor(0,1);  
  lcd.write(str);  
}

