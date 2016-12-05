/*

   MODULE DESCRIPTION:  

   AUTHOR:  Marco Ing. Dau		 																									

   ****************************************************************************************************************************************************
   * SVN-keywords: fields managed by SVN - DO NOT MODIFY 
   *
   *	USER who run commit:    $Author: Administrator $																										
   *	REVISION NUMBER:        $Revision: 344 $																											
   *	LAST DATE REVISION:     $Date: 2016-03-01 17:27:34 +0100 (mar, 01 mar 2016) $															
   *	LOCATION FILE:          $HeadURL: file:///C:/Users/Administrator/Documents/SVN/Repository/fw2/15101-emphil/work/rs2TimerGlo.h $			
   *																																						
   ****************************************************************************************************************************************************

 */

#ifdef _DEF_C
#define _EXTERN_DEF
#else
#define _EXTERN_DEF extern
#endif
 
 
 
 


// ----------------------------------------------------------------------------
// SECTION - SYSTEM INCLUDE
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// SECTION - PROJECT INCLUDE (Dependecies)

// direct dependecies:	------------------

//	reverse dependecies: Test
// #ifdef _DEF_C
// #include "Test.h"
// #endif

// ----------------------------------------------------------------------------

//	++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// SECTION - CONSTANT DEFINITION

#define	TMR_SECOND		0  //  modulo Test  
#define	TMR_TEST_GLCD	1  //  modulo Test 
#define	TMR_TOUCH		2  //  modulo Touch
#define	TMR_LCD_INIT	3  //  non fare niente
#define	TMR_BUTTONS		4  //  modulo Buttons
#define	TMR_UI_PAR		5  //  modulo Parameter
#define	TMR_UI_LBOX		6  //  modulo ListBox
#define  TMR_NUMBER		7

#define _TICK_DEC_TIMER		100	// Piattaforma .net di microsoft
//#define _TICK_DEC_TIMER		2		// Piattaforma EasyPic


// SECTION END
//	++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//	++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// SECTION - VARIABLE DEFINITION

#if defined(_DEF_C) || defined(_TIMER_C) || defined(_TEST_C) || defined(_TOUCH_C) || defined(_LCD_C) || defined(_BUTTONS_C) || defined(_UI_PAR_C) || defined(_UI_LBOX_C)
_EXTERN_DEF	int TmrSecond;
_EXTERN_DEF	int TmrError;
_EXTERN_DEF	int TmrTouch;
_EXTERN_DEF	int Timer[TMR_NUMBER];
#endif


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

// typedef void (*EventTimer)(void);
// 
// #ifdef _TIMER_C
// 
// // definizione della tabella in _ROM
// #pragma code
// extern _ROM EventTimer EventTable[];
// 
// // definizione della tabella in ram
// // extern EventTimer EventTable[]; 
// #endif

// #ifdef _DEF_C
// // definizione della tabella in _ROM
// #pragma code
// _ROM EventTimer EventTable[] = {TestTmrSecond,TestTmrSecond}; 
// 
// // definizione della tabella in ram
// //EventTimer EventTable[] = {TestTmrSecond,TestTmrSecond}; 
// #endif
