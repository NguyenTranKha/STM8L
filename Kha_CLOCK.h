#ifndef _KHA_CLOCK_H_
#define _KHA_CLOCK_H_
#include <stdint.h>
/*Clock STM8L152C6*/
typedef struct TypeInternalClock{
  uint8_t HSION : 1;
  uint8_t HSIRDY : 1;
  uint8_t LSION : 1;
  uint8_t LSIRDY : 1;
  uint8_t SAHALT : 1;
  uint8_t FHWU : 1;
  uint8_t BEEPAHALT : 1;
  uint8_t Reserved : 1;
} InternalClock_Type;

typedef struct TypeExternalClock{
  uint8_t HSEON : 1;
  uint8_t HSERDY : 1;
  uint8_t LSEON : 1;
  uint8_t LSERDY : 1;
  uint8_t HSEBYP : 1;
  uint8_t LSEBYP : 1;
  uint8_t Reserved1 : 1;
  uint8_t Reserved2 : 1;
} ExternalClock_Type;

typedef struct TypeDividerClock{
  uint8_t CKM : 3;
} DividerClock_Type;

typedef struct TypeSwitchControl{
  uint8_t SWBSY : 1;
  uint8_t SWEN : 1;
  uint8_t SWIEN : 1;
  uint8_t SWIF : 1;
  uint8_t Reserved : 4;
} SwitchControl_Type;

typedef enum Divider_Number{
    Divider_number_1 = 0, //divider 1
    Divider_number_2 = 1, //divider 2
    Divider_number_4 = 2, //divider 4
    Divider_number_8 = 3, //divider 8
    Divider_number_16 = 4, //divider 16
    Divider_number_32 = 5, //divider 32
    Divider_number_64 = 6, //divider 64
    Divider_number_128 = 7 //divider 128
} Div_Number;

typedef struct TypeRTC{
  uint8_t RTCSWBSY : 1;
  uint8_t RTCSEL : 4;
  uint8_t RTCDIV : 3;
} RTC_Type;

typedef struct TypeStatus{
  uint8_t REGREADY : 1;
  uint8_t REGOFF : 1;
  uint8_t HSIPD : 1;
  uint8_t LSIPD : 1;
  uint8_t HSEPD : 1;
  uint8_t LSEPD : 1;
  uint8_t EEBUSY : 1;
  uint8_t EEREADY : 1;
} Status_Type;

typedef struct TypeClock {
    DividerClock_Type CLK_DIVR;
    RTC_Type CLK_CRTCR;
    InternalClock_Type CLK_ICKR;
    uint8_t CLK_PCKENR1;
    uint8_t CLK_PCKENR2;
    uint8_t CLK_CCOR;
    ExternalClock_Type CLK_ECKR;
    uint8_t CLK_SCSR;
    uint8_t CLK_SWR;
    SwitchControl_Type CLK_SWCR;
    uint8_t CLK_CSSR;
    uint8_t CLK_CBEEPR;
    uint8_t CLK_HSICALR;
    uint8_t CLK_HSITRIMR;
    uint8_t CLK_HSIUNLCKR;
    Status_Type CLK_REGCSR;
} Clock_Type;

typedef enum SelectClock{
    HSI = 1,
    LSI = 2,
    HSE = 4,
    LSE = 8
} Sel;

#define CFG_GCR (*(uint8_t*)0x007F60)

#define Configure_Clock ((Clock_Type*)0x0050C0)

#endif // _KHA_CLOCK_H_