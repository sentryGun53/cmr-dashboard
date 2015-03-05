/*
 * CMR_Dashboard.c
 *
 * Created: 3/4/2015 9:35:31 PM
 *  Author: Robert
 */ 

#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "dashboard_dio.h"
#include "standard_dio.h"
#include "spi.h"
#include "display.h"

int main(void)
{
	set_DDRs();
	spi_init(0, 1, 0, 3, 0);
	
	while(1) {
		SPI_select_left_disp(1);
		
		// indicator LEDS
		spi_send(0b00000000);
		
		// hundreds place character
		writeDigit(6, 0b101);
		
		// tens place character
		writeDigit(7, 0b011);
		
		// ones place character
		writeDigit(9, 0b111);
		
		SPI_select_left_disp(0);
		_delay_ms(1000);
	}
}