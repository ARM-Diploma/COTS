/***********************************************************************/
/***********************************************************************/
/************************ AUTHER : Hanin Anwar  ************************/
/************************ LAYER  : HAL          ************************/
/************************ SWC    : KEYPAD          ************************/
/************************ VERSION : 1.00         ************************/
/***********************************************************************/
/***********************************************************************/


#ifndef  KPD_INTERFACE_H_
#define  KPD_INTERFACE_H_


#define KPD_COLUMN0_PIN			PIN11
#define KPD_COLUMN1_PIN			PIN10
#define KPD_COLUMN2_PIN			PIN1
#define KPD_COLUMN3_PIN			PIN0

#define KPD_ROW0_PIN			PIN4
#define KPD_ROW1_PIN			PIN5
#define KPD_ROW2_PIN			PIN6
#define KPD_ROW3_PIN			PIN7

typedef enum
{
	ROW0=4,
	ROW1,
	ROW2,
	ROW3,

	COL0=11,
	COL1=10,
	COL2=1,
	COL3=0,

}KeyPad_Config_T;

uint8_t KPD_KeyInit(void);

uint8_t KPD_GetPressedKey(void);
#endif
