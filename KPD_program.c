/* 
 * <<<<<<KPD_program.c>>>>>
 * Author : zahwa
 * Layer  : HAL
 * SWC    : KPD
 */

#include "STD_Types.h"
#include "BIT_MATH.h"
#include"DIO_interface.h"
#include"KPD_private.h"
#include"KPD_interface.h"
#include"KPD_config.h"
#include <util/delay.h>

void KPD_Init(void)
{
	/*INPUT PULLUP */
	 DIO_EnumSetPinDirection   (KPD_PORT, KPD_R0 , DIO_PIN_INPUT);
	 DIO_EnumSetPinDirection   (KPD_PORT, KPD_R1 , DIO_PIN_INPUT);
	 DIO_EnumSetPinDirection   (KPD_PORT, KPD_R2 , DIO_PIN_INPUT);
	 DIO_EnumSetPinDirection   (KPD_PORT, KPD_R3 , DIO_PIN_INPUT);

	 DIO_EnumSetPinValue       (KPD_PORT, KPD_R0 , DIO_PIN_HIGH  );
	 DIO_EnumSetPinValue       (KPD_PORT, KPD_R1 , DIO_PIN_HIGH  );
	 DIO_EnumSetPinValue       (KPD_PORT, KPD_R2 , DIO_PIN_HIGH  );
	 DIO_EnumSetPinValue       (KPD_PORT, KPD_R3,  DIO_PIN_HIGH  );

	 /*COLUMS AS OUTPUT PINS  -----> HIGH*/
	 DIO_EnumSetPinDirection   (KPD_PORT, KPD_C0 , DIO_PIN_OUTPUT);
	 DIO_EnumSetPinDirection   (KPD_PORT, KPD_C1 , DIO_PIN_OUTPUT);
	 DIO_EnumSetPinDirection   (KPD_PORT, KPD_C2 , DIO_PIN_OUTPUT);
	 DIO_EnumSetPinDirection   (KPD_PORT, KPD_C3 , DIO_PIN_OUTPUT);

	 DIO_EnumSetPinValue       (KPD_PORT, KPD_C0 , DIO_PIN_HIGH  );
	 DIO_EnumSetPinValue       (KPD_PORT, KPD_C1 , DIO_PIN_HIGH  );
	 DIO_EnumSetPinValue       (KPD_PORT, KPD_C2 , DIO_PIN_HIGH  );
	 DIO_EnumSetPinValue       (KPD_PORT, KPD_C3,  DIO_PIN_HIGH  );

}

u8 KPD_u8GetPressed(void)
{
	u8 LOC_u8ReturnData = NOTPRESSED;
	u8 LOC_u8GetPressed  ;
	u8 LOC_u8ROW;
	u8 LOC_u8COL;

	for( LOC_u8COL=0+KPD_COL_INIT ; LOC_u8COL<KPD_COL_END+1 ; LOC_u8COL++)
	{
		/*low on the colum */
		DIO_EnumSetPinValue       (KPD_PORT, LOC_u8COL , DIO_PIN_LOW  );

		for(LOC_u8ROW = 0+KPD_ROW_INIT ; LOC_u8ROW < KPD_ROW_END+1 ; LOC_u8ROW++)
		{
			DIO_EnumGetPinValue       (KPD_PORT , LOC_u8ROW , &LOC_u8GetPressed  );
			/*IF ROW IS HIGH ---> NOT PRESSED*/
			if(LOC_u8GetPressed==0)
			{
				_delay_ms(50); // for bouncing
				DIO_EnumGetPinValue       (KPD_PORT , LOC_u8ROW , &LOC_u8GetPressed  );  // to make sure
				if(LOC_u8GetPressed==0)
				{
					LOC_u8ReturnData=  KPD_u8Buttons [LOC_u8ROW-KPD_ROW_INIT][LOC_u8COL-KPD_COL_INIT];
					_delay_ms(200);
				}
			}

		}
		DIO_EnumSetPinValue       (KPD_PORT, LOC_u8COL , DIO_PIN_HIGH  );

	}

	return LOC_u8ReturnData;
}

