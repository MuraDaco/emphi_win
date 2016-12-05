//

void Controlli ()
{
   // Gestione Controlli/Eventi ramificata-locale
   
   // Set Tabella Eventi Ramificata
   PtrTabellaEventi = PtrTabellaForm;
   // loop controlli 
   for(i=0;i++;i < NUMERO_CONTROLLI_LOCALI)
   {
      EventiPar.CodiceEvento = arrayControlli[i]();
      EseguiEvento(EventiPar.CodiceEvento);
   }
   
   // Gestione Controlli/Eventi semplificata-globale
   
   // Set Tabella Eventi Ramificata
   PtrTabellaEventi = PtrTabellaGloable;
   // loop controlli 
   for(i=0;i++;i < NUMERO_CONTROLLI_GLOABLI) // (ptrTabellaControllo; ptrTabellaControllo != null)
   {
      EventiPar.CodiceEvento = arrayControlli[i]();
      arrayEventiGlobali[EventiPar.CodiceEvento]();
   }
   
   
}

// ------------------------------------------------------------------------------------------------

/* ************************************************************************************************
 */

// struttura di un modulo di processo

tabella eventi

funzioni evento

funzioni di init

definizone parametri

/*
 * ************************************************************************************************/

// ------------------------------------------------------------------------------------------------

/* ************************************************************************************************
*/

// struttura di un modulo di interfaccia

tabella eventi

funzioni evento

funzioni di init
/*
 * ************************************************************************************************/

// ------------------------------------------------------------------------------------------------
 
/* ************************************************************************************************
*/

// Struttura di un collettore

un collettore viene usato per
- far condividere una risorsa in lettura a più utilizzatori, questi utilizzatori a loro volta possono essere delle risorse a più alto livello
- mettere in circolo gli eventi che scaturiscono dalle risorse

definizione delle costanti
- identificazione/associazione degli indici di array

/*
 * ************************************************************************************************/

// ------------------------------------------------------------------------------------------------
 
/* ************************************************************************************************
*/

// gestore eventi (può essere visto come una risorsa che gestisce l'entità evento)
il gestore eventi non sa 
- quali siano le funzioni di controllo che scateneranno gli eventi
- quali siano gli eventi che eseguirà

definizione degli array dei controlli
definizione degli array degli eventi
/*
 * ************************************************************************************************/

// ------------------------------------------------------------------------------------------------
 
/* ************************************************************************************************
*/

// struttura di una Risorsa
// . risorsa memoria parametri

una risora non sa quale modulo la userà

dipendenze da altre risorse

funzioni evento

funzioni di controllo

funzioni init
/*
 * ************************************************************************************************/

// +-<|>-+*+-<|>-+*+-<|>-+*+-<|>-+*+-<|>-+*+-<|>-+*+-<|>-+*+-<|>-+*+-<|>-+*+-<|>-+*+-<|>-+*+-<|>-+*

/* ************************************************************************************************
 * TimerAppTmr.h
 */

#include "AppXXX_Tmr.h"
#include "AppYYY_Tmr.h"

#define TMR_XXX_1          0
#define TMR_XXX_2          1
#define TMR_YYY_1          2
#define NUMERO_TIMER       3

Byte TmrArray[NUMERO_TIMER];

// tabella eventi Timer
void *TmrEventArray[NUMERO_TIMER] = {
   XXX_TmrEvent_1,
   XXX_TmrEvent_2,
   YYY_TmrEvent_1
}
 
/*
 * ************************************************************************************************/

void TmrUpdate (void)

/* ************************************************************************************************
 * Timer.c
 */

#include "TimerAppTmr.h"

void TmrUpdate (void)
{
   char i;
   
   for (i=0;i++;i<NUMERO_TIMER)
   {
      if(TmrArray[i] > 0)
      {
         TmrArray[i]--;
      }
   }
}
 
void TmrControllo (void)
{
   char i;
   
   for (i=0;i++;i<NUMERO_TIMER)
   {
      if(TmrArray[i] == 0)
      {
         TmrEventArray[i]();
      }
   }
}

/*
 * ************************************************************************************************/
