/* 
 * <<<<<<LED_interface.h>>>>>
 * Author : zahwa
 * Layer  : HAL
 * SWC    : LED
 */
#include "STD_Types.h"
#ifndef _LED_INTERFACE_H_
#define _LED_INTERFACE_H_

#define LED_PORTA 0
#define LED_PORTB 1
#define LED_PORTC 2
#define LED_PORTD 3

#define LED_PIN0 0
#define LED_PIN1 1
#define LED_PIN2 2
#define LED_PIN3 3
#define LED_PIN4 4
#define LED_PIN5 5
#define LED_PIN6 6
#define LED_PIN7 7

#define Active_HIGH 1
#define Active_LOW  0	

typedef struct{
	u8 Port;
	u8 Pin;
	u8 Active_State;
}LED_Type;

void LED_Voidinit(LED_Type LED_Configration);
void LED_VoidOn  (LED_Type LED_Configration);
void LED_VoidOff (LED_Type LED_Configration);
void LED_VoidToggle(LED_Type LED_Configration);

#endif
