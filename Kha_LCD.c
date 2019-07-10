#include "Kha_LCD.h"
#include "Kha_CLOCK.h"

uint32_t b = 999;

void Init_BlinkLCD(void)
{
  Configure_Clock->CLK_CRTCR.RTCSEL = LSE;
  Configure_Clock->CLK_CRTCR.RTCDIV = Divider_number_2;
  Configure_Clock->CLK_PCKENR2 = 0x88;
  
  
  LCD->LCD_CR1.BLINK = 0x03;
  LCD->LCD_CR1.BLINKF = 0x04; //128
  
  LCD->LCD_CR1.DUTY = 0x03; //1/4
  LCD->LCD_FRQ.PS = 0x03;
  LCD->LCD_FRQ.DIV = 0;
  LCD->LCD_PM0.SEG00 = 1; //port mask
  LCD->LCD_PM0.SEG01 = 1;
  LCD->LCD_PM0.SEG02 = 1;
  LCD_Ram->LCD_LCD_RAM0 = 0xff;
  LCD_Ram->LCD_LCD_RAM1 = 0xff;
  LCD_Ram->LCD_LCD_RAM2 = 0xff;
  LCD_Ram->LCD_LCD_RAM3 = 0xff;
  LCD_Ram->LCD_LCD_RAM4 = 0xff;
  LCD_Ram->LCD_LCD_RAM5 = 0xff;
  LCD_Ram->LCD_LCD_RAM6 = 0xff;
  LCD_Ram->LCD_LCD_RAM7 = 0xff;
  LCD_Ram->LCD_LCD_RAM8 = 0xff;
  LCD_Ram->LCD_LCD_RAM9 = 0xff;
  LCD_Ram->LCD_LCD_RAM10 = 0xff;
  LCD_Ram->LCD_LCD_RAM11 = 0xff;
  LCD_Ram->LCD_LCD_RAM12 = 0xff;
  LCD_Ram->LCD_LCD_RAM13 = 0xff;
  LCD->LCD_CR3.LCDEN = 1;
};

void Test_LCD(void)
{
  //Configure CLock LCD
  Configure_Clock->CLK_CRTCR.RTCSEL = LSE; //32.768
  Configure_Clock->CLK_CRTCR.RTCDIV = Divider_number_2; //16.384
  Configure_Clock->CLK_PCKENR2 = 0x88; //enable
  
  LCD->LCD_CR1.DUTY = 3; //1/4
  LCD->LCD_FRQ.PS = 3;
  LCD->LCD_FRQ.DIV = 0;
  LCD->LCD_CR2.CC = 0x07;
  
  //LCD->LCD_PM0.SEG00 = 1; //port mask
  //LCD->LCD_PM0.SEG01 = 1;
  //LCD->LCD_PM0.SEG02 = 1;
  //LCD->LCD_PM0.SEG03 = 1;
  //LCD->LCD_PM0.SEG04 = 1;
  //LCD->LCD_PM0.SEG05 = 1;
  //LCD->LCD_PM0.SEG06 = 1;
  //LCD->LCD_PM0.SEG07 = 1;
  
  //LED5
  LCD->LCD_PM1.SEG08 = 1; //port mask
  LCD->LCD_PM1.SEG09 = 1;
  LCD->LCD_PM1.SEG14 = 1;
  LCD->LCD_PM1.SEG15 = 1;
  
  //LED6
  LCD->LCD_PM1.SEG10 = 1;
  LCD->LCD_PM1.SEG11 = 1;
  LCD->LCD_PM1.SEG12 = 1;
  LCD->LCD_PM1.SEG13 = 1;

  //LCD->LCD_PM2.SEG16 = 1; //port mask
  //LCD->LCD_PM2.SEG17 = 1;
  //LCD->LCD_PM2.SEG18 = 1;
  //LCD->LCD_PM2.SEG19 = 1;
  //LCD->LCD_PM2.SEG20 = 1;
  //LCD->LCD_PM2.SEG21 = 1;
  //LCD->LCD_PM2.SEG22 = 1;
  //LCD->LCD_PM2.SEG23 = 1;
  
  //LCD_Ram->LCD_LCD_RAM0 = 0xff;
  LCD_Ram->LCD_LCD_RAM1 = 0xff; //B E G M COM0
  //LCD_Ram->LCD_LCD_RAM2 = 0xff;
  //LCD_Ram->LCD_LCD_RAM3 = 0xff;
  
  LCD_Ram->LCD_LCD_RAM4 = 0xf0; //A C D F
  LCD_Ram->LCD_LCD_RAM5 = 0x0f;
  //LCD_Ram->LCD_LCD_RAM6 = 0xff;
  
  //LCD_Ram->LCD_LCD_RAM7 = 0xff;
  //LCD_Ram->LCD_LCD_RAM8 = 0xff;
  //LCD_Ram->LCD_LCD_RAM9 = 0xff;
  //LCD_Ram->LCD_LCD_RAM10 = 0xff;
  //LCD_Ram->LCD_LCD_RAM11 = 0xff;
  //LCD_Ram->LCD_LCD_RAM12 = 0xff;
  //LCD_Ram->LCD_LCD_RAM13 = 0xff;
  
  LCD->LCD_CR3.LCDEN = 1;
};
#pragma vector=18
__interrupt void LCDD(void)
{
  Show_LCD(b);
  LCD->LCD_CR3.SOFC = 1;
}

void Init_LCD(void)
{
  //Configure CLock LCD
  Configure_Clock->CLK_CRTCR.RTCSEL = LSE; //32.768
  Configure_Clock->CLK_CRTCR.RTCDIV = Divider_number_2; //16.384
  Configure_Clock->CLK_PCKENR2 = 0x88; //enable
  
  LCD->LCD_CR1.DUTY = 3; //1/4
  LCD->LCD_FRQ.PS = 3;
  LCD->LCD_FRQ.DIV = 0;
  LCD->LCD_CR2.CC = 0x07;
  
  //LED3
  LCD->LCD_PM0.SEG04 = 1;
  LCD->LCD_PM0.SEG05 = 1;
  LCD->LCD_PM2.SEG18 = 1;
  LCD->LCD_PM2.SEG19 = 1;
  
  //LED4
  LCD->LCD_PM0.SEG06 = 1;
  LCD->LCD_PM0.SEG07 = 1;
  LCD->LCD_PM2.SEG16 = 1; //port mask
  LCD->LCD_PM2.SEG17 = 1;
  
  //LED5
  LCD->LCD_PM1.SEG08 = 1; //port mask
  LCD->LCD_PM1.SEG09 = 1;
  LCD->LCD_PM1.SEG14 = 1;
  LCD->LCD_PM1.SEG15 = 1;
  
  //LED6
  LCD->LCD_PM1.SEG10 = 1;
  LCD->LCD_PM1.SEG11 = 1;
  LCD->LCD_PM1.SEG12 = 1;
  LCD->LCD_PM1.SEG13 = 1;
  
  LCD->LCD_CR3.LCDEN = 1;
  //LCD->LCD_CR3.SOFIE = 1;
};

void Show_LCD(uint32_t number)
{
  //LCD->LCD_CR3.LCDEN = 0;
  LCD_Ram->LCD_LCD_RAM0 = 0x00;
  LCD_Ram->LCD_LCD_RAM1 = 0x00;
  LCD_Ram->LCD_LCD_RAM2 = 0x00;
  LCD_Ram->LCD_LCD_RAM4 = 0x00;
  LCD_Ram->LCD_LCD_RAM5 = 0x00;
  
  uint32_t temp_nghin = number / 1000;
  uint32_t temp_dv = number % 1000;
    
  uint32_t temp_tram = temp_dv / 100;
  temp_dv %= 100;
  
  uint32_t temp_chuc = temp_dv / 10;
  temp_dv %= 10;
  
  switch(temp_dv)
  {
  case 0:
    LCD_Ram->LCD_LCD_RAM1 |= 0x14; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM4 |= 0xC0; //A C D F COM1
    LCD_Ram->LCD_LCD_RAM5 |= 0x03;
    break;
  case 1:
    LCD_Ram->LCD_LCD_RAM1 |= 0x10; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM4 |= 0x80; //A C D F COM1
    LCD_Ram->LCD_LCD_RAM5 |= 0x00;
    break;
  case 2:
    LCD_Ram->LCD_LCD_RAM1 |= 0x3C; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM4 |= 0x40; //A C D F COM1
    LCD_Ram->LCD_LCD_RAM5 |= 0x01;
    break;
  case 3:
    LCD_Ram->LCD_LCD_RAM1 |= 0x38; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM4 |= 0xC0; //A C D F COM1
    LCD_Ram->LCD_LCD_RAM5 |= 0x01;
    break;
  case 4:
    LCD_Ram->LCD_LCD_RAM1 |= 0x38; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM4 |= 0x80; //A C D F COM1
    LCD_Ram->LCD_LCD_RAM5 |= 0x02;
    break;
  case 5:
    LCD_Ram->LCD_LCD_RAM1 |= 0x28; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM4 |= 0xC0; //A C D F COM1
    LCD_Ram->LCD_LCD_RAM5 |= 0x03;
    break;
  case 6:
    LCD_Ram->LCD_LCD_RAM1 |= 0x2C; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM4 |= 0xC0; //A C D F COM1
    LCD_Ram->LCD_LCD_RAM5 |= 0x03;
    break;
  case 7:
    LCD_Ram->LCD_LCD_RAM1 |= 0x10; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM4 |= 0x80; //A C D F COM1
    LCD_Ram->LCD_LCD_RAM5 |= 0x01;
    break;
  case 8:
    LCD_Ram->LCD_LCD_RAM1 |= 0x3C; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM4 |= 0xC0; //A C D F COM1
    LCD_Ram->LCD_LCD_RAM5 |= 0x03;
    break;
  case 9:
    LCD_Ram->LCD_LCD_RAM1 |= 0x38; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM4 |= 0xC0; //A C D F COM1
    LCD_Ram->LCD_LCD_RAM5 |= 0x03;
    break;
  }
  
  switch(temp_chuc)
  {
  case 0:
    LCD_Ram->LCD_LCD_RAM1 |= 0x41; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM4 |= 0x30; //A C D F COM1
    LCD_Ram->LCD_LCD_RAM5 |= 0x0C;
    break;
  case 1:
    LCD_Ram->LCD_LCD_RAM1 |= 0x40; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM4 |= 0x20; //A C D F COM1
    LCD_Ram->LCD_LCD_RAM5 |= 0x00;
    break;
  case 2:
    LCD_Ram->LCD_LCD_RAM1 |= 0xC3; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM4 |= 0x10; //A C D F COM1
    LCD_Ram->LCD_LCD_RAM5 |= 0x04;
    break;
  case 3:
    LCD_Ram->LCD_LCD_RAM1 |= 0xC2; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM4 |= 0x30; //A C D F COM1
    LCD_Ram->LCD_LCD_RAM5 |= 0x04;
    break;
  case 4:
    LCD_Ram->LCD_LCD_RAM1 |= 0xC2; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM4 |= 0x20; //A C D F COM1
    LCD_Ram->LCD_LCD_RAM5 |= 0x08;
    break;
  case 5:
    LCD_Ram->LCD_LCD_RAM1 |= 0x82; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM4 |= 0x30; //A C D F COM1
    LCD_Ram->LCD_LCD_RAM5 |= 0x0C;
    break;
  case 6:
    LCD_Ram->LCD_LCD_RAM1 |= 0x83; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM4 |= 0x30; //A C D F COM1
    LCD_Ram->LCD_LCD_RAM5 |= 0x0C;
    break;
  case 7:
    LCD_Ram->LCD_LCD_RAM1 |= 0x40; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM4 |= 0x20; //A C D F COM1
    LCD_Ram->LCD_LCD_RAM5 |= 0x04;
    break;
  case 8:
    LCD_Ram->LCD_LCD_RAM1 |= 0xC3; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM4 |= 0x30; //A C D F COM1
    LCD_Ram->LCD_LCD_RAM5 |= 0x0C;
    break;
  case 9:
    LCD_Ram->LCD_LCD_RAM1 |= 0xC2; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM4 |= 0x30; //A C D F COM1
    LCD_Ram->LCD_LCD_RAM5 |= 0x0C;
    break;
  }
  
  switch(temp_tram)
  {
  case 0:
    LCD_Ram->LCD_LCD_RAM0 |= 0x40; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM2 |= 0x01; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM4 |= 0x0C; //A C D F COM1
    LCD_Ram->LCD_LCD_RAM5 |= 0x30;
    break;
  case 1:
    LCD_Ram->LCD_LCD_RAM0 |= 0x00; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM2 |= 0x01; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM4 |= 0x08; //A C D F COM1
    LCD_Ram->LCD_LCD_RAM5 |= 0x00;
    break;
  case 2:
    LCD_Ram->LCD_LCD_RAM0 |= 0xC0; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM2 |= 0x03; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM4 |= 0x04; //A C D F COM1
    LCD_Ram->LCD_LCD_RAM5 |= 0x10;
    break;
  case 3:
    LCD_Ram->LCD_LCD_RAM0 |= 0x80; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM2 |= 0x03; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM4 |= 0x0C; //A C D F COM1
    LCD_Ram->LCD_LCD_RAM5 |= 0x10;
    break;
  case 4:
    LCD_Ram->LCD_LCD_RAM0 |= 0x80; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM2 |= 0x03; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM4 |= 0x08; //A C D F COM1
    LCD_Ram->LCD_LCD_RAM5 |= 0x20;
    break;
  case 5:
    LCD_Ram->LCD_LCD_RAM0 |= 0X80; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM2 |= 0x02; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM4 |= 0x0C; //A C D F COM1
    LCD_Ram->LCD_LCD_RAM5 |= 0x30;
    break;
  case 6:
    LCD_Ram->LCD_LCD_RAM0 |= 0xC0; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM2 |= 0x02; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM4 |= 0x0C; //A C D F COM1
    LCD_Ram->LCD_LCD_RAM5 |= 0x30;
    break;
  case 7:
    LCD_Ram->LCD_LCD_RAM0 |= 0x00; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM2 |= 0x01; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM4 |= 0x08; //A C D F COM1
    LCD_Ram->LCD_LCD_RAM5 |= 0x10;
    break;
  case 8:
    LCD_Ram->LCD_LCD_RAM0 |= 0xC0; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM2 |= 0x03; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM4 |= 0x0C; //A C D F COM1
    LCD_Ram->LCD_LCD_RAM5 |= 0x30;
    break;
  case 9:
    LCD_Ram->LCD_LCD_RAM0 |= 0x80; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM2 |= 0x03; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM4 |= 0x0C; //A C D F COM1
    LCD_Ram->LCD_LCD_RAM5 |= 0x30;
    break;
  }
  
  switch(temp_nghin)
  {
  case 0:
    LCD_Ram->LCD_LCD_RAM0 |= 0x10; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM2 |= 0x04; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM4 |= 0x03; //A C D F COM1
    LCD_Ram->LCD_LCD_RAM5 |= 0xC0;
    break;
  case 1:
    LCD_Ram->LCD_LCD_RAM0 |= 0x00; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM2 |= 0x04; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM4 |= 0x02; //A C D F COM1
    LCD_Ram->LCD_LCD_RAM5 |= 0x00;
    break;
  case 2:
    LCD_Ram->LCD_LCD_RAM0 |= 0x30; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM2 |= 0x0C; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM4 |= 0x01; //A C D F COM1
    LCD_Ram->LCD_LCD_RAM5 |= 0x40;
    break;
  case 3:
    LCD_Ram->LCD_LCD_RAM0 |= 0x20; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM2 |= 0x0C; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM4 |= 0x03; //A C D F COM1
    LCD_Ram->LCD_LCD_RAM5 |= 0x40;
    break;
  case 4:
    LCD_Ram->LCD_LCD_RAM0 |= 0x20; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM2 |= 0x0C; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM4 |= 0x02; //A C D F COM1
    LCD_Ram->LCD_LCD_RAM5 |= 0x80;
    break;
  case 5:
    LCD_Ram->LCD_LCD_RAM0 |= 0X20; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM2 |= 0x08; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM4 |= 0x03; //A C D F COM1
    LCD_Ram->LCD_LCD_RAM5 |= 0xC0;
    break;
  case 6:
    LCD_Ram->LCD_LCD_RAM0 |= 0x30; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM2 |= 0x08; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM4 |= 0x03; //A C D F COM1
    LCD_Ram->LCD_LCD_RAM5 |= 0xC0;
    break;
  case 7:
    LCD_Ram->LCD_LCD_RAM0 |= 0x00; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM2 |= 0x04; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM4 |= 0x02; //A C D F COM1
    LCD_Ram->LCD_LCD_RAM5 |= 0x40;
    break;
  case 8:
    LCD_Ram->LCD_LCD_RAM0 |= 0x30; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM2 |= 0x0C; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM4 |= 0x03; //A C D F COM1
    LCD_Ram->LCD_LCD_RAM5 |= 0xC0;
    break;
  case 9:
    LCD_Ram->LCD_LCD_RAM0 |= 0x20; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM2 |= 0x0C; //B E G M COM0
    LCD_Ram->LCD_LCD_RAM4 |= 0x03; //A C D F COM1
    LCD_Ram->LCD_LCD_RAM5 |= 0xC0;
    break;
  }
  
  
}