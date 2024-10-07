#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
uint8_t BUTT1 = 2;
uint8_t NUM = 0;
uint8_t BUTT2 = 3;
uint32_t R1;
uint32_t R2;
uint8_t TIME1 = 0;
uint8_t TIME2 = 0;
uint8_t i;
uint32_t k;
uint32_t e;
void setup() {
  pinMode(BUTT1, INPUT_PULLUP);
  pinMode(BUTT2, INPUT_PULLUP);
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
}
void loop() {

  if (digitalRead(BUTT1)){R1 = millis();}
  if((millis() - R1) >= 1000){
      NUM += 10;
      R1 = millis();
      k = millis();}
  else if(TIME1  > millis() - R1 + 10 and millis() - k > 1000){NUM += 1;}

  TIME1 = millis() - R1;


  if (digitalRead(BUTT2)){R2 = millis();}
  if(millis() - R2 >= 1000){
      NUM -= 10;
      R2 = millis();
      e = millis();}
  else if(TIME2  > millis() - R2 + 10 and millis() - e > 1000){NUM -= 1;}

  TIME2 = millis() - R2;
  
  if(NUM >= 10 and NUM < 100){i = 1;} 
  else if (NUM >= 100){i = 2;}
  else{i = 0;}

  lcd.clear();
  lcd.setCursor(8-i,0);
  lcd.print(NUM);
  lcd.setCursor(0,1);
  lcd.print(NUM);
  lcd.setCursor(15-i,1);
  lcd.print(NUM);
}
