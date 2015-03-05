/*
 * dashboard_dio.c
 *
 * Created: 3/4/2015 8:42:27 PM
 *  Author: Robert
 */ 

#include <avr/io.h>
#include "standard_dio.h"

void set_DDRs() {
	/* data direction registers (input or output)
	 * these are specific to the dashboard PCB     */
	DDRB = 0b10111010;
	DDRC = 0b01001010;
	DDRD = 0b00000000;
	
	/* initialize all ports to zero */	
	PORTB = 0x00;
	PORTC = 0x00;
	PORTD = 0x00;
}

int LVE_btn_pressed() {
	return is_high(PIND, PIND7);
}

int HVE_btn_pressed() {
	return is_high(PINC, PINC5);
}

int RTD_btn_pressed() {
	return is_high(PINC, PINC0);
}

int DAQ_btn_pressed() {
	return is_high(PIND, PIND1);
}

int mode_btn_pressed() {
	return is_high(PINB, PINB0);
}

int left_disp_btn_pressed() {
	return is_high(PINC, PINC7);
}

int center_disp_btn_pressed() {
	return is_high(PINB, PINB6);
}

int right_disp_btn_pressed() {
	return is_high(PIND, PIND0);
}

int set_LVE_LED(int state) {
	if (state) {
		sbi()
	}
}