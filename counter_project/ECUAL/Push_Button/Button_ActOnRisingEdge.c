#include "button.h"

void Button_ActOnRisingEdge( uint8 port_index, uint8 pin_Number, void (*pAction)(void) ){
	if(DIO_ReadPort(port_index,1<<pin_Number))
	{
		SysTick_delay_ms(50);
		if(DIO_ReadPort(port_index,1<<pin_Number))
		{
			pAction();
			while(DIO_ReadPort(port_index,1<<pin_Number))
			{

			}
		}
	}
	
}