#ifndef LCD_H_
#define LCD_H_

#include "stm32f1xx_hal.h"

#define d4_set() HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET) /*Логическая 1 на ножке */
#define d5_set() HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET)
#define d6_set() HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET)
#define d7_set() HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET)

#define d4_reset() HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET) /*Логический 0 на ножке */
#define d5_reset() HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET)
#define d6_reset() HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET)
#define d7_reset() HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET)

#define e1    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET) /*установка линии E в 1 */
#define e0    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET) /* установка линии E в 0*/
#define rs1   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET) /* установка линии RS в 1 (данные)*/
#define rs0   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET) /* установка нет линии RS в 0 */

void delay (void);
void LCD_WriteData(uint8_t dt);
void LCD_Command (uint8_t dt);
void LCD_Data (uint8_t dt);
void LCD_ini (void);
void LCD_SendChar(char ch);
void LCD_Clear(void);
void LCD_String(char* st);
void LCD_SetPos(uint8_t x, uint8_t y);

#endif


// как формируется заголовок IP
// как настроить физические порты чтобы с них был доступен VLAN интерфейс 
// для чего указывается айп адрес в настройках сквида 