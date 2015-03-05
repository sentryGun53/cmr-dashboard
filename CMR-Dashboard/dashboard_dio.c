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

uint8_t LVE_btn_pressed() {
	return is_high(PIND, PIND7);
}

uint8_t HVE_btn_pressed() {
	return is_high(PINC, PINC5);
}

uint8_t RTD_btn_pressed() {
	return is_high(PINC, PINC0);
}

uint8_t DAQ_btn_pressed() {
	return is_high(PIND, PIND1);
}

uint8_t mode_btn_pressed() {
	return is_high(PINB, PINB0);
}

uint8_t left_disp_btn_pressed() {
	return is_high(PINC, PINC7);
}

uint8_t center_disp_btn_pressed() {
	return is_high(PINB, PINB6);
}

uint8_t right_disp_btn_pressed() {
	return is_high(PIND, PIND0);
}

void SPI_select_left_disp(uint8_t state) {
	if (state) {
		cbi(PORTB, PORTB3);	 // left on
		sbi(PORTB, PORTB4);  // center off
		sbi(PORTB, PORTB5);  // right off
	} else {
		sbi(PORTB, PORTB3);  // left off
	}
}

void SPI_select_center_disp(uint8_t state) {
	if (state) {
		sbi(PORTB, PORTB3);	 // left off
		cbi(PORTB, PORTB4);  // center on
		sbi(PORTB, PORTB5);  // right off
	} else {
		sbi(PORTB, PORTB4);  // center off
	}
}

void SPI_select_right_disp(uint8_t state) {
	if (state) {
		sbi(PORTB, PORTB3);	 // left off
		sbi(PORTB, PORTB4);  // center off
		cbi(PORTB, PORTB5);  // right on
	} else {
		sbi(PORTB, PORTB5);  // right off
	}
}