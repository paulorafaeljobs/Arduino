#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>
#include <Encoder.h>
//LiquidCrystal_I2C lcd(0x27,20,4);
LiquidCrystal_I2C lcd(0x3F,20,4); 
Encoder myEnc(6, 5);

#define botao_MAIS   24                 
#define botao_MENOS  25      
#define botao_VOLTAR 22                  
#define botao_ENTER  23                 
#define botao_menu1 26                  
#define botao_menu2 27                 
const byte led13 = 13;
bool L_botao_MAIS,  LA_botao_MAIS,  L_botao_MENOS,  LA_botao_MENOS  = 1;               
bool L_botao_ENTER, LA_botao_ENTER, L_botao_VOLTAR, LA_botao_VOLTAR = 1;
int  tela = 1;
int  voltar = 4;
#define Mot1  3                
#define Mot2  4                 
#define Mot3  5                 
#define Mot4  6           
#define Mot5  7           
#define Mot6  8                 
#define Mot7  9           
#define Mot8  10           

#define Led1  31                
#define Led2  32                
#define Led3  33                
#define Led4  34          
#define Led5  35           
#define Led6  36                 
#define Led7  37          
#define Led8  38           

byte Motor1;
byte Motor2;
byte Motor3;
byte Motor4;
byte Motor5;
byte Motor6;
byte Motor7;
byte Motor8;
byte Statusled1 = 0;
byte Statusled2 = 0;
byte Statusled3 = 0;
byte Statusled4 = 0;
byte Statusled5 = 0;
byte Statusled6 = 0;
byte Statusled7 = 0;
byte Statusled8 = 0;
                                                                         
void setup(){
   Serial.begin(9600);
   pinMode(botao_MAIS,   INPUT_PULLUP);       
   pinMode(botao_MENOS,  INPUT_PULLUP);
   pinMode(botao_VOLTAR, INPUT_PULLUP);
   pinMode(botao_ENTER,  INPUT_PULLUP);
   pinMode(botao_menu1,  INPUT_PULLUP);
   pinMode(botao_menu2,  INPUT_PULLUP);
   pinMode(Mot1,  OUTPUT);
   pinMode(Mot2,  OUTPUT);
   pinMode(Mot3,  OUTPUT);
   pinMode(Mot4,  OUTPUT);
   pinMode(Mot5,  OUTPUT);
   pinMode(Mot6,  OUTPUT);
   pinMode(Mot7,  OUTPUT);
   pinMode(Mot8,  OUTPUT);
   pinMode(Led1,  OUTPUT);
   pinMode(Led2,  OUTPUT);
   pinMode(Led3,  OUTPUT);
   pinMode(Led4,  OUTPUT);
   pinMode(Led5,  OUTPUT);
   pinMode(Led6,  OUTPUT);
   pinMode(Led7,  OUTPUT);
   pinMode(Led8,  OUTPUT);
   lcd.begin(); 
   lcd.backlight();  
   //lcd.noBacklight();
   inicio();
// byte brilho = 0;
// EEPROM.write(brilho, 123);
// Serial.println(EEPROM.read(brilho));
}

void inicio(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PauloRafael");
  lcd.setCursor(0,1);
  lcd.print(" Sistema v1");
  delay(3000);
}

void loop() {     
  if (Serial.available() > 0){
    String recebido = leStringSerial();
    if (recebido == "led1:1"){Statusled1 = 1;};
    if (recebido == "led2:1"){Statusled2 = 1;};
    if (recebido == "led3:1"){Statusled3 = 1;};
    if (recebido == "led4:1"){Statusled4 = 1;};
    if (recebido == "led5:1"){Statusled5 = 1;};
    if (recebido == "led6:1"){Statusled6 = 1;};
    if (recebido == "led7:1"){Statusled7 = 1;};
    if (recebido == "led8:1"){Statusled8 = 1;};
    if (recebido == "led1:0"){Statusled1 = 0;};
    if (recebido == "led2:0"){Statusled2 = 0;};
    if (recebido == "led3:0"){Statusled3 = 0;};
    if (recebido == "led4:0"){Statusled4 = 0;};
    if (recebido == "led5:0"){Statusled5 = 0;};
    if (recebido == "led6:0"){Statusled6 = 0;};
    if (recebido == "led7:0"){Statusled7 = 0;};
    if (recebido == "led8:0"){Statusled8 = 0;};
  };
  
  if (tela==1){
    lcd.setCursor(0,0);lcd.print("> Motor             ");
    lcd.setCursor(0,1);lcd.print("  Led               ");
    lcd.setCursor(0,2);lcd.print("  Serial            ");
    lcd.setCursor(0,3);lcd.print("  Config            ");

  }else if (tela==2){
    lcd.setCursor(0,0);lcd.print("  Motor             ");
    lcd.setCursor(0,1);lcd.print("> Led               ");
    lcd.setCursor(0,2);lcd.print("  Serial            ");
    lcd.setCursor(0,3);lcd.print("  Config            ");

  }else if (tela==3){
    lcd.setCursor(0,0);lcd.print("  Motor             ");
    lcd.setCursor(0,1);lcd.print("  Led               ");
    lcd.setCursor(0,2);lcd.print("> Serial            ");
    lcd.setCursor(0,3);lcd.print("  Config            ");

  }else if (tela==4){
    lcd.setCursor(0,0);lcd.print("  Motor             ");
    lcd.setCursor(0,1);lcd.print("  Led               ");
    lcd.setCursor(0,2);lcd.print("  Serial            ");
    lcd.setCursor(0,3);lcd.print("> Config            ");

  }else if (tela==11){
    lcd.setCursor(0,0);lcd.print(F("> Motor 1      "));lcd.print(Motor1);lcd.print(F("   "));
    lcd.setCursor(0,1);lcd.print(F("  Motor 2      "));lcd.print(Motor2);lcd.print(F("   ")); 
    lcd.setCursor(0,2);lcd.print(F("  Motor 3      "));lcd.print(Motor3);lcd.print(F("   ")); 
    lcd.setCursor(0,3);lcd.print(F("  Motor 4      "));lcd.print(Motor4);lcd.print(F("   ")); 

  }else if (tela==12){
    lcd.setCursor(0,0);lcd.print(F("  Motor 1      "));lcd.print(Motor1);lcd.print(F("   ")); 
    lcd.setCursor(0,1);lcd.print(F("> Motor 2      "));lcd.print(Motor2);lcd.print(F("   ")); 
    lcd.setCursor(0,2);lcd.print(F("  Motor 3      "));lcd.print(Motor3);lcd.print(F("   ")); 
    lcd.setCursor(0,3);lcd.print(F("  Motor 4      "));lcd.print(Motor4);lcd.print(F("   ")); 

  }else if (tela==13){
    lcd.setCursor(0,0);lcd.print(F("  Motor 1      "));lcd.print(Motor1);lcd.print(F("   ")); 
    lcd.setCursor(0,1);lcd.print(F("  Motor 2      "));lcd.print(Motor2);lcd.print(F("   ")); 
    lcd.setCursor(0,2);lcd.print(F("> Motor 3      "));lcd.print(Motor3);lcd.print(F("   ")); 
    lcd.setCursor(0,3);lcd.print(F("  Motor 4      "));lcd.print(Motor4);lcd.print(F("   ")); 

  }else if (tela==14){
    lcd.setCursor(0,0);lcd.print(F("  Motor 1      "));lcd.print(Motor1);lcd.print(F("   ")); 
    lcd.setCursor(0,1);lcd.print(F("  Motor 2      "));lcd.print(Motor2);lcd.print(F("   ")); 
    lcd.setCursor(0,2);lcd.print(F("  Motor 3      "));lcd.print(Motor3);lcd.print(F("   ")); 
    lcd.setCursor(0,3);lcd.print(F("> Motor 4      "));lcd.print(Motor4);lcd.print(F("   ")); 

  }else if (tela==15){
    lcd.setCursor(0,0);lcd.print(F("> Motor 5      "));lcd.print(Motor5);lcd.print(F("   ")); 
    lcd.setCursor(0,1);lcd.print(F("  Motor 6      "));lcd.print(Motor6);lcd.print(F("   ")); 
    lcd.setCursor(0,2);lcd.print(F("  Motor 7      "));lcd.print(Motor7);lcd.print(F("   "));  
    lcd.setCursor(0,3);lcd.print(F("  Motor 8      "));lcd.print(Motor8);lcd.print(F("   ")); 

  }else if (tela==16){
    lcd.setCursor(0,0);lcd.print(F("  Motor 5      "));lcd.print(Motor5);lcd.print(F("   ")); 
    lcd.setCursor(0,1);lcd.print(F("> Motor 6      "));lcd.print(Motor6);lcd.print(F("   ")); 
    lcd.setCursor(0,2);lcd.print(F("  Motor 7      "));lcd.print(Motor7);lcd.print(F("   ")); 
    lcd.setCursor(0,3);lcd.print(F("  Motor 8      "));lcd.print(Motor8);lcd.print(F("   ")); 
 
  }else if (tela==17){
    lcd.setCursor(0,0);lcd.print(F("  Motor 5      "));lcd.print(Motor5);lcd.print(F("   ")); 
    lcd.setCursor(0,1);lcd.print(F("  Motor 6      "));lcd.print(Motor6);lcd.print(F("   ")); 
    lcd.setCursor(0,2);lcd.print(F("> Motor 7      "));lcd.print(Motor7);lcd.print(F("   ")); 
    lcd.setCursor(0,3);lcd.print(F("  Motor 8      "));lcd.print(Motor8);lcd.print(F("   ")); 

  }else if (tela==18){
    lcd.setCursor(0,0);lcd.print(F("  Motor 5      "));lcd.print(Motor5);lcd.print(F("   ")); 
    lcd.setCursor(0,1);lcd.print(F("  Motor 6      "));lcd.print(Motor6);lcd.print(F("   ")); 
    lcd.setCursor(0,2);lcd.print(F("  Motor 7      "));lcd.print(Motor7);lcd.print(F("   ")); 
    lcd.setCursor(0,3);lcd.print(F("> Motor 8      "));lcd.print(Motor8);lcd.print(F("   ")); 
    
  }else if (tela==21){
    lcd.setCursor(0,0);lcd.print(F("> Led 1        "));lcd.print(Statusled1);lcd.print(F("   "));
    lcd.setCursor(0,1);lcd.print(F("  Led 2        "));lcd.print(Statusled2);lcd.print(F("   ")); 
    lcd.setCursor(0,2);lcd.print(F("  Led 3        "));lcd.print(Statusled3);lcd.print(F("   ")); 
    lcd.setCursor(0,3);lcd.print(F("  Led 4        "));lcd.print(Statusled4);lcd.print(F("   ")); 

  }else if (tela==22){
    lcd.setCursor(0,0);lcd.print(F("  Led 1        "));lcd.print(Statusled1);lcd.print(F("   ")); 
    lcd.setCursor(0,1);lcd.print(F("> Led 2        "));lcd.print(Statusled2);lcd.print(F("   ")); 
    lcd.setCursor(0,2);lcd.print(F("  Led 3        "));lcd.print(Statusled3);lcd.print(F("   ")); 
    lcd.setCursor(0,3);lcd.print(F("  Led 4        "));lcd.print(Statusled4);lcd.print(F("   ")); 

  }else if (tela==23){
    lcd.setCursor(0,0);lcd.print(F("  Led 1        "));lcd.print(Statusled1);lcd.print(F("   ")); 
    lcd.setCursor(0,1);lcd.print(F("  Led 2        "));lcd.print(Statusled2);lcd.print(F("   ")); 
    lcd.setCursor(0,2);lcd.print(F("> Led 3        "));lcd.print(Statusled3);lcd.print(F("   ")); 
    lcd.setCursor(0,3);lcd.print(F("  Led 4        "));lcd.print(Statusled4);lcd.print(F("   ")); 

  }else if (tela==24){
    lcd.setCursor(0,0);lcd.print(F("  Led 1        "));lcd.print(Statusled1);lcd.print(F("   ")); 
    lcd.setCursor(0,1);lcd.print(F("  Led 2        "));lcd.print(Statusled2);lcd.print(F("   ")); 
    lcd.setCursor(0,2);lcd.print(F("  Led 3        "));lcd.print(Statusled3);lcd.print(F("   ")); 
    lcd.setCursor(0,3);lcd.print(F("> Led 4        "));lcd.print(Statusled4);lcd.print(F("   ")); 

  }else if (tela==25){
    lcd.setCursor(0,0);lcd.print(F("> Led 5        "));lcd.print(Statusled5);lcd.print(F("   ")); 
    lcd.setCursor(0,1);lcd.print(F("  Led 6        "));lcd.print(Statusled6);lcd.print(F("   ")); 
    lcd.setCursor(0,2);lcd.print(F("  Led 7        "));lcd.print(Statusled7);lcd.print(F("   "));  
    lcd.setCursor(0,3);lcd.print(F("  Led 8        "));lcd.print(Statusled8);lcd.print(F("   ")); 

  }else if (tela==26){
    lcd.setCursor(0,0);lcd.print(F("  Led 5        "));lcd.print(Statusled5);lcd.print(F("   ")); 
    lcd.setCursor(0,1);lcd.print(F("> Led 6        "));lcd.print(Statusled6);lcd.print(F("   ")); 
    lcd.setCursor(0,2);lcd.print(F("  Led 7        "));lcd.print(Statusled7);lcd.print(F("   ")); 
    lcd.setCursor(0,3);lcd.print(F("  Led 8        "));lcd.print(Statusled8);lcd.print(F("   ")); 
 
  }else if (tela==27){
    lcd.setCursor(0,0);lcd.print(F("  Led 5        "));lcd.print(Statusled5);lcd.print(F("   ")); 
    lcd.setCursor(0,1);lcd.print(F("  Led 6        "));lcd.print(Statusled6);lcd.print(F("   ")); 
    lcd.setCursor(0,2);lcd.print(F("> Led 7        "));lcd.print(Statusled7);lcd.print(F("   ")); 
    lcd.setCursor(0,3);lcd.print(F("  Led 8        "));lcd.print(Statusled8);lcd.print(F("   ")); 

  }else if (tela==28){
    lcd.setCursor(0,0);lcd.print(F("  Led 5        "));lcd.print(Statusled5);lcd.print(F("   ")); 
    lcd.setCursor(0,1);lcd.print(F("  Led 6        "));lcd.print(Statusled6);lcd.print(F("   ")); 
    lcd.setCursor(0,2);lcd.print(F("  Led 7        "));lcd.print(Statusled7);lcd.print(F("   ")); 
    lcd.setCursor(0,3);lcd.print(F("> Led 8        "));lcd.print(Statusled8);lcd.print(F("   ")); 
  
  }else if (tela==31){
    lcd.setCursor(0,0);lcd.print(F("Serial            "));
    lcd.setCursor(0,1);lcd.print(F("                  "));
    lcd.setCursor(0,2);lcd.print(F("                  "));
    lcd.setCursor(0,3);lcd.print(F("                  "));

  }else if (tela==41){
    lcd.setCursor(0,0);lcd.print(F("Config            "));
    lcd.setCursor(0,1);lcd.print(F("                  "));
    lcd.setCursor(0,2);lcd.print(F("                  "));
    lcd.setCursor(0,3);lcd.print(F("                  "));
  }
  
  
  analogWrite (Mot1, Motor1); 
  analogWrite (Mot2, Motor2); 
  analogWrite (Mot3, Motor3); 
  analogWrite (Mot4, Motor4); 
  analogWrite (Mot5, Motor5); 
  analogWrite (Mot6, Motor6); 
  analogWrite (Mot7, Motor7); 
  analogWrite (Mot8, Motor8); 
  if (Statusled1 == 1){digitalWrite(Led1, HIGH);}else{digitalWrite(Led1, LOW);}
  if (Statusled2 == 1){digitalWrite(Led2, HIGH);}else{digitalWrite(Led2, LOW);}
  if (Statusled3 == 1){digitalWrite(Led3, HIGH);}else{digitalWrite(Led3, LOW);}
  if (Statusled4 == 1){digitalWrite(Led4, HIGH);}else{digitalWrite(Led4, LOW);}
  if (Statusled5 == 1){digitalWrite(Led5, HIGH);}else{digitalWrite(Led5, LOW);}
  if (Statusled6 == 1){digitalWrite(Led6, HIGH);}else{digitalWrite(Led6, LOW);}
  if (Statusled7 == 1){digitalWrite(Led7, HIGH);}else{digitalWrite(Led7, LOW);}
  if (Statusled8 == 1){digitalWrite(Led8, HIGH);}else{digitalWrite(Led8, LOW);}
  if(digitalRead(botao_menu1) == 0){
    lcd.clear();tela=1;
  }
  if(digitalRead(botao_menu2) == 0){
    if(tela==1){tela=11;}
    if(tela==2){tela=21;}
    if(tela==3){tela=31;lcd.clear();}
    if(tela==4){tela=41;}
  }

  
  L_botao_MAIS = digitalRead(botao_MAIS);
  if (!L_botao_MAIS && LA_botao_MAIS) {
            if (tela==11){Motor1++;}
            if (tela==12){Motor2++;}
            if (tela==13){Motor3++;}
            if (tela==14){Motor4++;}
            if (tela==15){Motor5++;}
            if (tela==16){Motor6++;}
            if (tela==17){Motor7++;}
            if (tela==18){Motor8++;}
            if (tela==21){Statusled1 = 1;}
            if (tela==22){Statusled2 = 1;}
            if (tela==23){Statusled3 = 1;}
            if (tela==24){Statusled4 = 1;}
            if (tela==25){Statusled5 = 1;}
            if (tela==26){Statusled6 = 1;}
            if (tela==27){Statusled7 = 1;}
            if (tela==28){Statusled8 = 1;}
            if (tela==41){lcd.backlight();}
            delay(30);
  }
  LA_botao_MAIS = L_botao_MAIS ; 
  // === Ações do Botão MENOS === //   
  L_botao_MENOS = digitalRead(botao_MENOS);
  if (!L_botao_MENOS && LA_botao_MENOS) {
            if (tela==11){Motor1--;}
            if (tela==12){Motor2--;}
            if (tela==13){Motor3--;}
            if (tela==14){Motor4--;}                    
            if (tela==15){Motor5--;}                    
            if (tela==16){Motor6--;}  
            if (tela==17){Motor7--;}
            if (tela==18){Motor8--;}
            if (tela==21){Statusled1 = 0;}
            if (tela==22){Statusled2 = 0;}
            if (tela==23){Statusled3 = 0;}
            if (tela==24){Statusled4 = 0;}
            if (tela==25){Statusled5 = 0;}
            if (tela==26){Statusled6 = 0;}
            if (tela==27){Statusled7 = 0;}
            if (tela==28){Statusled8 = 0;}
            if (tela==41){lcd.noBacklight();}
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
       else if (tela==4){tela=3;}
            if (tela==11){}
       else if (tela==12){tela=11;}
       else if (tela==13){tela=12;}
       else if (tela==14){tela=13;}
       else if (tela==15){tela=14;}
       else if (tela==16){tela=15;}
       else if (tela==17){tela=16;}
       else if (tela==18){tela=17;}
            if (tela==21){}
       else if (tela==22){tela=21;}
       else if (tela==23){tela=22;}
       else if (tela==24){tela=23;}
       else if (tela==25){tela=24;}
       else if (tela==26){tela=25;}
       else if (tela==27){tela=26;}
       else if (tela==28){tela=27;}
       delay(30);
  }                           
  LA_botao_VOLTAR = L_botao_VOLTAR;
  
  
  // === Ações do Botão ENTER === // 
  L_botao_ENTER = digitalRead(botao_ENTER);
  if (!L_botao_ENTER && LA_botao_ENTER) {
            if (tela==1){voltar=tela; tela=2;}
       else if (tela==2){voltar=tela; tela=3;}
       else if (tela==3){voltar=tela; tela=4;}
       else if (tela==4){}
            if (tela==11){voltar=tela; tela=12;}
       else if (tela==12){voltar=tela; tela=13;}
       else if (tela==13){voltar=tela; tela=14;}
       else if (tela==14){voltar=tela; tela=15;}
       else if (tela==15){voltar=tela; tela=16;}
       else if (tela==16){voltar=tela; tela=17;}
       else if (tela==17){voltar=tela; tela=18;}
       else if (tela==18){}
          if (tela==21){voltar=tela; tela=22;}
       else if (tela==22){voltar=tela; tela=23;}
       else if (tela==23){voltar=tela; tela=24;}
       else if (tela==24){voltar=tela; tela=25;}
       else if (tela==25){voltar=tela; tela=26;}
       else if (tela==26){voltar=tela; tela=27;}
       else if (tela==27){voltar=tela; tela=28;}
       else if (tela==28){}
  
     }                           
  LA_botao_ENTER = L_botao_ENTER;
}
