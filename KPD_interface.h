/* 
 * <<<<<<KPD_interface.h>>>>>
 * Author : zahwa
 * Layer  : HAL
 * SWC    : KPD
 */

#ifndef _KPD_INTERFACE_H_
#define _KPD_INTERFACE_H_
#include "STD_Types.h"

#define NOTPRESSED 0XFF

void KPD_Init(void);
u8 KPD_u8GetPressed(void);

#endif
