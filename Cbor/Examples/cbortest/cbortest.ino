/*
    Arduino Sketch to show how encode and decode CBOR package.

    Author: Juanjo Tara
    Email:  j.tara@arduino.cc
    Date:   24/04/2015

    Updated: Rich Morgan
    Email:   rich.l.morgan@gmail.com
    Date:    15/12/2023
*/

#include "CborEncoder.h"
#include "CborDecoder.h"

void setup()
{
  Serial.begin(9600);

  test1();
}

void loop()
{
  // Intentionally empty.
}

void test1()
{
  CborStaticOutput output(32);
  CborWriter writer(output);

  // Write a Cbor Package with a number and String
  writer.writeInt(124);
  writer.writeString("I");

  unsigned int sizeee = output.getSize();

  Serial.print("datalength:");
  Serial.println(sizeee);

  delay(1000);

  CborInput input(output.getData(), output.getSize());
  CborDebugListener listener;
  CborReader reader(input);

  reader.SetListener(listener);
  reader.Run();
}
