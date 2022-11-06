```cpp
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

int bot1 = 22;
int bot2 = 24;
int bot3 = 26;
int bot4 = 28; // Menos
int bot5 = 30; // Mais

LiquidCrystal_I2C lcd(0x27,20,4);

void setup(){
  lcd.init();  
  lcd.begin (16,2);
  lcd.backlight();
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(bot1, INPUT_PULLUP);
  pinMode(bot2, INPUT_PULLUP);
  pinMode(bot3, INPUT_PULLUP);
  pinMode(bot4, INPUT_PULLUP);
  pinMode(bot5, INPUT_PULLUP);
  menu();
}

void menu(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Menu");
  lcd.setCursor(0,1);
  lcd.print("Tela");
  delay(500);
}

void menu1(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Tela + 1 ");
  lcd.setCursor(0,1);
  lcd.print("Tela - 1");
  delay(500);
  //menu();
}
void menu2(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Tela + 2 ");
  lcd.setCursor(0,1);
  lcd.print("Tela - 2");
  delay(500);
  //menu();
}

void loop(){
  if(digitalRead(bot1) == 0){
    menu2();
  }
  if(digitalRead(bot2) == 0){
    menu1();
  }
  if(digitalRead(bot3) == 0){
    menu();
  }
  if(digitalRead(bot4) == 0){
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  }
  if(digitalRead(bot5) == 0){
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  }
}
```
