```cpp
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);
           
#define led1         3                
#define led2         4                 
#define led3         5                 

char dado = 0;

#define botao_MAIS   30                 
#define botao_MENOS  28      
           
#define botao_VOLTAR 22                  
#define botao_ENTER  24                  

bool L_botao_MAIS,  LA_botao_MAIS,  L_botao_MENOS,  LA_botao_MENOS  = 1;               
bool L_botao_ENTER, LA_botao_ENTER, L_botao_VOLTAR, LA_botao_VOLTAR = 1;
int  tela = 1;
int  voltar = 4;
byte brilho1;
byte brilho2;
byte brilho3;
                                                                         
void setup() {
   Serial.begin(9600);
   pinMode(botao_MAIS,   INPUT_PULLUP);       
   pinMode(botao_MENOS,  INPUT_PULLUP);
   pinMode(botao_VOLTAR, INPUT_PULLUP);
   pinMode(botao_ENTER,  INPUT_PULLUP);
   pinMode(led1,  OUTPUT);
   pinMode(led2,  OUTPUT);
   pinMode(led3,  OUTPUT);
   lcd.begin(16,2); 
   lcd.init(); 
   lcd.backlight();  
// inicio();
   pinMode(LED_BUILTIN, OUTPUT);
}

void inicio(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Sistema");
  lcd.setCursor(0,1);
  lcd.print("  v2");
  delay(3000);
}

void loop() {
  if(Serial.available() > 0){
    dado = Serial.read();
    brilho1 = dado;
    Serial.println(brilho1);
  }
  
  if (tela==1){
    lcd.setCursor(0,0);                   
    lcd.print(F("> Motor 1    "));
    lcd.print(brilho1);
    lcd.print(F("     ")); 
    lcd.setCursor(0,1);   
    lcd.print(F("  Motor 2    "));
    lcd.print(brilho2);
    lcd.print(F("     ")); 
  }else if (tela==2){
    lcd.setCursor(0,0);                   
    lcd.print(F("  Motor 1    "));
    lcd.print(brilho1);
    lcd.print(F("     ")); 
    lcd.setCursor(0,1);   
    lcd.print(F("> Motor 2    "));
    lcd.print(brilho2);
    lcd.print(F("     ")); 
  }else if (tela==3){
    lcd.setCursor(0,0);                   
    lcd.print(F("> Motor 3    "));
    lcd.print(brilho3);
    lcd.print(F("     ")); 
    lcd.setCursor(0,1);   
    lcd.print(F("  Motor 4 "));
    lcd.print("0");
    lcd.print(F("     ")); 
  }   
  analogWrite (led1, brilho1); 
  analogWrite (led2, brilho2); 
  analogWrite (led3, brilho3); 
  L_botao_MAIS = digitalRead(botao_MAIS);
  if (!L_botao_MAIS && LA_botao_MAIS) {
            if (tela==1)brilho1++;
            if (tela==2)brilho2++;
            if (tela==3)brilho3++;
       delay(30);
   }
   LA_botao_MAIS = L_botao_MAIS ; 
  // === Ações do Botão MENOS === //   
  L_botao_MENOS = digitalRead(botao_MENOS);
  if (!L_botao_MENOS && LA_botao_MENOS) {
            if (tela==1)brilho1--;
            if (tela==2)brilho2--;
            if (tela==3)brilho3--;
       delay(30);
  }                                      
  LA_botao_MENOS = L_botao_MENOS;
  // === Ações do Botão VOLTAR === // 
  L_botao_VOLTAR = digitalRead(botao_VOLTAR);
  if (!L_botao_VOLTAR && LA_botao_VOLTAR) {
       //tela=voltar;
            if (tela==1){}
       else if (tela==2){tela=1;}
       else if (tela==3){tela=2;}
       delay(30);
  }                           
  LA_botao_VOLTAR = L_botao_VOLTAR;
  // === Ações do Botão ENTER === // 
  L_botao_ENTER = digitalRead(botao_ENTER);
  if (!L_botao_ENTER && LA_botao_ENTER) {
            if (tela==1){voltar=tela; tela=2;}
       else if (tela==2){voltar=tela; tela=3;}
       else if (tela==3){voltar=tela;}
       delay(30);
       }                           
  LA_botao_ENTER = L_botao_ENTER;
}
void teste(){
    if (tela==1){
    lcd.setCursor(0,0);                   
    lcd.print(F(" Motor 1        "));      
    lcd.setCursor(0,1);                    
    lcd.print(F("     "));
    lcd.print(brilho1);
    lcd.print(F("     ")); 
  }else if (tela==2){
    lcd.setCursor(0,0);                   
    lcd.print(F(" Motor 2"));   
    lcd.setCursor(0,1);                    
    lcd.print(F("     "));
    lcd.print(brilho2);
    lcd.print(F("     ")); 
  }else if (tela==3){
    lcd.setCursor(0,0);                   
    lcd.print(F(" Motor 3"));   
    lcd.setCursor(0,1);                    
    lcd.print(F("     "));
    lcd.print(brilho3);
    lcd.print(F("     ")); 
  }   
}
```
