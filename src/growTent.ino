#include <LiquidCrystal.h>
#include <dht.h>

dht DHT;
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

#define DHT11_PIN 7

void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.clear();
}

void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  lcd.print("%");
  delay(5000);
}
