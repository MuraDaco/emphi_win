/*

   MODULE DESCRIPTION:  

   AUTHOR:  Marco Ing. Dau		 																									

   ****************************************************************************************************************************************************
   * SVN-keywords: fields managed by SVN - DO NOT MODIFY 
   *
   *	USER who run commit:    $Author: Administrator $																										
   *	REVISION NUMBER:        $Revision: 344 $																											
   *	LAST DATE REVISION:     $Date: 2016-03-01 17:27:34 +0100 (mar, 01 mar 2016) $															
   *	LOCATION FILE:          $HeadURL: file:///C:/Users/Administrator/Documents/SVN/Repository/fw2/15101-emphil/work/rs2Buttons.c $			
   *																																						
   ****************************************************************************************************************************************************

 */

#define _BUTTONS_C

#include "platform.h"

#include "..\dntButtonsGlo.h"

// ----------------------------------------------------------------------------
// SECTION - SYSTEM INCLUDE

// SECTION END
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// SECTION - PROJECT INCLUDE (Dependecies)

#include "EventGlo.h"

#include "rs2TimerGlo.h"
#include "rs2ButtonsGlo.h"




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

_ROM char ButtonsAction[BUTTONS_STATE_NUMBER][BUTTONS_EVENT_NUMBER] = {
   // NOTHING                          ,PRESS                              ,RELEASE
   // ----------------------------------------------------------------------------------------------------------------------------------------------
      BUTTONS_STATE_NO_PRESSED         ,BUTTONS_STATE_WAIT                 ,BUTTONS_STATE_NO_PRESSED     // BUTTONS_STATE_NO_PRESSED					0
     ,BUTTONS_STATE_PRESSED            ,BUTTONS_STATE_WAIT                 ,BUTTONS_STATE_NO_PRESSED     // BUTTONS_STATE_WAIT							1
     ,BUTTONS_STATE_PRESSED            ,BUTTONS_STATE_WAIT                 ,BUTTONS_STATE_NO_PRESSED     // BUTTONS_STATE_PRESSED						2
     ,BUTTONS_STATE_PRESSED_EXECUTED   ,BUTTONS_STATE_PRESSED_EXECUTED     ,BUTTONS_STATE_NO_PRESSED     // BUTTONS_STATE_PRESSED_EXECUTED			3
};



void InitButtons  (void)
{
   
   Buttons.Codice = Buttons.CodiceOld = Buttons.Stato = Buttons.Modalita = 0;
   
}

unsigned char ControlloButtons   (char i)
{
   char evento;
//   _ROM char *ptr_conversion;     // solo questa definizione occupa 16 byte di codice!!!!
   
   
   // se TastoPremuto allora
   // in base al tasto premuto ritorna l'evento associato
   if(Buttons.Stato == BUTTONS_STATE_PRESSED)
   {
      Buttons.Stato = BUTTONS_STATE_PRESSED_EXECUTED;

      
      // imposta evento
      switch (Buttons.Codice)
      {
         case CODE_BUTTONS_RIGHT:
            evento = EVENT_BUTTONS_RIGHT;
            break;
         case CODE_BUTTONS_UP:
            evento = EVENT_BUTTONS_UP;
            break;
         case CODE_BUTTONS_ENTER:
            evento = EVENT_BUTTONS_ENTER;
            break;
         case CODE_BUTTONS_DOWN:
            evento = EVENT_BUTTONS_DOWN;
            break;
         case CODE_BUTTONS_LEFT:
            evento = EVENT_BUTTONS_LEFT;
            break;   
         default:
            return 0xFF;
      }

      return evento;
      
   }
   
   return 0xFF;
}

void ButtonsTimer    (void)
{
   char evento;
   // leggi il digital input
   if(Buttons.Stato != BUTTONS_STATE_PRESSED)
   {
      Buttons.CodiceOld = Buttons.Codice;
      Buttons.Codice = dntKeyPress;
   }

	// imposta evento in base al valore appena letto
	evento = BUTTONS_EVENT_NOTHING;
   if(Buttons.Codice != Buttons.CodiceOld)
   {
		evento = BUTTONS_EVENT_RELEASE;
      if(Buttons.Codice != 0)
      {
			evento = BUTTONS_EVENT_PRESS;
		}
	}
   
   // imposta il nuovo stato in funzione dello stato corrente e dell'evento appena rilevato
	Buttons.Stato = ButtonsAction[Buttons.Stato][evento];
   
   // Completa le azioni da eseguire associate allo stato appena impostato
   if(Buttons.Stato == BUTTONS_STATE_NO_PRESSED)
   {
      Buttons.Modalita = BUTTONS_MODALITA_RIPETUTA_OFF;
   }

   if(Buttons.Stato == BUTTONS_STATE_WAIT)
   {
      Timer[TMR_BUTTONS] = _TICK_DEC_TIMER;
   }
      
   if(Buttons.Stato == BUTTONS_STATE_PRESSED)
   {
      Timer[TMR_BUTTONS] = _TICK_DEC_TIMER;
   }
   
   if(Buttons.Stato == BUTTONS_STATE_PRESSED_EXECUTED)
   {
      dntKeyPress = 0;
   }
   
}

