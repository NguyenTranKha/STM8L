#ifndef _KHA_LCD_H_
#define _KHA_LCD_H_
#include <stdint.h>

typedef struct LCD_CR1Type{
  uint8_t B2 : 1;
  uint8_t DUTY : 2;
  uint8_t BLINKF : 3;
  uint8_t BLINK : 2;
} TypeLCD_CR1;

typedef struct LCD_CR2Type{
  uint8_t VSEL : 1;
  uint8_t CC : 3;
  uint8_t HD : 1;
  uint8_t PON : 3;
} TypeLCD_CR2;

typedef struct LCD_CR3Type{
  uint8_t DEAD : 3;
  uint8_t SOFC : 1;
  uint8_t SOF : 1;
  uint8_t SOFIE : 1;
  uint8_t LCDEN : 1;
  uint8_t Reserved : 1;
} TypeLCD_CR3;

typedef struct LCD_FRQType{
  uint8_t DIV : 4;
  uint8_t PS : 4;
} TypeLCD_FRQ;

typedef struct LCD_PM0Type{
  uint8_t SEG00 : 1;
  uint8_t SEG01 : 1;
  uint8_t SEG02 : 1;
  uint8_t SEG03 : 1;
  uint8_t SEG04 : 1;
  uint8_t SEG05 : 1;
  uint8_t SEG06 : 1;
  uint8_t SEG07 : 1;
} TypeLCD_PM0;

typedef struct LCD_PM1Type{
  uint8_t SEG08 : 1;
  uint8_t SEG09 : 1;
  uint8_t SEG10 : 1;
  uint8_t SEG11 : 1;
  uint8_t SEG12 : 1;
  uint8_t SEG13 : 1;
  uint8_t SEG14 : 1;
  uint8_t SEG15 : 1;
} TypeLCD_PM1;

typedef struct LCD_PM2Type{
  uint8_t SEG16 : 1;
  uint8_t SEG17 : 1;
  uint8_t SEG18 : 1;
  uint8_t SEG19 : 1;
  uint8_t SEG20 : 1;
  uint8_t SEG21 : 1;
  uint8_t SEG22 : 1;
  uint8_t SEG23 : 1;
} TypeLCD_PM2;

//LCD Control
typedef struct LCDType{
  TypeLCD_CR1 LCD_CR1;
  TypeLCD_CR2 LCD_CR2;
  TypeLCD_CR3 LCD_CR3;
  TypeLCD_FRQ LCD_FRQ;
  TypeLCD_PM0 LCD_PM0;
  TypeLCD_PM1 LCD_PM1;
  TypeLCD_PM2 LCD_PM2;
} TypeLCD;

//LCD RAM
typedef struct LCD_RAMType{
  uint8_t LCD_LCD_RAM0;
  uint8_t LCD_LCD_RAM1;
  uint8_t LCD_LCD_RAM2;
  uint8_t LCD_LCD_RAM3;
  uint8_t LCD_LCD_RAM4;
  uint8_t LCD_LCD_RAM5;
  uint8_t LCD_LCD_RAM6;
  uint8_t LCD_LCD_RAM7;
  uint8_t LCD_LCD_RAM8;
  uint8_t LCD_LCD_RAM9;
  uint8_t LCD_LCD_RAM10;
  uint8_t LCD_LCD_RAM11;
  uint8_t LCD_LCD_RAM12;
  uint8_t LCD_LCD_RAM13;
} TypeLCD_Ram;

#define LCD ((TypeLCD*) 0x005400)
#define LCD_Ram ((TypeLCD_Ram*) 0x00540C)

void Init_LCD(void);
void Init_BlinkLCD(void);
void Test_LCD(void);
void Show_LCD(uint32_t number);

#endif 