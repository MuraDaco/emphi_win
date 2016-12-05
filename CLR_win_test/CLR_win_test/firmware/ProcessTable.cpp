/*

   MODULE DESCRIPTION:  

   AUTHOR:  Marco Ing. Dau		 																									

   ****************************************************************************************************************************************************
   * SVN-keywords: fields managed by SVN - DO NOT MODIFY 
   *
   *	USER who run commit:    $Author: Administrator $																										
   *	REVISION NUMBER:        $Revision: 344 $																											
   *	LAST DATE REVISION:     $Date: 2016-03-01 17:27:34 +0100 (mar, 01 mar 2016) $															
   *	LOCATION FILE:          $HeadURL: file:///C:/Users/Administrator/Documents/SVN/Repository/fw2/15101-emphil/work/ProcessTable.c $			
   *																																						
   ****************************************************************************************************************************************************

 */

#define _PROCESS_TABLE_C

#include "platform.h"


#include "ConfigEasyPicV7.h"

#include "ProcessGlo.h"

#include "Event.h"

//#include "uiPage.h"
////#include "uiBaseGlo.h"

#include "rs2TimerGlo.h"

// Necessari per la tabella dei processi di init
#include "rs2Timer.h"
#include "rs2Touch.h"
#include "rs2Buttons.h"
#include "rs2HW_Micro.h"
#include "rs2HW_Interrupt.h"
#include "rs2Glcd.h"
#include "rs2Lcd.h"

#include "uiBase.h"
//#include "uiPage.h"

#include "Test.h"


// ----------------------------------------------------------------------------
// SECTION - SYSTEM INCLUDE

// SECTION END
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// SECTION - PROJECT INCLUDE (Dependecies)

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



_ROM ProcessStruct ProcessTable[NUMBER_PROCESS] = {
//   {ControlloTimer0     ,EventTimer    ,TMR_NUMBER},      // PROCESS_TIMER        0
//   {ControlloButtons    ,uiPageEvent   ,1}                // PROCESS_BUTTONS      1
   {ControlloTimer0     ,EventTimerMatrix       ,TMR_NUMBER},      // PROCESS_TIMER        0
   {ControlloButtons    ,ButtonsEventMatrix     ,1}                // PROCESS_BUTTONS      1
};                                                        // NUMBER_PROCESS       2


_ROM EventTableDef ProcessInitTable[NUMERO_EVENTI_INIT] = {
   
   InitTimer,                 // init System Timer
   InitButtons,               // init Buttons pin ports
   InitMicro,                 // init Hardware Micro
#ifdef _CONFIG_EASY_PIC_V7_GRAPHIC_LCD
   glcdInitPorts,             // init port about Graphic LCD
#ifdef _CONFIG_EASY_PIC_V7_TOUCH
   touchInit,                 // init port about touch
#endif   // _CONFIG_TOUCH   
#endif   // _CONFIG_GRAPHIC_LCD
   InitInterruptTimer,        // init Interrupt Timer
#ifdef _CONFIG_EASY_PIC_V7_LCD
   LcdInit,                   // init LCD
#endif
   uiBaseInitCold,
   TestInit                  // visualizza la versione firmware
   
};

//void EventTest (void)
//{
//   ProcessTable[1].EventTable = EventTimer;
////   EventTableTest[3] = PtrFunzioneTest;
//}
