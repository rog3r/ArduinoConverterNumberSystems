#include <SoftwareSerial.h>
#include <Converter.h>
Converter conversorLib;

void setup() {
  Serial.begin(9600);  // start serial to PC
}

//Hexadecimal:  26005098E1
//Decimal:    163214039265
//Hexadecimal:  45001B031C
//Decimal :   296354513692

void convertValues() {
  String tagHex1 = "26005098E1";
  Serial.println("Hexadecimal: " + tagHex1);
  Serial.print("Decimal: ");
  Serial.println(conversorLib.hexToDecString(tagHex1));
  Serial.println("----------------------------------");

  String tagHex2 = "45001B031C";
  Serial.println("Hexadecimal: " + tagHex2);
  Serial.print("Decimal: ");
  Serial.println(conversorLib.hexToDecString(tagHex2));
  Serial.println("----------------------------------");
}

void loop() {
  convertValues();
  delay(1000);
}
