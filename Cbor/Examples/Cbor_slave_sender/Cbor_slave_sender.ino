/*
    Arduino Sketch to show how to send encoded CBOR package via I2c
    as slave requester. Load this sketch must in the second (slave)
    Arduino.

    Author: Juanjo Tara
    Email:  j.tara@arduino.cc
    Date:   24/04/2015

    Updated: Rich Morgan
    Email:   rich.l.morgan@gmail.com
    Date:    15/12/2023
*/

#include "CborEncoder.h"
#include <Wire.h>

void setup()
{
  Wire.begin(2);                // join i2c bus with address #2
  Wire.onRequest(requestEvent); // register event

  Serial.begin(9600);
}

void loop()
{
  // Intentionally empty.
}

// Function that executes whenever data is requested by master.
// This function is registered as an event, see setup()
void requestEvent()
{
  // get length and data of cbor package
  unsigned char *datapkg = output.getData();
  int datalength = output.getSize();

  Serial.print("datalength:");
  Serial.print(datalength);

  Wire.write(*datapkg); // respond with message
}
