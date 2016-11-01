#include "CurieIMU.h"

int ax,ay,az;

void setup() {
  Serial.begin(9600);
  CurieIMU.begin();

}

void loop() {
  CurieIMU.readAccelerometer(ax,ay,az);
  Serial.print(ax);
  Serial.print("\t");
  Serial.print(ay);
  Serial.print("\t");
  Serial.print(az);
  Serial.println();
  delay(10);
}
