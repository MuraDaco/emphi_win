/*

   MODULE DESCRIPTION:  

   AUTHOR:  Marco Ing. Dau		 																									

   ****************************************************************************************************************************************************
   * SVN-keywords: fields managed by SVN - DO NOT MODIFY 
   *
   *	USER who run commit:    $Author: Administrator $																										
   *	REVISION NUMBER:        $Revision: 344 $																											
   *	LAST DATE REVISION:     $Date: 2016-03-01 17:27:34 +0100 (mar, 01 mar 2016) $															
   *	LOCATION FILE:          $HeadURL: file:///C:/Users/Administrator/Documents/SVN/Repository/fw2/15101-emphil/work/rs2Lcd.c $			
   *																																						
   ****************************************************************************************************************************************************

 */

#define _LCD_C

#include "platform.h"
#include "..\dntLcdGlo.h"

// SECTION END
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// SECTION - PROJECT INCLUDE (Dependecies)

// direct dependecies:

//	reverse dependecies:
#include "rs2TimerGlo.h"


// SECTION END
// ----------------------------------------------------------------------------

//	++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// SECTION - CONSTANT DEFINITION



// SECTION END
//	++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//	++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// SECTION - VARIABLE DEFINITION

char lcdStato;
char lcdDisplayCursorShift;
char lcdEntryMode;

unsigned char Row;
unsigned char Col;

// SECTION END
//	++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//	++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// SECTION - ARRAY DEFINITION

// SECTION END
//	++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//	****************************************************************************
// SECTION - CONTROL FUNCTION DEFINITION

// SECTION END
//	****************************************************************************

//	****************************************************************************
// SECTION - EVENT FUNCTION DEFINITION

// SECTION END
//	****************************************************************************


//	****************************************************************************
// SECTION - LIBRTARY FUNCTION DEFINITION

// SECTION END
//	****************************************************************************

void LcdRegInit   (void)
{

}

void LcdInit1 (char nib)
{
}

void LcdCmd (char data)
{
}

void LcdCmdCh (char data)
{
}

void LcdInit (void)
{
	char i, j;

	Row = 0;
	Col = 0;

	for(i=0;i<LCD_ROW;i++)
	{
		for(j=0;j<LCD_COLUMN;j++)
		{
			lcd_string[i][j] = '-';
		}
	}

	lcd_string[0][LCD_COLUMN] = 0;
	lcd_string[1][LCD_COLUMN] = 0;
	lcd_string[2][LCD_COLUMN] = 0;
	lcd_string[3][LCD_COLUMN] = 0;
	lcd_string[4][LCD_COLUMN] = 0;

}


void	LcdIncCoord (void)
{
	char ch_box;

	ch_box = LCD_COLUMN*(Row) + Col;

	ch_box++;

	if(ch_box < LCD_COLUMN*LCD_ROW)
	{
		Row = ch_box / LCD_COLUMN;
		Col = ch_box % LCD_COLUMN;
	}
	else
	{
		Row = Col = 0;
	}
}

void LcdSetPosition(unsigned char row, unsigned char column)
{
	Row = row-1;
	Col = column;
}

void LcdCh(char carattere)
{
	lcd_string[Row][Col] = carattere;
	lcd_string[Row][LCD_COLUMN] = 0;

	LcdIncCoord();
}
/* */

void LcdStrRC  (unsigned char row,unsigned char column,char *str)
{
   LcdSetPosition(row,column);
   
   // write string
   while (*str>0)
   {
      LcdCh(*str);
      str++;
   }   
   
}

void LcdRomStrRC  (unsigned char row,unsigned char column,_CONST _ROM char *str)
{
   LcdSetPosition(row,column);
   
   // write string
   while (*str>0)
   {
      LcdCh(*str);
      str++;
   }   
   
}

void LcdNumberRC  (unsigned char row,unsigned char column,unsigned char par)
{
//   char par;
   unsigned char num[4];
   char i;
   
   LcdSetPosition(row,column);
   
//   par = *ptr_par;
   num[3] = 0;
   num[2] = par%10;
   num[1] = (par/10)%10;
   num[0] = par/100;
   
   
   // write string
   for(i=0;i<3;i++)
   {
      LcdCh('0'+num[i]);
   }   
   
}

void LcdDisplayReset (void)
{
}

void LcdDisplayOff (void)
{
}
void LcdDisplayOn (void)
{
}

void LcdCursorOff (void)
{
}
void LcdCursorOn (void)
{
}

void LcdBlinkingOff (void)
{
}
void LcdBlinkingOn (void)
{
}

void LcdDisplayShift (void)
{
}
void LcdCursorShift (void)
{
}

void LcdRightShift (void)
{
}
void LcdLeftShift (void)
{
}

void LcdEntryModeRightShift (void)
{
}
void LcdEntryModeLeftShift (void)
{
}

void LcdEntryModeDisplay (void)
{
}
void LcdEntryModeCursor (void)
{
}
