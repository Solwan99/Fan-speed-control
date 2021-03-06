/******************************************************************************
 *
 * File Name: Mini_Project2.c
 *
 * Description: Source file for the project.
 *
 * Author: Solwan Shokry Ahmed
 *
 *******************************************************************************/
#include "Mini_Project2.h"

int main(void){

	/*Variable to hold the value of the resistance*/
	uint16 resDigitalValue;

	SREG  |= (1<<7);

	/*Configure pin3 in PORTB as an output pin (Outputs the pulse with modulated signal generated by Timer0)*/
	DDRB  = DDRB | (1<<PB3);

	/*Initialize the motor's pins and operation*/
	DCmotor_Init();

	/*Initialize the LCD*/
	LCD_init();

	/*Initialize the ADC*/
	ADC_Init();

	/*Initialize the external interrupt INT1*/
	INT1_Init();

	/*Initially display this string and for the entire program*/
	LCD_displayString("ADC Value = ");

	while(1)
	{
		/*Go to this position after the initial string is located*/
		LCD_goToRowColumn(0,12);
		/*Read the digital value converted by the ADC*/
		resDigitalValue=ADC_readChannel(0);

		/*Display the value that has been read on the LCD*/
		LCD_intgerToString(resDigitalValue);

		/*Initialize the timer's PWM mode's duty cycle value controlled by the value of the variable resistance*/
		Timer0_PWM_MODE_Init(resDigitalValue/4);
	}
}
