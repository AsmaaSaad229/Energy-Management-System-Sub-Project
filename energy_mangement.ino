#include <LiquidCrystal.h>
LiquidCrystal lcd (2,3,4,5,6,7);

void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("measuring energy");
  delay(1000);
  lcd.clear();
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
}

void loop() {
  float voltage_cell =analogRead(A1) ;
  float volt= voltage_cell*5.0 / 1023.0;
  float volt_load = volt*2.0;
                                                                                                                                        
  int adcValue= analogRead(A0);
  double adcVoltage = (adcValue/1024.0)*5000;
  double currentValue = (adcVoltage-512)/100;

// Display voltage_cell on LCD
  lcd.setCursor(0,1);
  lcd.print("vol_cell:");
  lcd.print( volt_load , 2);
  lcd.print("V");

// Display current on LCD
  lcd.setCursor(0,0);
  lcd.print("current:");
  lcd.print( currentValue , 2);
  lcd.print("mA");
}
