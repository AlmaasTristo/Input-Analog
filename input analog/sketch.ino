

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C Rist(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  Rist.begin(16, 2);
  Rist.backlight();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int ITO = analogRead(A0);
  int pwm = map (ITO, 0, 1023, 0, 100);

  analogWrite(3, pwm);

  Rist.clear();
  Rist.setCursor(0, 0);
  Rist.print(pwm);
  Rist.print("%");

  delay(1000);
}
