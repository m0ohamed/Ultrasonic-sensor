/*
 ================================================================================================
 Name        : measure_period.c
 Author      : Mohamed Tarek
 Description : Measure period for a signal using ICU driver
 Date        : 10/1/2018
 ================================================================================================
 */

#include "LCD.h"
#include "icu.h"
#include "Ultrasonic.h"
#include "My_GPIO.h"
#include <avr/io.h> /* To use the SREG register */
#include <util/delay.h>
int main()
{
	uint32 Distance = 0;


	/* Enable Global Interrupt I-Bit */
	SREG |= (1<<7);
	SetupPinDirection(PORTC_ID,PIN0_ID,OUTPUT_PIN);
	SetupPinDirection(PORTC_ID,PIN0_ID,OUTPUT_PIN);
	Write_Pin(PORTC_ID,PIN0_ID,LOGIC_LOW);
	Write_Pin(PORTC_ID,PIN1_ID,LOGIC_LOW);
	LCD_init();
	Ultrasonic_init();
	LCD_displayStringRowColumn(1,0,"Distance=     cm");
	while(1)
	{
		Distance=Ultrasonic_readDistance();
		if(Distance>100)
		{
			LCD_moveCursor(1,10);
			LCD_intgerToString(Distance);
		}
		else
		{
			LCD_moveCursor(1,10);
			LCD_intgerToString(Distance);
			LCD_sendCharacter(' ');
		}
		if(Distance<150 && Distance>=100)
		{
			Write_Pin(PORTC_ID,PIN0_ID,LOGIC_HIGH);
			_delay_ms(100);
			Write_Pin(PORTC_ID,PIN0_ID,LOGIC_LOW);
			_delay_ms(100);
			LCD_displayStringRowColumn(2,1,"*BE Careful*");
		}
		else if(Distance<100)
		{
			Write_Pin(PORTC_ID,PIN0_ID,LOGIC_HIGH);
			Write_Pin(PORTC_ID,PIN1_ID,LOGIC_HIGH);
			_delay_ms(50);
			Write_Pin(PORTC_ID,PIN0_ID,LOGIC_LOW);
			Write_Pin(PORTC_ID,PIN1_ID,LOGIC_LOW);
			LCD_displayStringRowColumn(2,1,"*BE Careful*");
		}
		else
		{
			LCD_displayStringRowColumn(2,1,"              ");

		}
	}
}
