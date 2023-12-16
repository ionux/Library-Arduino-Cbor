/*
    Arduino Sketch to show how Send Encode Cbor package via Serial port

    Author: Juanjo Tara
    Email:  j.tara@arduino.cc
    Date:   24/04/2015

    Updated: Rich Morgan
    Email:   rich.l.morgan@gmail.com
    Date:    15/12/2023
*/

#include "CborEncoder.h"

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  testSerialPort();
  delay(10000);
}

void testSerialPort()
{
  CborStaticOutput output(32);
  CborWriter writer(output);

  // Write a Cbor Package with a number and String
  writer.writeInt(124);
  writer.writeString("I");

  // get length and data of cbor package
  unsigned int datalength = output.getSize();
  unsigned char *datapkg = output.getData();

  // print in Serial port the Data length and Cbor in binary
  Serial.print(datalength);
  Serial.write(datapkg, datalength);
}
