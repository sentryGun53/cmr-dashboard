/*
 * display.h
 *
 * Created: 3/4/2015 11:48:10 PM
 *  Author: Robert
 */ 


#ifndef DISPLAY_H_
#define DISPLAY_H_


char getDigit(uint8_t digit);

char thirdOut(char digit, char rgb);
char secondOut(char digit, char rgb);
char firstOut(char digit, char rgb);

void writeDigit(char dig, char rgb);


#endif /* DISPLAY_H_ */