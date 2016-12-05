// Appunti di programmazione

// modulo uiPage e suoi elementi

1. elenco funzioni legate all'inizializzazione
1.1. Pensare che ci sono più istanze associate alla pagina
1.1.1. Le istanze sono contraddistinte da
1.1.1.1. Tabella Eventi (forse questa può essere unica per tutte le istanze page)
1.1.1.2. Lista Elementi
1.2. Impostare l'istanza
1.3. Visualizzare gli elementi della lista

struct Class_Page {
	ptr_tabella_elementi
}

struct TabElementi {
	Init
	Aggiorna
	Class_elemento *ptr_istanza_elemento
}

PtrStructElemento {
	ptrValore
	nome
	TmrRefresch
	posizione, x, y
	stato: attivo, disattivo
}
PtrIstanza[]

. dell'elemento edit ci può essere solo una istanza attiva per volta
. cosa diversa per gli elementi label
. il label può essere equiparato al parametro?

. proprietà label/edit
.. nome
.. posizione, x, y
.. visualizzazione: temperatura, tensione, peso, tempo

. Proprietà parametro
.. byte, word, boolean
.. max, min (questi valori possono dipendere da altri parametri)

. InitLabel
.. posizione, x, y,
.. ptrValore
.. (nel timer vengo visualizzati i valori di tutte le label attive)
.. le istanze della label vengono disattivate tutte insieme, in questo caso non serve specificare l'indice del puntatore

. InitMenu
.. Completa la tabella eventi con le funzioni evento del padre per i posti lasciati nulli 
.. la particolarità di questa soluzione (molto elegante perche demanda all'elemento attivato la gestione degli eventi del padre)
   è che la tabella eventi deve risiedere in memopria RAM (non ROM) e quindi costringe tutte le altre tabelle eventi 
	a risiedere in memoria RAM è anche vero però che 
	a questo fatto però si può ovviare con delle funzioni evento che richiamano quelle del padre evitando anche la inizializzazione
	in questo caso però si consuma spazio nello stack quando vengono chiamati gli eventi del padre, am questo non è un problema
	infatti al massimo ci saranno tre livelli di annidamento di elementi
	page->menu->edit

ElementoMenu {
	riga_start, riga_stop
	lista_elementi
}

TabellaPageElementi[] = {
	{"Edit 01"	,PAR_1	,ROW_1	,COLUMN_02	,WIDTH_4	,EditInit(EventiPadre)	,EditSetOn()},
	{"Edit 02"	,PAR_2	,ROW_2	,COLUMN_10	,WIDTH_6	,EditInit(EventiPadre)	,EditSetOn()},
	{"Labe 01"	,VAR_1	,ROW_4	,COLUMN_05	,WIDTH_3	,LabelInit(EventiPadre)	,NULL			},
	{"Labe 02"	,VAR_2	,ROW_4	,COLUMN_10	,WIDTH_3	,LabelInit(EventiPadre)	,NULL			}
};

TabellaPageElementi[] = {
	{(char)&PtrIstanzaEdit[EDIT_1]		,EditInit(EventiPadre	,(char)&PtrIstanzaEdit)		,EditSetOn(EDIT_1)	},
	{(char)&PtrIstanzaEdit[EDIT_2]		,EditInit(EventiPadre	,(char)&PtrIstanzaEdit)		,EditSetOn(EDIT_2)	},
	{(char)&PtrIstanzaLabel[LABEL_1]		,LabelInit(EventiPadre	,(char)&PtrIstanzaLabel)	,NULL						},
	{(char)&PtrIstanzaLabel[LABEL_2]		,LabelInit(EventiPadre	,(char)&PtrIstanzaLabel)	,NULL						},
	{(char)&PtrIstanzaMenu[MENU_1]		,MenuInit(EventiPadre	,(char)&PtrIstanzaMenu)		,MenuSetOn(MENU_1)	},
	{(char)&PtrIstanzaMenu[MENU_2]		,MenuInit(EventiPadre	,(char)&PtrIstanzaMenu)		,MenuSetOn(MENU_2)	}
};

PtrIstanzaEdit[] = {
	{"Edit 01"	,(char)&TabellaParametri[PAR_1]	,ROW_1	,COLUMN_02	,WIDTH_4 },		// EDIT_1		0
	{"Edit 02"	,(char)&TabellaParametri[PAR_2]	,ROW_2	,COLUMN_10	,WIDTH_6	}		// EDIT_2		1
};

PtrIstanzaLabel[] = {
	{"Labe 01"	,VAR_1	,ROW_4	,COLUMN_05	,WIDTH_3	},		// LABEL_1		0
	{"Labe 02"	,VAR_2	,ROW_4	,COLUMN_10	,WIDTH_3	}     // LABEL_2		1
};

PtrIstanzaLabel[] = {
	{"Labe 01"	,VAR_1	,ROW_4	,COLUMN_05	,WIDTH_3	},		// LABEL_1		0
	{"Labe 02"	,VAR_2	,ROW_4	,COLUMN_10	,WIDTH_3	}     // LABEL_2		1
};

TabellaParametri[] = {
	{"Setpoint: "	,&SetPoint	,Min	,Max	,WORD	,DIGIT_3	,DisplayTemperatura},
	{"Delta:    "	,&Delta		,Min	,Max	,WORD	,DIGIT_3	,DisplayTemperatura}
}



uiPage <--------- uiAppPage.h (Definizione strutture TabellaPageElementi)
uiPageTable <---+ uiAppPage.h (Definizione strutture TabellaPageElementi)
                + ModuloTermostato (FORSE NON necessario (BASTA IL MODULO PAR) per visualizzare le variabili di stato del modulo termostato)
					 + ModuloPar
					 
All'interfaccia utente e quindi al modulo uiPageTable non interessa l'esistenza dei moduli funzionali come il modulo Termostato
per visualizzare/modificare i parametri dei vari moduli gli basta conoscere la tabella dei parametri

Parimenti ai moduli funzionali come il modulo termostato interessa solo usare i parametri e quindi le informazioni
sui parametri contenuti nella omonima tabella gli possono tranquillamente essere estranei					 
quindi non devo dipendere dall'include del modulo parametri

I moduli Label e Edit invece devono dipendere dal modulo Par sia per la visulaizzazione ma anche per la eventuale modifica

Riassumendo 
1. i moduli funzionali possono considerarsi indipendenti dai moduli interfaccia,
2. l'unione tra le due classi di moduli avviene attraverso la tabella dei parametri e delle variabili di stato
2.1. i moduli interfaccia dipendono dal modulo Par e Var
2.2. la relazione dei moduli funzionali con il modulo par può avvenire in due modi diversi a cui corrispondono rapporti di dipendenza invertiti
2.2.1. Modo 1: 
2.2.1.1. si crea un array di parametri (stessa cosa per l'array delle variabili di stato) nel modulo par 
2.2.1.2. i moduli funzionali avranno l'include del modulo Par e gestiranno i loro parametri come elementi di array
2.2.2. Modo 2: 
2.2.2.1. ciascun modulo definisce le sue variabili (che saranno extern e verranno realmente definite nel modulo Def)
2.2.2.2. Il modulo par dipenderà da tutti i moduli funzionali e inserirà nella sua tabella i puntatori delle variabili
         che rappresentano i parametri
2.2.2.3. Si fa notare che il moduli funzionali non dipenderanno dal modulo Par			
2.2.3. Differenze tra (Modo 1) e (Modo 2):
2.2.3.1. Il modo 1 probabilmente conusma meno memoria infatti il puntatore alle variabili consuma già due byte, tuttavia
		   bisogna dire che l'utilizzo delle variabili direttamente consuma meno memoria rispetto all'utilizzo di elementi di array
2.2.3.2. Il modo 2 credo sia più facilmente automatizzabile
2.2.3.3. in ogni caso in entrambe i modi c'è bisogno di una fase di identificazione dei parametri e per questa fase certamente
			la modalità 1 è più semplice da usare ed implementare dal momento che si ha un indirizzamento diretto ai parametri
			tuttavia l'uso dei parametri è più elaborato
2.2.3.4. Certamente la modalità 1 è più adatta per una futura gestione dei moduli di interfaccia remotizzati (via Seriale)
			infatti in questa modalità  l'allocazione di memoria corrisponde all'indice del parametro
			NON SAREBBE PROPRIO VERO QUANTO DETTO PERò!



classTermostato <-----
IstanzaTermostato <--- (associazione tra (din, ain, dout, aout reali) e (ingressi e aout del modulo))

{DIN_1	,DIN_TERMOSTATO	}	->	
{AIN_1	,AIN_TERMOSTATO	}	-> EventoSopra(la temperatura letta è maggiore del setpoint), EventoSotto
{DOUT_1	,DOUT_TERMOSTATO	}	-> EventoOutTermostato

Tabella delle associazioni degli ingressi fisici con ingressi moduli
Tabella delle associazioni degli ingressi/uscite intermedie con ingressi/uscite dei moduli
Tabella delle associazioni delle uscite fisiche con le uscite dei moduli

// istanze parametri da inserire nella corrispondente tabella generale
	{"Setpoint: "	,&SetPoint	,Min	,Max	,WORD	,DIGIT_3	,DisplayTemperatura},
	{"Delta:    "	,&Delta		,Min	,Max	,WORD	,DIGIT_3	,DisplayTemperatura}

// istanze parametri da inserire nella corrispondente tabella generale
IstanzaParametri
//																		Nome[n]			,ptr_parametro		,Default 			,Min		,Max		,sizeof()					,FLAG1		,FLAG2 ---> PAR_ID_<modulo>_<nome variabile>
#define	PAR_INSTANCE_TERMODSTATO_SETPOINT			{"Setpoint:     "	,&SetPoint			,defSetPoint		,Min		,Max		,sizeof(Setpoint)			,WORD			,DIGIT_3		}		//	PAR_ID_TERMODSTATO_SETPOINT		0
#define	PAR_INSTANCE_TERMODSTATO_DELTA				{"Delta:        "	,&Delta				,defDelta			,Min		,Max		,sizeof(Delta)				,WORD			,DIGIT_3		}		//	PAR_ID_TERMODSTATO_DELTA			1
#define	PAR_INSTANCE_TERMODSTATO_SETPOINT_MIN		{"Setpoint min: "	,&SetPointMin		,defSetPointMin	,Min		,Max		,sizeof(SetPointMin)		,WORD			,DIGIT_3		}		//	PAR_ID_TERMODSTATO_SETPOINT_MIN	2
#define	PAR_INSTANCE_TERMODSTATO_SETPOINT_MAX		{"Setpoint max: "	,&SetPointMax		,defSetPointMax	,Min		,Max		,sizeof(SetPointMax)		,WORD			,DIGIT_3		}		//	PAR_ID_TERMODSTATO_SETPOINT_MAX	3
#define	PAR_INSTANCE_TEMPO_DURATA						{"Setpoint max: "	,&SetPointMax		,defSetPointMax	,Min		,Max		,sizeof(SetPointMax)		,WORD			,DIGIT_3		}		//	PAR_ID_TEMPO_DURATA					4

IstanzaParametriLimiti	
//	 																	ptr_parametro		,ptr_limit_inf		,ptr_limit_sup		
#define PAR_INSTANCE_LIMIT_TERMODSTATO_SETPOINT			{&SetPoint			,&SetpointMin		,&SetpointMax	}
#define PAR_INSTANCE_LIMIT_TERMODSTATO_SETPOINT_MIN	{&SetPointMin	 	,NULL					,&Setpoint		}
#define PAR_INSTANCE_LIMIT_TERMODSTATO_SETPOINT_MAX	{&SetPointMax	 	,&Setpoint			,NULL				}

// locazione di memoria dei parametri nella eeprom
Si possono usare due modi:
1. calcolo runtime della locazione di memoria
2. impostazione statica della locazione di memeoria

	
#define	PAR_FLAG1_TYPE_TIME						0x00
#define	PAR_FLAG1_TYPE_BYTE						0x01
#define	PAR_FLAG1_TYPE_WORD						0x02	
#define	PAR_FLAG1_TYPE_MASK						0x03	
#define	PAR_FLAG1_TYPE_SHIFT						0	
															
#define	PAR_FLAG1_DISPLAY_NONE					0x00
#define	PAR_FLAG1_DISPLAY_BOOLEAN				0x04
#define	PAR_FLAG1_DISPLAY_TEMPER				0x08
#define	PAR_FLAG1_DISPLAY_HUMIDITY				0x0C
#define	PAR_FLAG1_DISPLAY_MASK					0x0C
#define	PAR_FLAG1_DISPLAY_SHIFT					2
															
#define	PAR_FLAG1_NUMBER_DIGIT_1				0x00
#define	PAR_FLAG1_NUMBER_DIGIT_2				0x10
#define	PAR_FLAG1_NUMBER_DIGIT_3				0x20
#define	PAR_FLAG1_NUMBER_DIGIT_4				0x30
#define	PAR_FLAG1_NUMBER_DIGIT_5				0x40
#define	PAR_FLAG1_NUMBER_DIGIT_STR				0x50
#define	PAR_FLAG1_NUMBER_DIGIT_MASK			0x70
#define	PAR_FLAG1_NUMBER_DIGIT_SHIFT			4
															
#define	PAR_FLAG1_VARIABLE_LIMIT_NO			0x00
#define	PAR_FLAG1_VARIABLE_LIMIT_YES			0x80
#define	PAR_FLAG1_VARIABLE_LIMIT_MASK			0x80
#define	PAR_FLAG1_VARIABLE_LIMIT_SHIFT		7

#define	PAR_FLAG2_SIGNED_NO						0x00
#define	PAR_FLAG2_SIGNED_YES						0x01
#define	PAR_FLAG2_SIGNED_MASK					0x01



/* test uso include	*/

// InstParTermostato.h

// istanze parametri da inserire nella corrispondente tabella generale
	{4	,5	,6	,7	,&test_disp},
	{4	,5	,6	,7	,&test_disp}

// ParTable.c

char test_disp;

typedef struct {
   char min;
   char max;
   char tipo;
   char digit;
   char *display;
   
} Parametri;

Parametri   TabellaParametri[] = {

#include "InstParTermostato.h"


};	
	
/*	fine  test uso include */


/* inizio Test - Questo test è funzionante */

// InstParTermostato.h

// istanze parametri da inserire nella corrispondente tabella generale
	{4	,5	,6	,7	,&test_disp},
	{4	,5	,6	,7	,&test_disp}

// InstParTermostato2.h

// istanze parametri da inserire nella corrispondente tabella generale
#define	INST_MODULO_TEST_1		{4	,5	,6	,7	,&test_disp},
#define	INST_MODULO_TEST_2		{4	,5	,6	,7	,&test_disp},


// ParTable.c

#include "InstParTermostato2.h"


char test_disp;

typedef struct {
   char min;
   char max;
   char tipo;
   char digit;
   char *display;
   
} Parametri;

Parametri   TabellaParametri[] = {

INST_MODULO_TEST_1
INST_MODULO_TEST_2
#include "InstParTermostato.h"

};	
	



/*  fine Test */

/* inizio	analisi dipendenze */

Modulo 
. uiGeneral
.. gestione delle funzioni dei moduli con la tabella corrispondente
... Init, Abilitazione, Visualizzazione
... dipende da tutti i mdouli: uiPage.h, uiLbox.h, uiPar.h, uiVar.h
. uiTabFunction.c con relativa uiTabFunction.h
... dipende dai moduli ui e definisce la tabella 
. uiPage
... dipende da uiTabFunction.h per poter usare la tabella delle funzioni degli elementi
.... quindi la conoscenza degli altri moduli avviene in modo indiretto (NO)
.... in teroria non servirebbe consocere l'esistenza degli altri moduli è sufficente conoscere la conoscenza della tabella delle funzioni
     quindi è sufficente la definizione extern come ad esempio nel modulo dei timer
. uiLbox
... dipende da uiGeneral.h per poter usare la tabella delle funzioni degli elementi
. uiPar
.. Byte
.. Word
.. Temperatura
. uiVar
.. Byte
.. Word
.. Temperatura

NOTARE COME CON L'UTILIZZO DELLA TABELLA DELLE FUNZIONI I MODULI PAGE E LBOX CHE CONTENGONO ELEMENTI DI VARI MODULI
NON HANNO LA NECSSITA DI CONOSCERE GLI ALTRI MODULI

il modulo applicativo sarà
. uiApplication.c
.. in questo modulo vengono implementate le tabelle dei moduli, con la particolarità che le righe dei moduli Par e Var vengono definite 
   nei moduli funzionali in cui i parametri e le variabili di stato vengono usate 

. uiTabFunction.c (usa ui<Moduli>.h) e uiAppTabFunction.h (contenente la definizione extern della tabella delle funzioni e usato dai moduli ui<Moduli>.c) 
. uiPage.c (usa uiAppTabFunction.h), 
.. uiPageGlo.h (definizione funzioni e tabella Elemento e ListaElementi; usato da uiApplication.c) 
.. uiPage.h (definizione funzioni; usato da uiTabFunction.c)
. uiLbox.c (usa uiAppTabFunction.h) e 
.. uiLboxGlo.h ( definizione funzioni e tabella Elemento e ListaElementi; usato da uiTabFunction.c e uiApplication.c)
.. uiLbox.h ( definizione funzioni e tabella Elemento e ListaElementi; usato da uiTabFunction.c e uiApplication.c)
. uiPar.c (usa uiAppTabFunction.h) e uiPar.h ( definizione funzioni e tabella Elemento; usato da uiTabFunction.c e uiApplication.c)
. uiVar.c (usa uiAppTabFunction.h) e uiVar.h ( definizione funzioni e tabella Elemento; usato da uiTabFunction.c e uiApplication.c)

. uiApplication.c (usa ui<Moduli>.h in particolare servono le definizioni della struttura delle tabelle per poterle definire)

/* fine		analisi dipendenze */


/* inizio appunti sui moduli Par, Var, Lbox e Page	*/

PtrIstanzaEdit[] = {
	{"Edit 01"	,(char)&IstanzaParametri[PAR_1]	,ROW_1	,COLUMN_02	,WIDTH_4 },		// EDIT_1		0
	{"Edit 02"	,(char)&IstanzaParametri[PAR_2]	,ROW_2	,COLUMN_10	,WIDTH_6	}		// EDIT_2		1
};

// Etichetta	,Posizione	,dimensioni		,IstanzaParametro/IdParametro		,ptr_parametro
nella struttura edit box Istanza Parametro potrebbe essere una variabile e quindi si avrebbe solo tre istanze di editbox

oppure usare il modulo menu o page dove inserire le istanze editbox

menu e page hanno la caratteristica di avere una lista elementi
nel caso menu gli elementi sono tutti editbox mentre per page gli elementi sono vari ma tutti all'interno della pagina


1. Il modulo interfaccia EdiBox deve dipendere dal modulo Par in particolare deve conoscere la struttura delle istanza dei parametri

PagetStructElemento	PageElemento[NUNERO_PAGE_ELEMENTI] = {
	//	Titolo			,Id_Start_lista_elementi				,numero_elementi		,IdPageNext
	{	"Home       "	,ID_START_ELEMENT_PAGE_HOME			,ELEMENTI_4				,ID_PAGE_SETTINGS_A},	//	ID_PAGE_HOME				0
	{	"Settings A:"	,ID_START_ELEMENT_PAGE_SETTINGS_A	,ELEMENTI_2				,ID_PAGE_SETTINGS_B},	//	ID_PAGE_SETTINGS_A		1
	{	"Settings B:"	,ID_START_ELEMENT_PAGE_SETTINGS_B	,ELEMENTI_4				,ID_PAGE_INFO},			//	ID_PAGE_SETTINGS_B		2
	{	"Info      :"	,ID_START_ELEMENT_PAGE_INFO			,ELEMENTI_3				,ID_PAGE_HOME}				//	ID_PAGE_INFO				3
};

LboxStructElemento LboxElemento[NUMERO_LBOX_ELEMENTI] = {
	//	,dimensione (numero righe)	,Id_Start_lista_elementi					,numero_elementi
	{	N_ROW_2							,ID_START_ELEMENT_LBOX_TST_1				,4	},	//	ID_LBOX_TST_1						0
	{	N_ROW_1							,ID_START_ELEMENT_LBOX_TST_2				,1	},	//	ID_LBOX_TST_2						1
	{	N_ROW_2							,ID_START_ELEMENT_LBOX_SETTINGS_A		,1	},	//	ID_LBOX_SETTINGS_A				3
	{	N_ROW_2							,ID_START_ELEMENT_LBOX_SETTINGS_B		,1	},	//	ID_LBOX_SETTINGS_B				4
};

char*	StrElemento[NUMERO_STR_ELEMENTI] = {
	"  www.emphil.org   ",
	"  info@emphil.org  ",
	"cell. xxx-aa.bb.ccc"
}

PageStructListaElementi	PageListaElementi[NUMERO_PAGE_LISTA_ELEMENTI] = {
	//	IdIstanzaElemento					,TipoElemento	,Pos:Row			,Pos:Column		Dim:Width		
// START ELEMENTI PAGE_HOME         
	{	ID_LBOX_TST_1						,EL_LBOX			,ROW_2			,COLUMN_00		,N_COLUMN_00	},
	{	ID_LBOX_TST_2						,EL_LBOX			,ROW_3			,COLUMN_00		,N_COLUMN_00	},
	{	ID_PAR_SETPOINT					,EL_PAR			,ROW_4			,COLUMN_00		,N_COLUMN_00	},
	{	ID_VAR_TEMPERATURA				,EL_VAR			,ROW_4			,COLUMN_10		,N_COLUMN_00	}
// START ELEMENTI PAGE_SETTINGS_A   	
	{	ID_LBOX_SETTINGS_A				,EL_LBOX			,ROW_2			,COLUMN_00		,N_COLUMN_00	},
// START ELEMENTI PAGE_SETTINGS_B   	
	{	ID_LBOX_SETTINGS_B				,EL_LBOX			,ROW_2			,COLUMN_00		,N_COLUMN_00	},
// START ELEMENTI PAGE_INFO
	{	ID_STR_WEB_SITE					,EL_STR			,ROW_2			,COLUMN_00		,N_COLUMN_00	},
	{	ID_STR_E_MAIL						,EL_STR			,ROW_3			,COLUMN_00		,N_COLUMN_00	},
	{	ID_STR_PHONE						,EL_STR			,ROW_4			,COLUMN_00		,N_COLUMN_00	},
};

LboxStructListaElementi LboxListaElementi[NUMERO_LBOX_LISTA_ELEMENTI] = {
	// IdParametro					,TipoElemento (Label, EditBox)
	{	ID_PAR_SETPOINT			,EL_PAR},
	{	ID_PAR_SETPOINT_MIN		,EL_PAR},
	{	ID_PAR_SETPOINT_MAX		,EL_PAR},
	{	ID_VAR_TEMPERATURA		,EL_VAR},
	{	ID_VAR_UMIDITA				,EL_VAR},
	{	ID_LBOX_TEMPO_DURATA		,EL_LBOX},	// gestisce il parametro tempo hh:mm:ss come se fosse una lista di tre elementi distinti
														// tuttavia mancano le coordinate di posizione (forse no! in questa lista le coordinate di posizione
														// sono variabili)
	{	ID_PAR_TEMPO_ORE			,EL_PAR},
	{	ID_PAR_TEMPO_MINUTI		,EL_PAR},
	{	ID_PAR_TEMPO_SECONDI		,EL_PAR},
}

// questa tabella deve essere presente nel modulo Page non deve vedersi nel modulo di applicazioni
FunzioniElemento = {
	// Istanza							,InitCold			,Initlight				,SetState(solo visualizzazione, attivazione tabella eventi, cancella, disabilita)
	{	(char *) PageElemento		,PageInit			,PageInitLight			,PageSetState		},
	{	(char *) LboxElemento		,LboxInit			,LboxInitLight			,LboxSetState		},
	{	(char *) ParElemento			,uiParInitCold				,uiParInitLight			,ParSetState		},
	{	(char *) VarElemento			,uiVarInitCold				,uiVarInitLight			,VarSetState		},
};



/* fine appunti sui moduli Par, Var, Lbox e Page		*/



. le tabelle elementi e istanze si devono trovare in un file di applicazione
.. uiPageTable dovra essere un file dipendente dall'applicazione
.. ci dovrà essere un file

InitPage {
	for(listaelementi) {
		InitElemento	// qui verranno visualizzati tutti gli elementi ma questo non significa che verranno attivati
							// qui verranno chiamate tutte le funzioni Init dei vari elementi
							// i parametri passati saranno
							// nome (se presente)
							// posizione
							// numero di istanza (se ci sono più istanze attive di una stessa classe di elemento)
							// puntatore alla propria tabella eventi, questa all'elemento figlio servirà per
							// . eseguire eventi non presenti nella propria tabella eventi
							// . restituire il comando al padre
	}
	AttivaElemento {
						// azione eseguita in funzione della tabella degli elementi
						// attivazione significa attivare la tabella eventi del'elemento prescelto
						// l'elemento prescelto può essere l'unico presente nella lista degli elementi oppure
						// l'elemento selezionato
						// e quindi il moddulo page deve gestire anche la selezione degli elementi					
			
	}
	
}

EventoPage Right/Left {
	
}

1. elenco funzioni legate agli eventi
1.1. scorrere elementi presenti nella pagina
1.2. selezionare l'elemento
1.2.1. passare la gestione eventi all'elemento selezionato
1.2.2. trasmettere il proprio puntatore per quando l'elemento cede il controllo a colui che lo ha attivato
1.3. passare il controllo alla pagina successiva
1.3.1. questo può avvenire in modo semplice con una sequenza circolare o lineare, oppure
1.3.2. utilizzando una tabella di transizioni


// tabella eventi dinamici
. per gestire l'interfaccia utente oppure anche applicazioni tipo PLC è necessario usare array eventi dinamici
.. ciò significa che il puntatore alla tabella eventi sara presente in una variabile e non sarà direttamente una tabella eventi

typedef void (*EventTable)(void);
EventTabel *PtrTabellaEventi

ora ci sono alcuni fatti da tener presenti
. quando viene eseguito un evento inizia una "catena di esecuzioni" nel senso che la funzione evento può passare l'evento ad un'altra tabella eventi
.. quindi l'esecuzione di questo evento termierà quando eseguita una funzione evento la variabile PtrTabellaEventi rimarrà immutata

. Ci può essere la necessità che uno stesso evento debba essere trasmesso a più tabelle eventi dinamiche
.. per fare un esempio di quando si possa verificare questa necessità
... 1. si hanno più display e li si vogliono gestire in modo indipendente l'uno dall'alto
... 2. una tabella eventi per gli eventi da tastiera legati alle tabelle eventi dei moduli interfaccia utente
       una tabella eventi per gli eventi da Digital/analog Input per applicazioni PLC
... Notare come la gestione dinamica delle tabelle eventi si addica ad applicazioni associabili ad automi a stato finito in cui lo stato 
    può essere rappresentato dalla tabella eventi corrispondente

. istanze
. il moduloStatoAtm A cui è associata la TabellaEventi attiva se vuole "passare" l'evento al moduloStatoAtm B deve conoscere la tabella evento ad esso associata
.. gli automi possono avere stati, sub.stati, sub.sub.stati e così via

. per uno stesso moduloStatoAtm possono essere associate più tabelle evento ovvero ad uno stesso moduloStatoAtm possono essere associate più istanze
.. quindi si dovranno gestire 

. ogni moduloStatoAtm sarà caratterizzato da
.. una funzione di iniziailizzazione
... questa funzione di inizializzazione verrà chiamata
.... 1. fase iniziale del main oppure
.... 2. dal modulo da cui ottiene l'evento
.. una tabella_eventi
... notare che: gli eventi saranno intirnseci al modulo oppure dipenederanno dalla applicazione

. rammentare che gli stati dell'automa sono i moduloStatoAtm mentre l'automa è rappresentato dal modluloAutoma
.. il moduloAutoma caratterizza l'applicazione ed è caratterizzato da
... 1. lista degli stati (moduliStatoAtm)
... 2. link tra gli stati
.. i moduliStatoAtm sono dei moduli generici per essere più precisi sono caratterizzati da funzioni 
... 1. che gestiscono elementi attraverso i loro puntatori
... 2. da definirsi al momento della creazione del moduloAutoma
.. notare che i moduliStatoAtm possono loro stessi essere dei ModuliAutoma
... quindi ci possono essere più livelli di PtrTabellaEventiAttiva

. il moduloStatoAtm deve avere una funzione per il cambiamento di stato, naturalmente questa funzione sarà una funzione virtuale
  da implementare al momento della definizione del ModuloAutoma
. i moduliStatoAtm possono avere varie implementazioni generiche 
 

do
{
	ptr_tabella_eventi = PtrTabellaEventi(attiva)
	esegui evento
} while (ptr_tabella_eventi != PtrTabellaEventi(attiva))

// situazione 1: singolo evento verso più tabelle_evento	
								+----->	(TabellaEvento A) Es. Interfaccia Utente
								|
	(OrigineEvento 1) ---+
	Es. Tasteira			|
	o Dig. Input			+----->	(TabellaEvento B) Es. Applicazione PLC

// situazione 2: più eventi verso singola tabella_evento	
	(OrigineEvento 1)	---+	
	Es. Tasteira			|
								+--->	(TabellaEvento A) Es. Interfaccia Utente oppure Applicazione PLC
								|
	(OrigineEvento 2) ---+
	Es. Digital Input
	
	for(i=0;i<ORIGINE_EVENTO_NUMERO;i++)
	{
		OrigineEvento(i);
		for(j=0;j<GESTORE_EVENTO_NUMERO;j++)
		{
			GestoreEvento(i);
		}
	}
							

// generatori di eventi
.di seguito un elenco di esempio
.. timer, buttons, touch pannel, adc, etc

. gli eventi possono essere gestiti in modo diverso ad esempio un evento timer sarà gestito in modo diverso da un evento tastiera

. un singolo evento può essere elaborato da più gestori

. funzione controllaEvento -> imposta una struttura dati che verrà letta da tutti i gestori evento
.. ad esempio i gestori evento possono essere timer e interfaccia

// utilizzo degli include per i file di intestazione .h
// i file di intestazione hanno il nome cpstituito come segue
// <nome Modulo>.h oppure <nome Modulo><App>.h

. la differenza tra i file .h "App" e "non App" è che
.. il file "non App" vengono usati da moduli all'insaputa del file c associato
.. ovvero il file c associato non sa e non conosce i suoi utilizzatori, in questo caso viene da se che non c'è
   nessuna variabile condivisa tra i moduli
.. i files "App" identificano la presenza di un collettore ovvero una presenza di una dipendenza indiretta  tra i moduli
   che tipicamente si esplica con la condivisione di variabili
... si vuole evidenziare poi che tali variabili saranno delle varibaili globali e quindi soggette alla define "_EXTERN_DEF"
.... in questo caso tutti i file "App" che hanno variabili globali devono avere le seguenti righe di define all'inizio del file
#ifdef _DEF_C
#define _EXTERN_DEF
#else
#define _EXTERN_DEF extern
#endif
.... notare che define _EXTERN è stata completata con il postfisso DEF che ha lo scopo di indicare il modulo in cui effettivamente 
     tali variabili globali verranno definite; viene da se che posso usare più file dove definire le variabili globali, al momento credo sia
	  conveniente usare un unico file 


. il file A.c chiama un file B.h
.. significa che ci  sarà una dipendenza diretta di quel modulo sul modulo.h (caso del modulo Test con il modulo Glcd)
.. o una dipendenza indiretta del B.c sul modulo A.c (caso del modulo main.c con rs2Timer.h, ed altri) 

. il file A.c chiama un file AppB.h
.. dipendenza indiretta del modulo A sul modulo B (ad esempio il modulo timer che condivide con altri moduli gli elementi degli array deii timer)

. i file <nome modulo><App>.h non dovrebbero chiamare altri file 

. Anche i file <modulo>.h non dovrebbero chiamare alcun file.h
.. ha lo scopo di rendere disponibile le intestazioni di alcune funzioni per un utilizzo diretto o indiretto
.. i file <Modulo.h> non vengono chiamati dal loro corrispettivo <Modulo>.c
.. fa eccezione il modulo
... "Event"
... nel caso del moculo "Event" sarebbe più corretto usare un file App dal momento che si mette in comune la definizione della tabella eventi
    usata ad esempio dal modulo timer

. nei files <Modulo><App>.h sono presenti le definizioni di variabili globali ovvero variabili utilizzate da più moduli
.. questi file App che hanno la funzione di collettore conoscono il modulo di appertenza ma anche i suoi utilizzatori
   che sono utilizzatori indiretti; in questo file ad esempio vengono assegnate le locazioni degli elementi di strutture dati
	come ad esempio l'array dei timer



// Rev 00.01 del 2015-10-09
Questa revisione ha un codice i cui moduli vengono compilati senza nessun errore  tuttavia la fase di link presenta un errore, in particolare
"Error - symbol 'TmrSecond' has multiple definitions."

per risolvere questo problema si deve capire come in un progetto c con più moduli sia possibile definire una variabile globale ovvero visibile da più moduli
per far questo si fa uso della parola chiave extern

la parola extern permette ad un modulo di compilarsi senza errori quando viene usata una variabile extern
per non avere errori in fase di link la variabile definita come extern deve essere definita in un modulo e solo uno senza la parola extern

ora per meglio gestire tali variabili globali è bene stabilire una politica di gestione, come si vedrà tra breve tale politica farà un certo uso 
anche delle #define

La politca di gestione delle variabili globali usate nel presente progetto seguirà i seguenti principi
. le variabili verranno definite in un modulo dedicato solo a loro che si chiamerà rs2GloabalVarGlo
questo modulo avrà sia un file .h che un file .c

. all'interno di questo modulo facendo un opportuno uso delle define le variabili verranno chiamate una sola volta come di seguito indicato:

// modulo rs2GloablVarGlo.h

#ifdef _DEF_H

#define _EXTERN_DEF

#else

#define _EXTERN_DEF extern

#endif


// definizione variabili globali

// tmr_glo_def.h
_EXTERN_DEF int TmrSecond;
_EXTERN_DEF char TmrError;

// key_glo_def.h
_EXTERN_DEF char Buttons;


// glcd_glo_def.h
_EXTERN_DEF char line;

// adc_glo_def.h

// adcApp_glo_def.h
_EXTERN_DEF int adcAppBuff[3];

// touch_glo_def.h
_EXTERN_DEF char TouchX;
_EXTERN_DEF char TouchY;

ora _DEF_H verrà definito solo nel modulo "def.c" e naturalmente prima di "chiamare" l'include "def.h"
si capisce quindi che tutti i moduli "vedranno" le variabili definite come extern

// modulo timer
Quali siano i timer di sistema al modulo timer poco interessa
quindi
il modulo timer deve poter vedere solo il file.h in cui è definito l'array, questo file .h dovra naturalmente conoscere il numero di timer usati
la definizone dei timer deve necessaramente avvenire per mezzo del collettore della risorsa timer

rs2TimerApp.h // definizione dei timer
rs2TimerApp.c // definizione della tabella eventi
	
	// funzione di controllo
	se Timer i scaduto allora codice_evento = i
	char TmrControllo (indice_timer);

// modulo eventi
// può essere visto come un collettore tra la risorsa e le sue applicazioni
// deve conoscere le funzioni di controllo e le funzioni evento
// tuttavia se il gestore eventi si preoccupa solo di eseguire la funzione di controllo e successivamente eseguire l'evento
// non ha bisogno di conoscere la definizione delle rispettive funzioni
// 
ControlloEventi()
è una funzione che gestisce un array di coppie di funzioni formate da una funzione di controllo e da una funzione evento da eseguirsi se il controllo 
da esito positivo, però ci sono anche altre funzioni che devono essere sempre eseguite a prescindere dal controllo

// risorsa di esecuzione ovvero risorsa cpu (processi in esecuzione)
ci sono delle funzioni che si chiede vengano eseguite (funzioni di controllo) altre funzioni semplicemente possono sussistere in modo autonomo

lo schema è

Modulo rs2Processes.c	<--- Define AppProcesses.h è definita la struttura della tabella controlli/eventi
Define AppProcesses.h	<--- Define AppEvents.h
Define AppEvents.h		<--- Define (AppEventsTimer.h, AppEventsDIn.h, AppEventskey.h, TouchGlo.h, etc. )
Define AppEventsTimer.h <--- Define (TimerGloADC.h, TimerGloDIn.h, TimerGloKey.h, TimerGloTouch.h, etc. )

Moduli
- funzioni controllo (lettura risorse)
- funzioni evento
- funzioni di libreria (scrittura risorse)
- definizione costanti
- definizione variabili
- definizione array

Usare una risorsa significa in modo indiretto (esempio il timer di systema che usa l'interrupt) mettere a disposizione una propria funzione che possa 
venire chiamata
Usare una risorsa in modo diretto (esempio utilizzo dell'LCD) usare le funzioni messe a disposizione dalla risorsa

Dipendenza Diretta (per risorse in scrittura) e Inversa (per risorse in lettura)
. Diretta:	la risorsa mette a disposizione le routine affinche possa essere gestita, qui si capisce benissimo come la risorsa non sappia quali moduli la 
				stanno utilizzando o la utilizzeranno
. Inversa:	la risorsa svolge delle funzioni che coinvolgo delle generiche funzioni; ad esempio il timer quando scade deve chiamare un evento (al timer 
				non interessa cosa faccia); l'ADC quando legge un valore deve assegnarlo ad una precisa variabile (per evitare di usare il passaggio di 
				varibaili che consumano parecchio codice) cosa sia questa variabile all'ADC non interessa; ancora di più quando l'ADC usa l'interrupt; 
				In questo caso sembra che la risorsa usi il suo utilizzatore e non il vicevrsa dato che nel modulo della risprsa compare file di intestazione
				dell'utilizzatore; per eliminare questo assurdo si usa il concetto di collettore ovvero un modulo che può essere costituito anche da un solo
				file di intestazione, questo modulo collettore fa conoscere alla risorsa le strutture "dati+funzioni di istanze", che la risorsa gestirà 
				in modo del tutto generico mentre i vari utilizzatori della risorsa faranno conoscere al collettore i propri dati e funzioni istanze che 
				alimenteranno la struttura suddetta.
				Con questa impostazione si ha il vantaggio di centralizzare alcune procedure che per il debug è una cosa molto buona oltre che ad una
				scrittura del codice più fluida e facile da leggere (una volta capita la struttura) tesa anche a minimizzare l'uso delle istruzioni if-then
				e quindi proiettata alla "tabellizzazione" del codice.
				
				
Albero delle dipendenze
-	la cosa interessante sarebbe quella di creare l'albero delle risorse semplicemente vedendo come sono usati i file include, importante sarà anche la 
	struttura del nome dei file include
- i file .c hanno solo dipendenze dirette
- i file .h e gli app.h hanno solo dipendenze inverse

Esempi di dipendenze
-	timer: in teoria il timer di sistema condivide solo le variabili (per i moduli che dipendono da lui, non da funzioni da usare), inoltre 
	la gestione degli eventi potrebbe essere un modulo a parte, mentre per le dipendenze da altri moduli come l'interrupt ed il main sono tutte
	dipendenze indirette descritte nel file di intestazione
	quindi
	. nel file di instestazione si vedono le dipendenze inverse "in entrata"
	. nel file App si vedono le dipendenze inverse "in uscita"
	. nel file .c del modulo si vedono le dipendenze dirette
	
	
Nome dei moduli
-	<prefisso 0><prefisso 1><nome risorsa>
-	moduli delle risorse inizizieranno con "rs2"
-	i moduli delle risorse che avranno diretto accesso ai registri del micro inizieranno con "rs2HW"
	questi moduli sono quelli che avranno l'include "<p18f45k22.h>"
-	i moduli collettore inizieranno con "rs2App"





     struct command
     {
       char *name;
       void (*function) (void);
     };
     
     struct command commands[] =
     {
       { "quit", quit_command },
       { "help", help_command },
       ...
     };

Using typedef:

		typedef int (*ptFunction)(int, int);
		
		// Can now use "ptFunction" as a type;
		ptFunction pt1 = &subtract;
		
		printf("%d\n", (*pt1)(10, 2));
		
		

Dispatch Tables:

Common application for function pointers is to create dispatch tables. Cannot store functions inside an array so we have to use pointers to functions. A dispatch table contains pointers to functions to be called.
Example: Create a table for processing user commands. Each entry would contain the command name and the pointer to a function to call to when that command is entered.

		// Sample dispatch table [Ideally we would use hashtables, but for now let's just use arrays]
		// array of structs
		
		struct  entry{
			char *command; // string
			int (*func)(int, int); // pointer to a function which takes in two ints
		};
		
		// table with two entries
		struct entry table[] = { {"add", &add},
					 {"subtract", &subtract} };
		
		// define a function which retrieves proper function depending on command
		// retrieves the proper function pointer from the dispatch table according to t$
		int (*getDispatchPtr(char *comm))(int, int) {
			// go through the table
			int i;
			for(i = 0; i < 2; i++) {
				if (strcmp(table[i].command, comm) == 0) // found match
					return table[i].func;
			}

			// found nothing
			return 0;
		}
		
		// Usage:
		// create pointer first
		ptFunction pt2 = NULL;
		
		// get the function pointer
		pt2 = getDispatchPtr("subtract");
		
		int subtr = (*ptr2)(100, 20);
		
		

	  


//	****************************************************************************
//	++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/*

   MODULE DESCRIPTION:  

   AUTHOR:  Marco Ing. Dau		 																									

   ****************************************************************************************************************************************************
   * SVN-keywords: fields managed by SVN - DO NOT MODIFY 
   *
   *	USER who run commit:    $Author:  $																										
   *	REVISION NUMBER:        $Revision:  $																											
   *	LAST DATE REVISION:     $Date:  $															
   *	LOCATION FILE:          $HeadURL:  $			
   *																																						
   ****************************************************************************************************************************************************

 */

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

