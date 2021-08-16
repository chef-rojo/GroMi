//DHT-11 sensor board to UNO R3 with LCD Display and relay
//added conversion from Celcius to Farenheit to read-out, may keep Celcius for back-end equations
//if statement controls dehumidifier, will add additional relays/humidifier/exhaust-fan/ac controls later

int motor = 5;
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <dht11.h>
#define DHT11PIN 4 
               
dht11 DHT11;            
 
LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup() {
  Serial.begin(9600);
  
  pinMode(motor,OUTPUT);
  
   lcd.clear();
   lcd.init();
   lcd.backlight(); 
}


void loop() {
  Serial.println();
  
  int chk = DHT11.read(DHT11PIN);
  
  lcd.setCursor(0,0);
  lcd.print("Humidity: ");
  lcd.println((float)DHT11.humidity, 2);

  lcd.setCursor(0,1);
  lcd.print("Temp (F): ");
  lcd.println((float)(DHT11.temperature*1.8)+32, 2);

  delay(2000);

  if(DHT11.humidity >= 62)
  {
    
    digitalWrite(motor,LOW);
    
  }
  else
  {
    digitalWrite(motor,HIGH);
  }
}
