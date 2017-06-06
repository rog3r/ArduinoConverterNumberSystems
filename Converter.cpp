#include <Arduino.h>
#include "Converter.h"

Converter::Converter(){}

/**
  1: Convert the hexadecimal string into unsigned long long value
  Reference: https://www.arduino.cc/en/Reference/StringCharAt
*/
unsigned long long Converter::hexToDec(String hexString) {
  unsigned long long decValue = 0;
  int nextInt;
  for (int i = 0; i < hexString.length(); i++) {
    nextInt = int(hexString.charAt(i));
    if (nextInt >= 48 && nextInt <= 57) nextInt = map(nextInt, 48, 57, 0, 9);
    if (nextInt >= 65 && nextInt <= 70) nextInt = map(nextInt, 65, 70, 10, 15);
    if (nextInt >= 97 && nextInt <= 102) nextInt = map(nextInt, 97, 102, 10, 15);
    nextInt = constrain(nextInt, 0, 15);
    decValue = (decValue * 16) + nextInt;
  }
  return decValue;
}

/**
  1: Convert the string into char array
  2: Use char array with cpp strtol and base
  Reference: http://www.cplusplus.com/reference/cstdlib/strtol/
*/
long Converter::binaryToDecimal(String value){
    int base = 2; 
    int length = value.length() +1;
    char valueAsArray[length];
    value.toCharArray(valueAsArray, length);
    
    return strtol(valueAsArray, NULL, base);
}

/**
  1: Convert the string into char array
  2: Use char array with cpp strtol and base
  Reference: http://www.cplusplus.com/reference/cstdlib/strtol/
*/
long Converter::hexaToDecimal(String value){
    int base = 16;
    int length = value.length() +1;
    char valueAsArray[length];
    value.toCharArray(valueAsArray, length);
    return strtol(valueAsArray, NULL, base);
}

/**
  1: Convert the string into char array
  2: Use char array with cpp strtol and base
  Reference: http://www.cplusplus.com/reference/cstdlib/strtol/
*/
long Converter::octalToDecimal(String value){
    int base = 8;
    int length = value.length() +1;
    char valueAsArray[length];
    value.toCharArray(valueAsArray, length);
    return strtol(valueAsArray, NULL, base);
}

/**
  1: Convert the hexadecimal string into printable decimal string value
  Reference: https://www.arduino.cc/en/Reference/StringCharAt
*/
String Converter::hexToDecString(String hexString) {
  unsigned long long decValue = 0;
  String ret = "";
  int nextInt;
  for (int i = 0; i < hexString.length(); i++) {
    nextInt = int(hexString.charAt(i));
    if (nextInt >= 48 && nextInt <= 57) nextInt = map(nextInt, 48, 57, 0, 9);
    if (nextInt >= 65 && nextInt <= 70) nextInt = map(nextInt, 65, 70, 10, 15);
    if (nextInt >= 97 && nextInt <= 102) nextInt = map(nextInt, 97, 102, 10, 15);
    nextInt = constrain(nextInt, 0, 15);
    decValue = (decValue * 16) + nextInt;
  }

  uint64_t xx = decValue / 1000000000ULL;
  if (xx > 0) {
    ret += (long)xx;
  }
  ret += (long)(decValue - xx * 1000000000);
  return ret;
}


/**
  1: Convert the long long value into string value
  Reference:  
*/
String Converter::longLongToString(long long ll) {
  String ret = "";
  uint64_t xx = ll / 1000000000ULL;
  if (xx > 0) {
    ret += (long)xx;
  }
  ret += (long)(ll - xx * 1000000000);
  return ret;
}

/**
  Using the divide by 2 and remainder method to create a binary string
  Reference: http://www.wikihow.com/Convert-from-Decimal-to-Binary
*/
String Converter::decimalToBinary(long value){
  String result = "";
  if(value == 0){
    return "0";
  }else{
    while(value > 0){
      if((value % 2) == 0){
        result = "0" + result;
      }else{
        result = "1" + result;
      }
      value /= 2;
    }
  }
  return result;
}


/**
  1: Convert the decimal value into a binary String
  2: Each 4 bit pattern is translated into hexadecimal
  Reference: http://www.rapidtables.com/convert/number/how-binary-to-hex.htm
*/
String Converter::decimalToHexa(long value){
  String valueAsBinary = decimalToBinary(value);
  String valueAsHexa = "";
  String tmp = "";

  // Loop over the binary list from right to left
  for(int i = valueAsBinary.length() ; i > 0; i--){
    if(tmp.length() == 4){
      valueAsHexa = fourBitsToHex(tmp) + valueAsHexa;
      tmp = "";
    }
    tmp = valueAsBinary.substring(i, i-1) + tmp;
  }

  valueAsHexa = fourBitsToHex(tmp) + valueAsHexa;
  return valueAsHexa;
}

/**
  1: Convert the decimal value into a binary String
  2: Each 3 bit pattern is translated into octal
  Reference: http://www.wikihow.com/Convert-Binary-to-Octal-Number
*/
String Converter::decimalToOctal(long value){
  String valueAsBinary = decimalToBinary(value);
  String valueAsOctal = "";
  String tmp = "";

  // Loop over the binary list from right to left
  for(int i = valueAsBinary.length() ; i > 0; i--){
    if(tmp.length() == 3){
      valueAsOctal = String(binaryToDecimal(tmp)) + valueAsOctal;
      tmp = "";
    }
    tmp = valueAsBinary.substring(i, i-1) + tmp;
  }

  valueAsOctal = String(binaryToDecimal(tmp)) + valueAsOctal;
  return valueAsOctal;

}

/**
  This method will translate a 4 bit binary value into the correct hexadecimal didgit
*/
String Converter::fourBitsToHex(String value){
  int decValue = binaryToDecimal(value);
  switch(decValue){
    case 10:
      return "A";
    break;
    case 11:
      return "B";
    break;
    case 12:
      return "C";
    break;
    case 13:
      return "D";
    break;
    case 14:
      return "E";
    break;
    case 15:
      return "F";
    break;
    default:
      return String(decValue);
    break;
  }
}
