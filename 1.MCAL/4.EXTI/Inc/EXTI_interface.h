#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


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

}EXTI_LineNum;

typedef enum
{
	FALLING_TRIG,
	RISING_TRIG,
	FALLING_RISING_TRIG
}EXTI_TrigSrc_T;

typedef enum
{
	ENABLED,
	DISABLED,

}EXTI_InitState_T;


typedef struct
{
	EXTI_LineNum LineNum;
	EXTI_InitState_T InitState;
	EXTI_TrigSrc_T TrigSrc;
	void(* CallBackFunc)(void);

}EXTI_Config_T;


uint8_t EXTI_u8Init(EXTI_Config_T * Copy_Config);

uint8_t EXTI_u8SetTrigSrc(EXTI_LineNum Copy_LineNum,EXTI_TrigSrc_T Copy_TrigSrc);

void EXTI_u8EnableInt(EXTI_LineNum Copy_LineNum);

void EXTI_u8DisableInt(EXTI_LineNum Copy_LineNum);

void EXTI_u8ClearPendingFlag(EXTI_LineNum Copy_LineNum);

uint8_t EXTI_u8GetPendingFlag(EXTI_LineNum Copy_LineNum , uint8_t *Copy_p8FlagStatus);

#endif
