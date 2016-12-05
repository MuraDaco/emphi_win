/*

   MODULE DESCRIPTION:  

   AUTHOR:  Marco Ing. Dau		 																									

   ****************************************************************************************************************************************************
   * SVN-keywords: fields managed by SVN - DO NOT MODIFY 
   *
   *	USER who run commit:    $Author: Administrator $																										
   *	REVISION NUMBER:        $Revision: 344 $																											
   *	LAST DATE REVISION:     $Date: 2016-03-01 17:27:34 +0100 (mar, 01 mar 2016) $															
   *	LOCATION FILE:          $HeadURL: file:///C:/Users/Administrator/Documents/SVN/Repository/fw2/15101-emphil/work/uiBaseGlo.h $			
   *																																						
   ****************************************************************************************************************************************************

 */

#ifdef _UI_DEF_C
#define _EXTERN_UI_DEF
#else
#define _EXTERN_UI_DEF extern
#endif

#include "EventGlo.h"

#ifndef _UI_BASE_GLO_H
#define _UI_BASE_GLO_H

typedef struct {
	char o_row;
	char o_col;
	char n_row;	
} BaseCoordinateStruct;
	
typedef struct {
//	_ROM void *ptr_elemento;
//	_ROM EventTableDef *EventTable;
	void (*InitCold)		(void);
	void (*InitLight)		(char element_id);
	void (*EventOn)		(unsigned char father_id);
	void (*Visualizza)	(char element_id, BaseCoordinateStruct coordinate);
	void (*Select)			(char element_id, BaseCoordinateStruct coordinate);
//_ROM	void (*Visualizza)	(char element_id, char o_row, char o_col, char n_row);
//_ROM	void (*Select)			(char element_id, char o_row, char o_col, char n_row);
	void (*Deselect)		(void);
} BaseElementoStruct;




#ifndef _UI_BASE_C

extern _ROM BaseElementoStruct BaseElemento[];

extern _ROM uiFunction0Param BaseElemento_InitCold[]; 
extern _ROM uiFunction1Param BaseElemento_InitLight[]; 
extern _ROM uiFunction1Param BaseElemento_EventOn[]; 
extern _ROM uiFunction4Param BaseElemento_Visualizza[]; 
extern _ROM uiFunction4Param BaseElemento_Select[]; 
extern _ROM uiFunction0Param BaseElemento_Deselect[]; 


#endif

//_EXTERN_UI_DEF EventTableDef uiButtonsEvent[];
//extern _ROM EventTableDef uiPageEvent[];

#define	EL_PAGE				0
#define	EL_LBOX				1
#define	EL_PAR				2
#define	EL_VAR				3
#define	EL_STR				4
#define	EL_NUMBER			5

#define	WORD			0
#define	DIGIT_3 		0
#define	BYTE 			0
#define	DIGIT_1 		0

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

#endif		// _UI_BASE_GLO_H
