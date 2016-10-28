#include "CurieIMU.h"

int ax, ay, az;

void setup() {
  Serial.begin(9600);
    // Lower the serial timeout (from its default value of 1000 ms)
  // so that the call to Serial.parseInt() below doesn't pause for
  // too long and disrupt the sending of accelerometer data.
  Serial.setTimeout(2);

  CurieIMU.begin();

  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  CurieIMU.readAccelerometer(ax, ay, az);
  Serial.print(ax);
  Serial.print("\t");
  Serial.print(ay);
  Serial.print("\t");
  Serial.print(az);
  Serial.println();
  
   // Check for a valid prediction.
  int val = Serial.parseInt();
  if (val != 0) {
    // Turn off all the LEDs.
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);

    // Turn on the LED corresponding to the prediction.
    if (val == 1) digitalWrite(9, HIGH);
    if (val == 2) digitalWrite(10, HIGH);
    if (val == 3) digitalWrite(11, HIGH);
  }
}
