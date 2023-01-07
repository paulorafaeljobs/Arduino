#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Encoder.h>

LiquidCrystal_I2C lcd(0x3F,20,4); 
Encoder myEnc(6, 5);

void setup() {
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
}

void loop() {
    byte newPos = myEnc.read();
    lcd.setCursor(0,1);
    lcd.print(F("  ENCODER      "));
    lcd.print(newPos);
    lcd.print(F("   ")); 
}
