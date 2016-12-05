/*

   MODULE DESCRIPTION:  

   AUTHOR:  Marco Ing. Dau		 																									

   ****************************************************************************************************************************************************
   * SVN-keywords: fields managed by SVN - DO NOT MODIFY 
   *
   *	USER who run commit:    $Author: Administrator $																										
   *	REVISION NUMBER:        $Revision: 344 $																											
   *	LAST DATE REVISION:     $Date: 2016-03-01 17:27:34 +0100 (mar, 01 mar 2016) $															
   *	LOCATION FILE:          $HeadURL: file:///C:/Users/Administrator/Documents/SVN/Repository/fw2/15101-emphil/work/Test.c $			
   *																																						
   ****************************************************************************************************************************************************

 */


#define	_TEST_C
 
#include "platform.h"

// ----------------------------------------------------------------------------
// SECTION - SYSTEM INCLUDE

// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// SECTION - PROJECT INCLUDE (Dependecies)

#include "ConfigEasyPicV7.h"


// direct dependecies:

//	reverse dependecies: Timer, Glcd, Touch
#include "rs2TimerGlo.h"
#include "rs2lcd.h"
#include "rs2Glcd.h"
#include "rs2TouchGlo.h"

#include "rs2ButtonsGlo.h"


// ----------------------------------------------------------------------------

//	++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// SECTION - CONSTANT DEFINITION
// ------------------------01234567890123456789
#define  STR_VERSIONE_FW  "Test FW ver 0 81xxxx"

// SECTION END
//	++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//	++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// SECTION - VARIABLE DEFINITION

char Flag;
char Counter;

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

// void InitMicro (void)
// {
// 
//    // set RC0 and RC11 as digital output
//    ANSELC &= 0xCF;
//    TRISC  &= 0xCF;
// 
// }

#ifdef _CONFIG_EASY_PIC_V7_GRAPHIC_LCD
void TestInit (void)
{
}
#elif defined(_CONFIG_EASY_PIC_V7_LCD)
void TestInit (void)
{
//   LcdRomStrRC(1,0,STR_VERSIONE_FW);
}
#endif


void TestTmrSecond (void)
{
   Timer[TMR_SECOND] = 10;
   
}


#if defined(_CONFIG_EASY_PIC_V7_TOUCH) && defined(_CONFIG_EASY_PIC_V7_GRAPHIC_LCD)
void TestTmrGLCD (void)
{
  
}
#elif defined(_CONFIG_EASY_PIC_V7_LCD)
void TestTmrGLCD (void)
{
}
#endif
