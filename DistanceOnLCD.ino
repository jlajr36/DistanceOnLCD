#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int TrigPin = 2;
int PulsePin = 3;

long dist = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  pinMode(TrigPin, OUTPUT);
  pinMode(PulsePin, INPUT);
}

void loop() {
  Trigger();
  dist = getDistance();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(dist);
  lcd.print(" cm");
  delay(10);
}

void Trigger() {
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(TrigPin, LOW);
}

long getDistance() {
  long temp = pulseIn(PulsePin, HIGH, 2000);
  temp = temp/29/2;
  return temp; 
}

