# Ligando Led pela Serial

```cpp
const byte led = 13;

char letter;
boolean control = 0;
boolean state = 0;

void setup() {
  Serial.begin(9600); // incia a comunicação serial
  pinMode(led, OUTPUT);
  Serial.println("Digite: ");
  Serial.println("A para ligar e Desligar");
}

void loop() {
  if (Serial.available()) {
    letter = Serial.read();
    control = 0;
    Serial.print("Char recebido: ");
    Serial.println(letter);    
  } 

  if (letter == 'A' && control == 0) {
    state = !state;
    digitalWrite(led, state);
    control = 1;
  }
  
} 
```
