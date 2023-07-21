#include <stdint.h>

#include "STATUS.h"
#include "STM32F446xx.h"

#include "SysCfg_interface.h"
#include "SysCfg_private.h"

void SysCfg_voidSetEXTIPort(SysCfg_LineNum Copy_LineNum, SysCfg_Port_T Copy_Port)
{
	uint8_t Local_u8RegisterNum = Copy_LineNum / SYSCFG_REG_NUM;
	uint8_t Local_u8BitNum = (Local_u8RegisterNum % SYSCFG_REG_NUM)*SYSCFG_REG_NUM;

	/* Clear the required 4 bits*/
	SYSCFG->CR[Local_u8RegisterNum] &= (~(0b1111)<< Local_u8BitNum);

	/* Set the port number*/
	SYSCFG->CR[Local_u8RegisterNum] |= (~Copy_Port<< Local_u8BitNum);

}
