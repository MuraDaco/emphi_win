/*

   MODULE DESCRIPTION:  

   AUTHOR:  Marco Ing. Dau		 																									

   ****************************************************************************************************************************************************
   * SVN-keywords: fields managed by SVN - DO NOT MODIFY 
   *
   *	USER who run commit:    $Author: Administrator $																										
   *	REVISION NUMBER:        $Revision: 344 $																											
   *	LAST DATE REVISION:     $Date: 2016-03-01 17:27:34 +0100 (mar, 01 mar 2016) $															
   *	LOCATION FILE:          $HeadURL: file:///C:/Users/Administrator/Documents/SVN/Repository/fw2/15101-emphil/work/Event.c $			
   *																																						
   ****************************************************************************************************************************************************

 */

#define _EVENT_C

#include "platform.h"

// ----------------------------------------------------------------------------
// SECTION - SYSTEM INCLUDE


// SECTION END
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// SECTION - PROJECT INCLUDE (Dependecies)

// definizione della funzione evento
#include "EventGlo.h"

// si apprende il numero dei timers
#include "rs2TimerGlo.h"

// moduli che usano timer
#include "rs2Timer.h"
#include "rs2Touch.h"
#include "rs2Buttons.h"

#include "uiPar.h"
#include "uiLbox.h"

#include "Test.h"

#include "uiPageGlo.h"
//#include "uiBaseGlo.h"


// direct dependecies:

//	reverse dependecies:

// SECTION END
// ----------------------------------------------------------------------------

//	++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// SECTION - CONSTANT DEFINITION

// SECTION END
//	++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//	++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// SECTION - VARIABLE DEFINITION

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

void EventNull (void)
{}


_ROM EventTableDef EventTimer[TMR_NUMBER] = {
                                 TestTmrSecond,    // TMR_SECOND		0  //  modulo Test  
                                 TestTmrGLCD,      // TMR_TEST_GLCD	1  //  modulo Test 
                                 EventNull,        // TMR_TOUCH		2  //  modulo Touch
                                 EventNull,        // TMR_LCD_INIT	3  //  non fare niente
                                 ButtonsTimer,     // TMR_BUTTONS		4  //  modulo Buttons
                                 uiParTimer,       // TMR_UI_PAR		5  //  modulo Parameter
                                 uiLboxTimer       // TMR_UI_LBOX		6  //  modulo ListBox
};                                                 // TMR_NUMBER		7

//_ROM EventTableDef EventTimer[TMR_NUMBER] = {
//                                 TestTmrSecond,    // TMR_SECOND		0  //  modulo Test  
//                                 TestTmrGLCD,      // TMR_TEST_GLCD	1  //  modulo Test 
//                                 TouchTimer,       // TMR_TOUCH		2  //  modulo Touch
//                                 EventNull,        // TMR_LCD_INIT	3  //  non fare niente
//                                 ButtonsTimer      // TMR_BUTTONS		4  //  modulo Lcd
//};                                                 // TMR_NUMBER		5

EventStructX   EventTimerMatrix[1] = {EventTimer};


//EventStructX ButtonsEventMatrix[2] = {{uiPageEvent}, {uiPageEvent}};
EventStructX ButtonsEventMatrix[1] = {uiPageEvent};
