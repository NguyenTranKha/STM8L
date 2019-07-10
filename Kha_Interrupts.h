#ifndef _KHA_INTERRUPTS_H_
#define _KHA_INTERRUPTS_H_

#include "Kha_GPIO.h"

//enum Falling, Rising, Only_Rising, Only_Falling
typedef enum State{
  Falling_Edge_And_Low_Level = 0,
  Rising_Edge = 1,
  Falling_Edge = 2,
  Rising_And_Falling_Edge = 3
} __State;

//typedef ITC - EXTI
typedef struct EXTI1_CR1_Type{
  uint8_t P0IS : 2;
  uint8_t P1IS : 2;
  uint8_t P2IS : 2;
  uint8_t P3IS : 2;
} TypeEXTI_CR1;

typedef struct EXTI_CR2_Type{
  uint8_t P4IS : 2;
  uint8_t P5IS : 2;
  uint8_t P6IS : 2;
  uint8_t P7IS : 2;
} TypeEXTI_CR2;

typedef struct EXTI_CR3_Type{
  uint8_t PBIS : 2;
  uint8_t PDIS : 2;
  uint8_t PEIS : 2;
  uint8_t PFIS : 2;
} TypeEXTI_CR3;

typedef struct EXTI_CR4_Type{
  uint8_t PGIS : 2;
  uint8_t PHIS : 2;
  uint8_t Reserved : 4;
} TypeEXTI_CR4;

typedef struct EXTI_SR1_Type{
  uint8_t P0F : 1;
  uint8_t P1F : 1;
  uint8_t P2F : 1;
  uint8_t P3F : 1;
  uint8_t P4F : 1;
  uint8_t P5F : 1;
  uint8_t P6F : 1;
  uint8_t P7F : 1;
} TypeEXTI_SR1;

typedef struct EXTI_SR2_Type{
  uint8_t PBF : 1;
  uint8_t PDF : 1;
  uint8_t PEF : 1;
  uint8_t PFF : 1;
  uint8_t PGF : 1;
  uint8_t PHF : 1;
  uint8_t Reserved : 2;
} TypeEXTI_SR2;

typedef struct EXTI_CONF1_Type{
  uint8_t PBLIS : 1;
  uint8_t PBHIS : 1;
  uint8_t PDLIS : 1;
  uint8_t PDHIS : 1;
  uint8_t PELIS : 1;
  uint8_t PEHIS : 1;
  uint8_t PFLIS : 1;
  uint8_t PFES : 1;
} TypeEXTI_CONF1;

typedef struct EXTI_CONF2_Type{
  uint8_t PFHIS : 1;
  uint8_t PGLIS : 1;
  uint8_t PGHIS : 1;
  uint8_t PHLIS : 1;
  uint8_t PHHIS : 1;
  uint8_t PGBS : 1;
  uint8_t PHDS : 1;
  uint8_t Reserved : 1;
} TypeEXTI_CONF2;

typedef struct ITC_EXTI{
  TypeEXTI_CR1 EXTI_CR1;
  TypeEXTI_CR2 EXTI_CR2;
  TypeEXTI_CR3 EXTI_CR3;
  //TypeEXTI_CR4 EXTI_CR4; //khong co thanh ghi CR4 trong STM8L152C6
  TypeEXTI_SR1 EXTI_SR1;
  TypeEXTI_SR2 EXTI_SR2;
  TypeEXTI_CONF1 EXTI_CONF1;
  TypeEXTI_CONF2 EXTI_CONF2;
} TypeITC_EXTI;

//CPU int CCR
typedef struct CCR_Type{
  uint8_t C : 1;
  uint8_t Z : 1;
  uint8_t N : 1;
  uint8_t I0 : 1;
  uint8_t H : 1;
  uint8_t I1 : 1;
  uint8_t Reverse : 1;
  uint8_t V : 1;
}TypeCCR;

#define ITC_EXTI ((TypeITC_EXTI*) 0x0050A0)
#define CCR ((TypeCCR*)0x007F0A)

void Init_Interrupt()
{
  //init led Blue PC7
  init_Led_Blue();
  init_Led_Green();
  
  //int button PC1
  GPIOC_Fields_Bit->DDR.DDR1 = 0;
  GPIOC_Fields_Bit->CR1.CR1_1 = 1;
  GPIOC_Fields_Bit->CR2.CR2_1 = 1;
  
  //init interrupt
  ITC_EXTI->EXTI_CR1.P1IS = Falling_Edge;
  ITC_EXTI->EXTI_SR1.P1F = 1;
  
  //enable interrupt
  asm("rim\n");
  
  GPIOE_Fields_Bit->ODR.ODR7 = 1;
}

#endif // _KHA_INTERRUPTS_H_