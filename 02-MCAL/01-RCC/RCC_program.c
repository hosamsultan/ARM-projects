/***************************************************************/
/* Author   : Hossam Sultan                                    */
/* DATE     : 17 SEP 2020                                      */
/* Version  : V01                                              */
/***************************************************************/

/*************************used Libratis***********************************/

#include "STD_TYPES.h"
#include "01-LIB/02-BIT_MATH/BIT_MATH.h"


#include "RCC_interface.h"
#include "02-MCAL/01-RCC/RCC_private.h"
#include "RCC_config.h"

void RCC_voidInitSysClock(void)
{
	#if   RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
			RCC_CR   = 0x00010000;				/*Enable Crystal with no bypass*/
			RCC_CFGR = 0x00000001;				/*HSE as clk src*/
    #elif RCC_CLOCK_TYPE == RCC_HSE_RC
			RCC_CR   = 0x00050000;				/*Enable RC with Bypass*/
			RCC_CFGR = 0x00000001;				/*HSE as clk src*/
    #elif RCC_CLOCK_TYPE == RCC_HSI
			RCC_CR   = 0x00000081;				/*Enable HSI +Trimining*/
			RCC_CFGR = 0x00000000;				/*HSI as clk src*/
	#elif RCC_CLOCK_TYPE == RCC_PLL
			#if   RCC_PLL_IN_INPUT == RCC_PLL_IN_HSI_DIV_2
			RCC_CFGR=0x00000000;
			#elif RCC_PLL_IN_INPUT == RCC_PLL_IN_HSE_DIV_2
			RCC_CFGR=0x00000003;
			#elif RCC_PLL_IN_INPUT == RCC_PLL_IN_HSE
			RCC_CFGR=0x00000001;
			#else
				#error("you choosed Wrong PLL Source");
			#endif

			#if   RCC_PLL_MUL_VAL == 2
				RCC_CFGR |= 0x00000000;
			#elif RCC_PLL_MUL_VAL == 3
				RCC_CFGR |= 0x00040000;
			#elif RCC_PLL_MUL_VAL == 4
				RCC_CFGR |= 0x00000000;
			#elif RCC_PLL_MUL_VAL == 5
				RCC_CFGR |= 0x000C0000;
			#elif RCC_PLL_MUL_VAL == 6
				RCC_CFGR |= 0x00100000;
			#elif RCC_PLL_MUL_VAL == 7
				RCC_CFGR |= 0x00140000;
			#elif RCC_PLL_MUL_VAL == 8
				RCC_CFGR |= 0x00180000;
			#elif RCC_PLL_MUL_VAL == 9
				RCC_CFGR |= 0x001C0000;
			#elif RCC_PLL_MUL_VAL == 10
				RCC_CFGR |= 0x00200000;
			#elif RCC_PLL_MUL_VAL == 11
				RCC_CFGR |= 0x00240000;
			#elif RCC_PLL_MUL_VAL == 12
				RCC_CFGR |= 0x00280001;
			#elif RCC_PLL_MUL_VAL == 13
				RCC_CFGR |= 0x002C0000;
			#elif RCC_PLL_MUL_VAL == 14
				RCC_CFGR |= 0x00300000;
			#elif RCC_PLL_MUL_VAL == 15
				RCC_CFGR |=0x00340000;
			#elif RCC_PLL_MUL_VAL == 16
				RCC_CFGR |= 0x00380000;
			#else
				#error("you choosed Wrong PLL prescaler");
			#endif

			RCC_CR =0x01000000;				/*Enable pll*/
    #else
		#error("you chosed Wrong Clock type");
	#endif

}

void RCC_void_EnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if( Copy_u8PerId <= 31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_APB1 :
				SET_BIT(RCC_AHBENR,Copy_u8PerId);
				break;
			case RCC_AHB  :
				SET_BIT(RCC_APB1  ,Copy_u8PerId);
				break;
			case RCC_APB2 :
				SET_BIT(RCC_APB2  ,Copy_u8PerId);
				break;
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
			case RCC_AHB  :
				CLR_BIT(RCC_APB1  ,Copy_u8PerId);
				break;
			case RCC_APB1 :
				CLR_BIT(RCC_AHBENR,Copy_u8PerId);
				break;
			case RCC_APB2 :
				CLR_BIT(RCC_APB2  ,Copy_u8PerId);
				break;
		}
	}
	
	else
	{
		/*Return Error*/
	}
}

