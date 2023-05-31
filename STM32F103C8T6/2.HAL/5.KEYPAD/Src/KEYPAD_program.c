/***********************************************************************/
/***********************************************************************/
/************************ AUTHER : Hanin Anwar  ************************/
/************************ LAYER  : HAL          ************************/
/************************ SWC    : KEYPAD          ************************/
/************************ VERSION : 1.00         ************************/
/***********************************************************************/
/***********************************************************************/

#include <stdint.h>

#include "../../../1.MCAL/2.GPIO/Inc/GPIO_interface.h"
#include "../Inc/KEYPAD_private.h"
#include "../Inc/KEYPAD_config.h"
#include "../Inc/KEYPAD_interface.h"

static GPIO_PinConfig_T
uint8_t KPD_KeyInit(void)
{

	GPIO_PinConfig_T Key_Row =
		{
				.Port = PORTA,
				.PinNum = PIN
				.Mode = INPUT,
				.InputOutConfig = PULL_UPDN,
				.PullType = PULL_UP,

		};
}
uint8_t KPD_GetPressedKey(void)
{
	uint8_t Local_u8ColumnIdx , Local_u8RowIdx,Local_u8PinSate;
	uint8_t Local_u8PressedKey = KPD_NO_PRESSED_KEY;

	static uint8_t Local_u8KPDArr[ROW_NUM][COLUMN_NUM] = KPD_ARR_VAL;
	static uint8_t Local_u8ColumnArr[COLUMN_NUM] = {KPD_COLUMN0_PIN,KPD_COLUMN1_PIN,KPD_COLUMN2_PIN,KPD_COLUMN3_PIN};
	static uint8_t Local_u8RowArr[ROW_NUM] = {KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};

	for(Local_u8ColumnIdx = 0 ; Local_u8ColumnIdx < COLUMN_NUM ; Local_u8ColumnIdx++)
	{
		/*Activate Current Column*/
		GPIO_u8SetPinValue(KPD_, Local_u8ColumnArr[Local_u8ColumnIdx],PIN_LOW);

		for(Local_u8RowIdx = 0 ; Local_u8RowIdx < ROW_NUM ; Local_u8RowIdx++)
		{
			/*Read The Current Row*/
			GPIO_u8ReadPinValue(KPD_PORT,Local_u8RowArr[Local_u8RowIdx],&Local_u8PinSate);

			/*Check it the Switch is pressed*/
			if (PIN_LOW == Local_u8PinSate)
			{
				Local_u8PressedKey = Local_u8KPDArr[Local_u8RowIdx][Local_u8ColumnIdx];

				/*Polling(busy waiting) until the key is released*/
				while(PIN_LOW == Local_u8PinSate)
				{
					GPIO_u8ReadPinValue(KPD_PORT,Local_u8RowArr[Local_u8RowIdx],&Local_u8PinSate);
				}
				return Local_u8PressedKey;
			}

		}

		/*Deactivate Current Column*/
		GPIO_u8SetPinValue(KPD_PORT,Local_u8ColumnArr[Local_u8ColumnIdx],PIN_HIGH);
	}


	return Local_u8PressedKey;
}
