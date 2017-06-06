#ifndef Converter_h
#define Converter_h

#include <Arduino.h>

class Converter
{
  public:
    Converter();    
    unsigned long long hexToDec(String hexString);  
    long binaryToDecimal(String value);
    long hexaToDecimal(String value);
    long octalToDecimal(String value);
    String hexToDecString(String hexString);
    String longLongToString(long long ll);
    String decimalToBinary(long value);
    String decimalToHexa(long value);
    String decimalToOctal(long value);
  private:
  	String fourBitsToHex(String value);
};

#endif
