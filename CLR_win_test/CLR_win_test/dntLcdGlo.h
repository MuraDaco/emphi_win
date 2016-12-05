#include "stdafx.h"


#ifdef _DNT_DEF_CPP
#define _EXTERN_DNT_DEF
#else
#define _EXTERN_DNT_DEF extern
#endif


#define     LCD_COLUMN     20
#define     LCD_ROW        4

_EXTERN_DNT_DEF char lcd_string[LCD_ROW+10][LCD_COLUMN+10];
