#include "CurieIMU.h"

int ax,ay,az;

void setup() {
  Serial.begin(9600);
  CurieIMU.begin();

  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  CurieIMU.readAccelerometer(ax,ay,az);
  Serial.print(ax);
  Serial.print("\t");
  Serial.print(ay);
  Serial.print("\t");
  Serial.print(az);
  Serial.println();
  
  if (az > 0) {
    //The board is facing up
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
  }
  if (az < 0) {
    //The board is facing down
    digitalWrite(9, LOW);
    digitalWrite(10,HIGH);
  }

  delay(10);
}
