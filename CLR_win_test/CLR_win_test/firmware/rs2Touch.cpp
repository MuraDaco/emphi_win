/*
   touch.c
   
   Description / Descrizione:
   Driver to handle the resistive touch screen with 4 wire
   Driver per gestire il touch ecreen resistivo a 4 fili
	
   Documentation / Documentazione
	

   Gestione Personale
   - RC0->1 e RC1->0 ---> Read RA0
   - RC0->0 e RC1->1 ---> Read RA1
   
   Gestione MicroElektronika
   - RC0 e RC1 sempre a 0 e quindi RA0 -> 1 e RA1 -> 0
   - Periodo di 3 ms e con RC a 1 per 1ms
   
   
   Author:
   Marco Dau

   Creation Date:
   Tuesday, 17 March 2015
   
   Update:
   
   
*/

/*

   MODULE DESCRIPTION:  

   AUTHOR:  Marco Ing. Dau		 																									

   ****************************************************************************************************************************************************
   * SVN-keywords: fields managed by SVN - DO NOT MODIFY 
   *
   *	USER who run commit:    $Author: Administrator $																										
   *	REVISION NUMBER:        $Revision: 344 $																											
   *	LAST DATE REVISION:     $Date: 2016-03-01 17:27:34 +0100 (mar, 01 mar 2016) $															
   *	LOCATION FILE:          $HeadURL: file:///C:/Users/Administrator/Documents/SVN/Repository/fw2/15101-emphil/work/rs2Touch.c $			
   *																																						
   ****************************************************************************************************************************************************

 */

#define	_TOUCH_C

#include "platform.h"

#include "rs2ADC.h"
#include "rs2ADCGlo.h"
#include "rs2TouchGlo.h"
#include "rs2TimerGlo.h"



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

#define TOUCH_PHASE_0	0
#define TOUCH_PHASE_1	1
#define TOUCH_PHASE_2	2


char TouchState;
char TouchXold;
char TouchYold;



void touchInit (void)
{
}

void TouchTimer (void)
{
}

char ControlloTouch0 (char i)
{
	return 0x7F;
}

void touchCheckLoopParallel (void)
{
}
