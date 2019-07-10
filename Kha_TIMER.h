#ifndef _KHA_TIMER_H_
#define _KHA_TIMER_H_

typedef struct TIMER1{
  uint8_t TIM1_CR1;
  uint8_t TIM1_CR2;
  uint8_t TIM1_SMCR;
  uint8_t TIM1_ETR;
  uint8_t TIM1_ETR;
  uint8_t TIM1_IER;
  uint8_t TIM1_SR1;
  uint8_t TIM1_SR2;
  uint8_t TIM1_EGR;
  uint8_t TIM1_CCMR1;
  uint8_t TIM1_CCMR2;
  uint8_t TIM1_CCMR3;
  uint8_t TIM1_CCMR4;
  uint8_t TIM1_CCER1;
  uint8_t TIM1_CCER2 ;
  uint8_t TIM1_CNTRH;
  uint8_t TIM1_CNTRL;
  uint8_t TIM1_PSCRH;
  uint8_t TIM1_PSCRL;
  uint8_t TIM1_ARRH;
  uint8_t TIM1_ARRL;
  uint8_t TIM1_RCR;
  uint8_t TIM1_CCR1H;
  uint8_t TIM1_CCR1L;
  uint8_t TIM1_CCR2H;
  uint8_t TIM1_CCR2L;
  uint8_t TIM1_CCR3H;
  uint8_t TIM1_CCR3L;
  uint8_t TIM1_CCR4H;
  uint8_t TIM1_CCR4L;
  uint8_t TIM1_BKR;
  uint8_t TIM1_DTR;
  uint8_t TIM1_OISR;
  uint8_t TIM1_DCR1;
  uint8_t TIM1_DCR2;
  uint8_t TIM1_DMA1R;
} TypeTIMER1;

#define TIMER1 ((TypeITC_EXTI*) 0x0052B0)

#endif // _KHA_TIMER_H_