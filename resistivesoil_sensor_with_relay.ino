

int moistureSensor = 0;
int motor = 5;
int min = 300;
int max = 1000;
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 
void setup() {
  Serial.begin(9600);
  pinMode(motor,OUTPUT);
  
   lcd.clear();
   lcd.init();
   lcd.backlight(); 
}


void loop() {
 int SensorValue = analogRead(moistureSensor);
 float percentage = (float)((SensorValue - min) * 100) / (max - min);
  lcd.setCursor(0,0);

  if(SensorValue >=600)
  {
    
    digitalWrite(motor,LOW);
    lcd.print("Soil RH: Good");
    
  }
  else
  {
    digitalWrite(motor,HIGH);
    lcd.print("Watering...");
  }
}
