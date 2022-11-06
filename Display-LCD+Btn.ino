```cpp
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

int bot1 = 22;
int bot2 = 24;

LiquidCrystal_I2C lcd(0x27,20,4);

void setup(){
  lcd.init();  
  lcd.begin (16,2);
  lcd.backlight();
  pinMode(bot1, INPUT_PULLUP);
  pinMode(bot2, INPUT_PULLUP);
}


void loop(){
  if(digitalRead(bot1) == 0){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Tela + 1 ");
    lcd.setCursor(0,1);
    lcd.print("Tela - 1");
    delay(500);
  }
  if(digitalRead(bot2) == 0){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Tela + 2");
    lcd.setCursor(0,1);
    lcd.print("Tela - 2");
    delay(500);
  }
}
```
