#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define POT_PIN A0  // Potentiometer connected to analog pin A0

LiquidCrystal_I2C lcd(0x27, 16, 2);  // LCD I2C address

void setup() {
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Temperature:");
}

void loop() {
  int sensorValue = analogRead(POT_PIN);  // Read potentiometer value
  float voltage = sensorValue * (5.0 / 1023.0);  // Convert the value to voltage
  float temperatureC = voltage * 100.0;  // Convert the voltage to temperature in Celsius

  lcd.setCursor(0, 1);  
  lcd.print(temperatureC);  // Display temperature
  lcd.print(" C");
  
  delay(1000);  // Update every 1 second
}
