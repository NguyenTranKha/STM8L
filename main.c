#include "Kha_GPIO.h"
#include "Kha_LCD.h"
#include "Kha_Interrupts.h"


void LCD_TestNumber();
uint32_t cnt = 0;
uint32_t a = 0;


int main()
{
  
  //::LCD_Interrupt
  Init_Interrupt();
  Init_LCD();
  //Show_LCD(a);
  while(1)
  {
    LCD_TestNumber();
  };
}

void Delay(){
  uint32_t i = 30000;
  while(i)
    {
      i--;
    }
}

void LCD_TestNumber()
{
  while(a < 10000)
  {
    Show_LCD(a);
    a++;
    Delay();
  }
  a = 0;
}

#pragma vector=11
__interrupt void Button(void)
{
  a++;
  if(a >= 100) a = 0;
  Show_LCD(a);
  ITC_EXTI->EXTI_SR1.P1F = 1;
}

