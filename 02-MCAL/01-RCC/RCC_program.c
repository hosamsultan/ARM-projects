/***************************************************************/
/* Author   : Hossam Sultan                                    */
/* DATE     : 17 SEP 2020                                      */
/* Version  : V01                                              */
/***************************************************************/

/*************************used Libratis***********************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_void_EnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if( Copy_u8PerId <= 31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_APB1 : SET_BIT(RCC_AHBENR,Copy_u8PerId);	break;
			case RCC_AHB  : SET_BIT(RCC_APB1  ,Copy_u8PerId);	break;
			case RCC_APB2 : SET_BIT(RCC_APB2  ,Copy_u8PerId);	break;
		}
	}
	
	else
	{
		/*Return Error*/
	}
}

void RCC_void_DisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if( Copy_u8PerId <= 31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB  : CLR_BIT(RCC_APB1  ,Copy_u8PerId);	break;
			case RCC_APB1 : CLR_BIT(RCC_AHBENR,Copy_u8PerId);	break;
			case RCC_APB2 : CLR_BIT(RCC_APB2  ,Copy_u8PerId);	break;
		}
	}
	
	else
	{
		/*Return Error*/
	}
}

void RCC_voidInitSysClock(void)
{
	
}