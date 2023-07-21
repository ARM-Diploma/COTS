#ifndef SYSCFG_INTERFACE_H_
#define SYSCFG_INTERFACE_H_

typedef enum
{
    PORTA=0,
    PORTB,
    PORTC,
    PORTD,
    PORTE,
    PORTF,
    PORTG,
    PORTH

}SysCfg_Port_T;

typedef enum
{
	EXTI0,
	EXTI1,
	EXTI2,
	EXTI3,
	EXTI4,
	EXTI5,
	EXTI6,
	EXTI7,
	EXTI8,
	EXTI9,
	EXTI10,
	EXTI11,
	EXTI12,
	EXTI13,
	EXTI14,
	EXTI15,
	EXTI16,
	EXTI17,
	EXTI18,
	EXTI19,
	EXTI20,
	EXTI21,
	EXTI22,

}SysCfg_LineNum;

void SysCfg_voidSetEXTIPort(SysCfg_LineNum Copy_LineNum, SysCfg_Port_T Copy_Port);

#endif
