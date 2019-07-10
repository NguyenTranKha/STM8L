#include "Kha_GPIO.h"

void Init_Output(Port x, int bit){
  switch(x)
  {
  case A:
    Set_Bit(GPIOA->DDR, bit);
    Set_Bit(GPIOA->CR1, bit);
    break;
  case B:
    Set_Bit(GPIOB->DDR, bit);
    Set_Bit(GPIOB->CR1, bit);
    break;
  case C:
    Set_Bit(GPIOC->DDR, bit);
    Set_Bit(GPIOC->CR1, bit);
    break;
  case D:
    Set_Bit(GPIOD->DDR, bit);
    Set_Bit(GPIOD->CR1, bit);
    break;
  case E:
    Set_Bit(GPIOE->DDR, bit);
    Set_Bit(GPIOE->CR1, bit);
    break;
  case F:
    Set_Bit(GPIOF->DDR, bit);
    Set_Bit(GPIOF->CR1, bit);
    break;
  default:
    break;
  }
};
void Init_Input(Port x, int bit);

void init_Led_Blue(void){
  GPIOC_Fields_Bit->DDR.DDR7 = 1;
  GPIOC_Fields_Bit->CR1.CR1_7 = 1;
}

void init_Led_Green(void){
  GPIOE_Fields_Bit->DDR.DDR7 = 1;
  GPIOE_Fields_Bit->CR1.CR1_7 = 1;
}