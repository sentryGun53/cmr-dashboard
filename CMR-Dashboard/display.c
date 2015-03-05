/*
 * display.c
 *
 * Created: 3/4/2015 11:00:39 PM
 *  Author: Robert
 */ 


#include "spi.h"

/*
 Seven segment ordering
 /-a-\
 f   b
 |-g-|
 e   c
 \-d-/
*/

char getDigit(uint8_t digit) {
  switch (digit) {
    case 0: return 0b01111110;
    case 1: return 0b00110000;
    case 2: return 0b01101101;
    case 3: return 0b01111001;
    case 4: return 0b00110011;
    case 5: return 0b01011011;
    case 6: return 0b01011111;
    case 7: return 0b01110000;
    case 8: return 0b01111111;
    case 9: return 0b01111011;
    default: return 0b00000000;
  }
}

char thirdOut(char digit, char rgb) {
  char final = 0b0;
  //         (dp)abcdefg             rgb
  if ((digit & 0b00000100) && (rgb & 0b010)) final |= 0b1;
  if ((digit & 0b00001000) && (rgb & 0b001)) final |= 0b10;
  if ((digit & 0b00001000) && (rgb & 0b010)) final |= 0b100;
  if ((digit & 0b00001000) && (rgb & 0b100)) final |= 0b1000;
  if ((digit & 0b00010000) && (rgb & 0b001)) final |= 0b10000;
  if ((digit & 0b00010000) && (rgb & 0b100)) final |= 0b100000;
  if ((digit & 0b10000000) && (rgb & 0b010)) final |= 0b1000000;
  if ((digit & 0b10000000) && (rgb & 0b100)) final |= 0b10000000;
  return final;
}

char secondOut(char digit, char rgb) {
  char final = 0b0;
  //         (dp)abcdefg             rgb
  if ((digit & 0b00000100) && (rgb & 0b001)) final |= 0b1;
  if ((digit & 0b00000100) && (rgb & 0b100)) final |= 0b10;
  if ((digit & 0b00010000) && (rgb & 0b010)) final |= 0b100;
  if ((digit & 0b10000000) && (rgb & 0b001)) final |= 0b1000;
  if ((digit & 0b00000010) && (rgb & 0b010)) final |= 0b10000;
  if ((digit & 0b00000010) && (rgb & 0b100)) final |= 0b100000;
  if ((digit & 0b00000001) && (rgb & 0b010)) final |= 0b1000000;
  if ((digit & 0b00100000) && (rgb & 0b010)) final |= 0b10000000;
  return final;
}

char firstOut(char digit, char rgb) {
  char final = 0b0;
  //         (dp)abcdefg             rgb
  if ((digit & 0b00000010) && (rgb & 0b001)) final |= 0b1;
  if ((digit & 0b00000001) && (rgb & 0b001)) final |= 0b10;
  if ((digit & 0b00000001) && (rgb & 0b100)) final |= 0b100;
  if ((digit & 0b01000000) && (rgb & 0b001)) final |= 0b1000;
  if ((digit & 0b01000000) && (rgb & 0b010)) final |= 0b10000;
  if ((digit & 0b01000000) && (rgb & 0b100)) final |= 0b100000;
  if ((digit & 0b00100000) && (rgb & 0b001)) final |= 0b1000000;
  if ((digit & 0b00100000) && (rgb & 0b100)) final |= 0b10000000;
  return final;
}


void writeDigit(char dig, char rgb) {
  char digit = getDigit(dig);
  char first = firstOut(digit, rgb);
  char second = secondOut(digit, rgb);
  char third = thirdOut(digit, rgb);
  //shift first
  spi_send(first);
  //shift second
  spi_send(second);
  //shift third
  spi_send(third);
}
