# Controlando-PWM-Serial

```cpp
int PWM_PIN = 3;
int pwmval = 0;

void setup() {
  Serial.begin(9600);
  pinMode(PWM_PIN,OUTPUT);
  Serial.println("Valor entre 1 a 255");
}

void loop() {
  if (Serial.available() > 1) {
      pwmval =  Serial.parseInt();
      Serial.print("Valor: ");
      Serial.println(pwmval);
      analogWrite(PWM_PIN, pwmval);
  }
}
```
