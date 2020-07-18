#include<dht11.h>      // Including library for dht
#include<LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

#define dht_dpin 12 

dht11 DHT;

byte degree[8] = 
              {
                0b00011,
                0b00011,
                0b00000,
                0b00000,
                0b00000,
                0b00000,
                0b00000,
                0b00000
              };

void setup()
{
 lcd.begin(16, 2);
 lcd.createChar(1, degree);
 lcd.clear();
 
 lcd.print("   Humidity   ");
 lcd.setCursor(0,1);
 lcd.print("  Measurement ");
 delay(2000);
 lcd.clear();
 lcd.print("Circuit Digest ");
 delay(2000);
}

void loop()
{
  DHT.read(dht_dpin);
  lcd.setCursor(0,1);
  lcd.print("H:");
  lcd.print(DHT.humidity);   // printing Humidity on LCD
  lcd.print(" %");
  lcd.setCursor(0,0);
  lcd.print("T:");
  lcd.print(((DHT.temperature)));   // Printing temperature on LCD
  lcd.write(1);
  lcd.print("C");
  delay(500);
}
