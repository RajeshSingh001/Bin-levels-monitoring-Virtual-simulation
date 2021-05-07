#include <LiquidCrystal.h>
LiquidCrystal BIN_DISPLAY(12, 11, 5, 4, 3, 2);
void setup()
{
  BIN_DISPLAY.begin(16, 2);
  Serial.begin(9600);
}
void loop()
{
  //Read the analog values
  int VAL1_level = analogRead(A0);
  int VAL2_level = analogRead(A1);
  int VAL3_level = analogRead(A2);
  int VAL4_level = analogRead(A3);
  //Mapping the analog values
  int FSR1 = map (VAL1_level, 1023, 0, 0, 100);
  int FSR2 = map (VAL2_level, 1023, 0, 0, 100);
  int FSR3 = map (VAL3_level, 1023, 0, 0, 100);
  int FSR4 = map (VAL4_level, 1023, 0, 0, 100);
  // print vaues on serial monitor
  Serial.print("FSR1:");
  Serial.print(FSR1);
  Serial.print("FSR2:");
  Serial.print(FSR2);
  Serial.print("FSR3:");
  Serial.print(FSR3);
  Serial.print("FSR4:");
  Serial.print(FSR4);
  // print vaues on lcd
  BIN_DISPLAY.setCursor(0, 0);
  BIN_DISPLAY.print(FSR1);
  BIN_DISPLAY.setCursor(5, 0);
  BIN_DISPLAY.print(FSR2);
  BIN_DISPLAY.setCursor(9, 0);
  BIN_DISPLAY.print(FSR3);
  BIN_DISPLAY.setCursor(0, 1);
  BIN_DISPLAY.print(FSR4);
  delay(1000);
}
