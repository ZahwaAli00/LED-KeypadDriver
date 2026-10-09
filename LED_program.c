/* 
 * <<<<<<LED_program.c>>>>>
 * Author : zahwa
 * Layer  : HAL
 * SWC    : LED
 */

#include "STD_Types.h"
#include "BIT_MATH.h"
#include"DIO_interface.h"
#include"LED_private.h"
#include"LED_interface.h"
#include"LED_config.h"
#include <util/delay.h>

void LED_Voidinit(LED_Type LED_Configration)
{
	 DIO_EnumSetPinDirection (LED_Configration.Port, LED_Configration.Pin, DIO_PIN_OUTPUT);
}

void LED_VoidOn(LED_Type LED_Configration)
{
	if(LED_Configration.Active_State==Active_HIGH)
	{
		 DIO_EnumSetPinValue (LED_Configration.Port, LED_Configration.Pin , DIO_PIN_HIGH    );

	}
	else if(LED_Configration.Active_State==Active_LOW)
	{
		 DIO_EnumSetPinValue (LED_Configration.Port, LED_Configration.Pin , DIO_PIN_LOW     );
	}
}

void LED_VoidOff(LED_Type LED_Configration)
{
	if(LED_Configration.Active_State==Active_HIGH)
	{
		 DIO_EnumSetPinValue (LED_Configration.Port, LED_Configration.Pin , DIO_PIN_LOW    );

	}
	else if(LED_Configration.Active_State==Active_LOW)
	{
		 DIO_EnumSetPinValue (LED_Configration.Port, LED_Configration.Pin , DIO_PIN_HIGH   );
	}
}

void LED_VoidToggle(LED_Type LED_Configration)
{
	 DIO_EnumTogglePinValue (LED_Configration.Port, LED_Configration.Pin );
}
