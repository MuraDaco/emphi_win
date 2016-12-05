/*

   MODULE DESCRIPTION:  

   AUTHOR:  Marco Ing. Dau		 																									

   ****************************************************************************************************************************************************
   * SVN-keywords: fields managed by SVN - DO NOT MODIFY 
   *
   *	USER who run commit:    $Author: Administrator $																										
   *	REVISION NUMBER:        $Revision: 344 $																											
   *	LAST DATE REVISION:     $Date: 2016-03-01 17:27:34 +0100 (mar, 01 mar 2016) $															
   *	LOCATION FILE:          $HeadURL: file:///C:/Users/Administrator/Documents/SVN/Repository/fw2/15101-emphil/work/uiPar.c $			
   *																																						
   ****************************************************************************************************************************************************

 */
 
#define _UI_PAR_C

#include "platform.h"


#include "EventGlo.h"
#include "Event.h"

#include "uiBaseGlo.h"
#include "uiParGlo.h"
#include "uiStrGlo.h"
#include "uiGeneralGlo.h"

#include "rs2Lcd.h"
#include "rs2TimerGlo.h"


_ROM ParElementoStruct   *PtrParElemento;
_ROM BaseElementoStruct  *PtrParBaseElemento;
char ParRow;
char ParCol;
char Lampeggio;



//void uiParEventNull (void)
//{
//}

void uiParTimer   (void)
{
   // aggiorna il timer
   Timer[TMR_UI_PAR] = 200;
   if(Lampeggio)
   {
      Lampeggio = 0;
      LcdRomStrRC(ParRow,ParCol,"               ");
   }
   else
   {
      Lampeggio = 1;
      LcdRomStrRC(ParRow,ParCol,StrElemento[PtrParElemento->id_label].Lang[Language]);
   }
   
}


void ValueDisplay    (void)
{
   // 1. Chiama la funzione del display alfanumerico
   LcdNumberRC(ParRow,ParCol+16,*PtrParElemento->ptr_par);
}

void LabelDisplay    (void)
{
   // 1. Chiama la funzione del display alfanumerico
   LcdRomStrRC(ParRow,ParCol,StrElemento[PtrParElemento->id_label].Lang[Language]);
}

void uiParEventButtonsUp      (void)
{
   // incementare il valore
//   *(PtrParElemento->ptr_par) = 47;
   (*PtrParElemento->ptr_par)++;

   // visualizza valore
   ValueDisplay();
}

void uiParEventButtonsDown      (void)
{
   // decementare il valore
   (*PtrParElemento->ptr_par)--;

   // visualizza valore
   ValueDisplay();
}

void uiParEventButtonsRight      (void)
{
   
}

void uiParEventButtonsLeft      (void)
{
   
}

void uiParEventButtonsEnter      (void)
{
   // riattiva la tabella eventi del elemento padre
   PtrParBaseElemento->EventOn(0xFF);
   
   Timer[TMR_UI_PAR] = 200;

}

_ROM EventTableDef uiParEvent[NUMBER_EVENT_BUTTONS] = {
    EventNull                    //    EVENT_BUTTONS_RIGHT     0
   ,uiParEventButtonsUp          //    EVENT_BUTTONS_UP        1
   ,uiParEventButtonsEnter       //    EVENT_BUTTONS_ENTER     2
   ,uiParEventButtonsDown        //    EVENT_BUTTONS_DOWN      3
   ,EventNull                    //    EVENT_BUTTONS_LEFT      4
};                               //    NUMBER_EVENT_BUTTONS    5

void uiParDeselect		(void)
{
   // disattivare il timer di lampeggio dell'etichetta
   Timer[TMR_UI_PAR] = 1;
   
   // visualizza etichetta
   LabelDisplay();
   
//   // azzera il puntatore al parametro
//   PtrParElemento = 0;
}


void uiParInitLight		(char element_id)
{
}

void uiParInitCold			(void)
{
   // disattiva il timer di lampeggio dell'etichetta
   Timer[TMR_UI_PAR] = 1;
}

void uiParEventOn	   (unsigned char father_id)
{
   PtrParBaseElemento = BaseElemento + father_id;

   uiParDeselect();
   
   // imposta tabella eventi
   ButtonsEventMatrix[0].EventTable = uiParEvent;
   
}

//void uiParSelect		(char element_id, char o_row, char o_col, char n_row)
void uiParSelect		(char element_id, BaseCoordinateStruct coordinate)
{
   // 0. iniziailizzazione delle variabili globali circoscritte al modulo
   // 0.1. impostare il puntatore al parametro
   PtrParElemento = ParElemento + element_id;
   // 0.2. imposta le coordinate
   ParRow = coordinate.o_row;
   ParCol = coordinate.o_col;
   
   // attivare il timer di lampeggio dell'etichetta
   Timer[TMR_UI_PAR] = 200;
   
}

//void uiParVisualizza		(char element_id, char o_row, char o_col, char n_row)
void uiParVisualizza		(char element_id, BaseCoordinateStruct coordinate)
{

   // 0. iniziailizzazione delle variabili globali circoscritte al modulo
   // 0.1. impostare il puntatore al parametro
   PtrParElemento = ParElemento + element_id;
   // 0.2. imposta le coordinate
   ParRow = coordinate.o_row;
   ParCol = coordinate.o_col;
//   ParRow = o_row;
//   ParCol = o_col;
   
   // 1. visualizza etichetta
   LabelDisplay();
   
   // 1. visualizza valore
   ValueDisplay();
}




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

