#ifndef _KHA_GPIO_H_
#define _KHA_GPIO_H_
#include <stdint.h>


/*BAI TAP 1*/
#define PC_ODR (*(uint8_t*)0x00500A)
#define PC_IDR (*(uint8_t*)0x00500B)
#define PC_DDR (*(uint8_t*)0x00500C)
#define PC_CR1 (*(uint8_t*)0x00500D)
#define PC_CR2 (*(uint8_t*)0x00500E)

#define PE_ODR (*(uint8_t*)0x005014)
#define PE_IDR (*(uint8_t*)0x005015)
#define PE_DDR (*(uint8_t*)0x005016)
#define PE_CR1 (*(uint8_t*)0x005017)
#define PE_CR2 (*(uint8_t*)0x005018)

/*BAI TAP 2*/
#define Set_Bit(PORT, bit) (PORT |= (1 << bit))
#define Clear_Bit(PORT, bit) (PORT &= ~(1 << bit))
#define Toggle_Bit(PORT, bit) (PORT ^= (1 << bit))
#define Get_Bit(PORT, bit) (PORT &(1 << bit))

typedef struct TypeGPIO {
    uint8_t ODR;
    uint8_t IDR;
    uint8_t DDR;
    uint8_t CR1;
    uint8_t CR2;
} GPIO_Type;

#define GPIOA ((GPIO_Type*)0x005000)
#define GPIOB ((GPIO_Type*)0x005005)
#define GPIOC ((GPIO_Type*)0x00500A)
#define GPIOD ((GPIO_Type*)0x00500F)
#define GPIOE ((GPIO_Type*)0x005014)
#define GPIOF ((GPIO_Type*)0x005019)
/*BAI TAP 3*/

/*struct ODR fileds bit*/
typedef struct TypeODR{
  uint8_t ODR0 : 1;
  uint8_t ODR1 : 1;
  uint8_t ODR2 : 1;
  uint8_t ODR3 : 1;
  uint8_t ODR4 : 1;
  uint8_t ODR5 : 1;
  uint8_t ODR6 : 1;
  uint8_t ODR7 : 1;
} ODR_Type;

/*struct IDR fileds bit*/
typedef struct TypeIDR{
  uint8_t IDR0 : 1;
  uint8_t IDR1 : 1;
  uint8_t IDR2 : 1;
  uint8_t IDR3 : 1;
  uint8_t IDR4 : 1;
  uint8_t IDR5 : 1;
  uint8_t IDR6 : 1;
  uint8_t IDR7 : 1;
} IDR_Type;

/*struct DDR fileds bit*/
typedef struct TypeDDR{
  uint8_t DDR0 : 1;
  uint8_t DDR1 : 1;
  uint8_t DDR2 : 1;
  uint8_t DDR3 : 1;
  uint8_t DDR4 : 1;
  uint8_t DDR5 : 1;
  uint8_t DDR6 : 1;
  uint8_t DDR7 : 1;
} DDR_Type;

/*struct CR1 fileds bit*/
typedef struct TypeCR1{
  uint8_t CR1_0 : 1;
  uint8_t CR1_1 : 1;
  uint8_t CR1_2 : 1;
  uint8_t CR1_3 : 1;
  uint8_t CR1_4 : 1;
  uint8_t CR1_5 : 1;
  uint8_t CR1_6 : 1;
  uint8_t CR1_7 : 1;
} CR1_Type;

/*struct CR2 fileds bit*/
typedef struct TypeCR2{
  uint8_t CR2_0 : 1;
  uint8_t CR2_1 : 1;
  uint8_t CR2_2 : 1;
  uint8_t CR2_3 : 1;
  uint8_t CR2_4 : 1;
  uint8_t CR2_5 : 1;
  uint8_t CR2_6 : 1;
  uint8_t CR2_7 : 1;
} CR2_Type;

typedef struct TypeGPIO_Fields_Bit{
  ODR_Type ODR;
  IDR_Type IDR;
  DDR_Type DDR;
  CR1_Type CR1;
  CR2_Type CR2;
} GPIO_Fields_Bit_Type;

#define GPIOA_Fields_Bit ((GPIO_Fields_Bit_Type*)0x005000)
#define GPIOB_Fields_Bit ((GPIO_Fields_Bit_Type*)0x005005)
#define GPIOC_Fields_Bit ((GPIO_Fields_Bit_Type*)0x00500A)
#define GPIOD_Fields_Bit ((GPIO_Fields_Bit_Type*)0x00500F)
#define GPIOE_Fields_Bit ((GPIO_Fields_Bit_Type*)0x005014)
#define GPIOF_Fields_Bit ((GPIO_Fields_Bit_Type*)0x005019)

typedef enum PORT
{
  A = 1,
  B = 2,
  C = 3,
  D = 4,
  E = 5,
  F = 6
} Port;

void Init_Output(Port x, int bit);
void Init_Input(Port x, int bit);
void Init_LCD(void);

void init_Led_Blue(void);
void init_Led_Green(void);
#endif // _KHA_GPIO_H_