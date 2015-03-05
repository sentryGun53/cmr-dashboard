/*
 * dashboard_dio.h
 *
 * Created: 3/4/2015 8:41:05 PM
 *  Author: Robert
 */ 

#ifndef DASHBOARD_DIO_H_
#define DASHBOARD_DIO_H_

/* Sets up Direction registers for buttons, LEDs, and SPI on the dashboard. */
void set_DDRs();

/* Functions to read the state of button inputs.
 * These return 1 if the button is pressed, 0 otherwise.
 */
int LVE_btn_pressed();
int HVE_btn_pressed();
int RTD_btn_pressed();
int DAQ_btn_pressed();
int mode_btn_pressed();
int left_disp_btn_pressed();
int center_disp_btn_pressed();
int right_disp_btn_pressed();


#endif /* DASHBOARD_DIO_H_ */