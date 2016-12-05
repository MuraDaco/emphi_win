/*

   MODULE DESCRIPTION:  

   AUTHOR:  Marco Ing. Dau		 																									

   ****************************************************************************************************************************************************
   * SVN-keywords: fields managed by SVN - DO NOT MODIFY 
   *
   *	USER who run commit:    $Author: Administrator $																										
   *	REVISION NUMBER:        $Revision: 344 $																											
   *	LAST DATE REVISION:     $Date: 2016-03-01 17:27:34 +0100 (mar, 01 mar 2016) $															
   *	LOCATION FILE:          $HeadURL: file:///C:/Users/Administrator/Documents/SVN/Repository/fw2/15101-emphil/work/EventGlo.h $			
   *																																						
   ****************************************************************************************************************************************************

 */

#include "platform.h"

#ifndef _EVENT_GLO_H
#define _EVENT_GLO_H
 
// ----------------------------------------------------------------------------
// SECTION - SYSTEM INCLUDE
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

#define  EVENT_BUTTONS_RIGHT     		0
#define  EVENT_BUTTONS_UP        		1
#define  EVENT_BUTTONS_ENTER     		2
#define  EVENT_BUTTONS_DOWN      		3
#define  EVENT_BUTTONS_LEFT      		4
#define  NUMBER_EVENT_BUTTONS    		5

typedef void (*uiFunction0Param)(void);
typedef void (*uiFunction1Param)(char a);
typedef void (*uiFunction4Param)(char a, char b, char c, char d);

typedef void (*EventTableDef)(void);

typedef struct
{
   _ROM EventTableDef *EventTable;
} EventStructX;



#endif	// _EVENT_GLO_H

