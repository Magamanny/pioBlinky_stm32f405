#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  pinMode(PA12,OUTPUT);
  digitalWrite(PA12,LOW);
}

void loop() {
  digitalWrite(PA12,LOW);
  delay(250);
  digitalWrite(PA12,HIGH);
  delay(250);
  // put your main code here, to run repeatedly:
}