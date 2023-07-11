#include "Ultrasonic.h"

#include <util/delay.h>
uint8 g_edgeCount = 0;
static volatile  uint32 PULSE_T=0;
ICU_ConfigType ICU_CONFIG={F_CPU_8,RAISING};


void Ultrasonic_init(void)
{
	 ICU_init( &ICU_CONFIG );
	 ICU_setCallBack(Ultrasonic_edgeProcessing);
	 SetupPinDirection(TRIGGER_PORT_ID,TRIGGER_PIN_ID,OUTPUT_PIN);
}

void Ultrasonic_Trigger(void)
{
	Write_Pin(TRIGGER_PORT_ID,TRIGGER_PIN_ID,LOGIC_HIGH);
	_delay_us(10);
	Write_Pin(TRIGGER_PORT_ID,TRIGGER_PIN_ID,LOGIC_LOW);

}

uint16 Ultrasonic_readDistance(void)
{
	uint32 Distance=0;
	Ultrasonic_Trigger();
	Distance =((34000*PULSE_T)/(1000000*(1.9699999999)))+1;
	return Distance;

}

 void Ultrasonic_edgeProcessing(void)
{
	g_edgeCount++;
		if(g_edgeCount == 1)
		{
			/*
			 * Clear the timer counter register to start measurements from the
			 * first detected rising edge
			 */
			ICU_clearTimerValue();
			/* Detect falling edge */
			ICU_setEdgeDetectionType(FALLING);
		}
		else if(g_edgeCount == 2)
		{
			/* Store the High time value */
			PULSE_T = ICU_getInputCaptureValue();
			/* Detect rising edge */
			g_edgeCount=0;
			ICU_setEdgeDetectionType(RAISING);

		}
}

