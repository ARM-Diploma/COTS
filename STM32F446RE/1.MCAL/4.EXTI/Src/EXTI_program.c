#include <stdint.h>

#include "STM32F446xx.h"
#include "STATUS.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"

static void(* EXTI_CallBackFunc[EXTI_LINE_NUM])(void) = {NULL};

uint8_t EXTI_u8Init(EXTI_Config_T * Copy_Config)
{
	uint8_t Local_u8ErrorState = OK;

	if(Copy_Config != NULL)
	{
		/* 1. Setting Trigger Source */
		switch(Copy_Config->TrigSrc)
		{

		/* Set Rising and Clear Falling*/
		case RISING_TRIG:
			EXTI->RTSR |= (1 << (Copy_Config->LineNum));
			EXTI->FTSR &= (~(1 << (Copy_Config->LineNum)));
			break;

			/* Set Falling and Clear Rising*/
		case FALLING_TRIG:
			EXTI->FTSR |= (1 << (Copy_Config->LineNum));
			EXTI->RTSR &= (~(1 << (Copy_Config->LineNum)));
			break;

			/* Set Rising & Falling*/
		case FALLING_RISING_TRIG:
			EXTI->RTSR |= (1 << (Copy_Config->LineNum));
			EXTI->FTSR |= (1 << (Copy_Config->LineNum));
			break;

		default : Local_u8ErrorState = NOK;
		}

		/* 2. Set Interrupt Enable/Disable Initial State*/
		if(Copy_Config->InitState == ENABLED)
		{
			EXTI->IMR |= (1 << (Copy_Config->LineNum));
		}

		else if(Copy_Config->InitState == DISABLED)
		{
			EXTI->IMR &= (~(1 << (Copy_Config->LineNum)));

		}

		else
		{
			Local_u8ErrorState = NOK;
		}

		/* 3.Setting Callback Function*/
		if(Copy_Config->CallBackFunc != NULL)
		{
			EXTI_CallBackFunc[Copy_Config->LineNum] = Copy_Config->CallBackFunc;
		}

		else
		{
			Local_u8ErrorState = NULL_PTR;
		}
	}

	else
	{
		Local_u8ErrorState = NULL_PTR;
	}

	return Local_u8ErrorState;
}

uint8_t EXTI_u8SetTrigSrc(EXTI_LineNum Copy_LineNum,EXTI_TrigSrc_T Copy_TrigSrc)
{
	uint8_t Local_u8ErrorState = OK;

	/* 1. Setting Trigger Source */
	switch(Copy_Config->TrigSrc)
	{

	/* Set Rising and Clear Falling*/
	case RISING_TRIG:
		EXTI->RTSR |= (1 << (LineNum));
		EXTI->FTSR &= (~(1 << (LineNum)));
		break;

		/* Set Falling and Clear Rising*/
	case FALLING_TRIG:
		EXTI->FTSR |= (1 << (LineNum));
		EXTI->RTSR &= (~(1 << (LineNum)));
		break;

		/* Set Rising & Falling*/
	case FALLING_RISING_TRIG:
		EXTI->RTSR |= (1 << (LineNum));
		EXTI->FTSR |= (1 << (LineNum));
		break;

	default : Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState ;
}
void EXTI_u8EnableInt(EXTI_LineNum Copy_LineNum)
{
	EXTI->IMR |= (1 << (Copy_Num));
}

void EXTI_u8DisableInt(EXTI_LineNum Copy_LineNum)
{

	EXTI->IMR &= (~(1 << (Copy_Num)));
}


void EXTI_u8ClearPendingFlag(EXTI_LineNum Copy_LineNum)
{
	EXTI->PR = 1 << Copy_LineNum;
}

uint8_t EXTI_u8GetPendingFlag(EXTI_LineNum Copy_LineNum , uint8_t *Copy_p8FlagStatus)
{

	uint8_t Local_u8ErrorState = OK;
	if(Copy_p8FlagStatus != NULL)
	{
		*Copy_p8FlagStatus = (EXTI->PR >> Copy_LineNum)&1;
	}
	else
	{
		Local_u8ErrorState = NULL_PTR;
	}
	return Local_u8ErrorState;


}
