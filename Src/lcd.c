#include "lcd.h"


void delay (void) {
	uint16_t i;
	for (i = 0; i < 1000; ++i)
	{}
}

void LCD_WriteData(uint8_t dt) {
	if(((dt >> 3)&0x01)==1) {d7_set();}
 else {d7_reset();}
	if(((dt >> 2)&0x01)==1) {d6_set();}
 else {d6_reset();}
	if(((dt >> 1)&0x01)==1) {d5_set();}
 else {d5_reset();}
	if((dt&0x01)==1) {d4_set();}
 else {d4_reset();}
}

void LCD_Command (uint8_t dt) {
	rs0;
	LCD_WriteData(dt>>4);
	e1;
	delay();
	e0;
	LCD_WriteData(dt);
	e1;
	delay();
	e0;
}



void LCD_ini (void) {
	HAL_Delay(40); // инициализация в 4 битном режиме 
	rs0;
	LCD_WriteData(3);
	e1;
	delay();
	e0;
HAL_Delay(1);
	LCD_WriteData(3);
	e1;
	delay();
	e0;
HAL_Delay(1);
	LCD_WriteData(3);
	e1;
	delay();
	e0;
	HAL_Delay(1);

	LCD_Command(0x28);
	HAL_Delay(1);
	LCD_Command(0x28);
	HAL_Delay(1); // инициалазиция в 4 битный режим завершенна  
	LCD_Command(0x0F); // Включение дисплея и курсора
	HAL_Delay(1);
	LCD_Command(0x01); // отчистка дисплея
	HAL_Delay(2);
	LCD_Command(0x06);//пишем влево
    HAL_Delay(1);
	LCD_Command(0x02);//сброс курсора
	HAL_Delay(2);
}

void LCD_Data (uint8_t dt) {
    rs1;
    LCD_WriteData(dt>>4);
    e1;
    delay();
    e0;
    LCD_WriteData(dt);
    e1;
    delay();
    e0;
} // запись 1 символа в память дисплея

void LCD_SendChar(char ch) {
    LCD_Data((uint8_t) ch);
    delay();
} // отображение 1 символа

void LCD_Clear(void) {
    LCD_Command(0x01);
    HAL_Delay(2);
}

void LCD_String(char* st) {
    for (char i = 0; st[i] != '\o'; ++i) {
        LCD_Data(st[i]);
        delay();
        i++;
    }
}

void LCD_SetPos(uint8_t x, uint8_t y)
{
    switch(y)
    {
        case 0:
            LCD_Command(x|0x80);
            HAL_Delay(1);
            break;
        case 1:
            LCD_Command((0x40+x)|0x80);
            HAL_Delay(1);
            break;
        case 2:
            LCD_Command((0x14+x)|0x80);
            HAL_Delay(1);
            break;
        case 3:
            LCD_Command((0x54+x)|0x80);
            HAL_Delay(1);
            break;
    }
}

