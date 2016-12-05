
. Obiettivi
.. Permettere uno sviluppo veloce di applicazioni firmware per processori 8 bit
.. Portabilita del codice su altre piattaforme in cui sia presente un compilatore C standard
... creare i driver per la nuova piattaforma
... per gli ambienti desktop
.... possibilità di creare dei test / sviluppo di test automatici
.... per la qualità del codice prodotto
..... sia per i moduli interfaccia
..... sia per i moduli funzionali
.... i driver del LCD/7 segmenti/GLCD possono generare dei file XML che poi possono essere usati per i test di interfaccia
.. Sviluppare applicazioni PLC
... Standard
... con Moduli / orientate agli oggetti


. inserire i parametri
. utilizzo dei def, variabili globali


. Struttura

. nomenclatura
.. Nomi dei file header
... <Nome Modulo>.h <MomeModulo>Glo.h
.... <MomeModulo>Glo.h -> tipicamente vengono definite le variabili globali utilizzate dal modulo proprietario e dai moduli che da esso dipendono 
.... <Nome Modulo>.h   -> vengono rese pubbliche alcune funzioni del modulo
.. Nomi dei Moduli

. Definizione delle variabili globali
.. file <>Def.c
.. define _DEF

. Tipologie di funzioni
.. eventi timer
.. eventi moduli funzionali
... esempio moduli interfaccia
.. funzioni controllo eventi
.. funzioni esecuzione eventi
.. funzioni di libreria classiche
... esempio: funzioni dei dirver LCD
.. funzioni di init
.. funzioni dei moduli interfaccia presenti nella tabella del modulo Base

. Descrizione delle dipendenze
.. dipendenze dirette
... esempio: sono quelle dipendenze dove il modulo A che dipende da un modulo B deve chiamare al suo interno il file header del modulo B
.. dipendenze indirette
... esempio: il modulo dei processi dipende dal modulo main ma è il modulo main che deve chiamare il file header dei processi; questo avviene 
		perchè la modalità di dipendenza è quella di offrire un servizio, nel caso specifico quella 


. Procedure
.. utilizzo dei timer
.. utilizzo degli eventi
.. esecuzione ad ogni ciclo di un task
.. inserimento di un modulo funzionale
... esempio della tastiera
.. inserimento nuovi moduli interfaccia
.. inserire dei parametri del firmware nella lista parametri

.. Moduli interfaccia
... Tabella delle istanze
... Tabella degli eventi
... Funzioni presenti nella tabella del modulo Base
... Come:
.... Inserire elementi nella pagina
.... Passare da una pagina all'altra
.... Inserire elementi in un ListBox


. Descrizione dei Moduli principali
.. main
.. process
.. rs<> (rs2 sta per risorse->(togliendo le vocali)rsrs->rs2)
.. <>Glo
.. <>Table
.. <>Def


. Albero delle dipenedenze

. File header per la configurazione della piattaforma


// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

implemenetazione windows, con librerie CLR/.net

. per la simulazione dell'LCD
.. definire file di intestazione GLO
... netLcdGlo.h
.... lcd_string[righe][colonne]
.. definire il file in cui vengono definite le variabili globali che necessariamente devono definirsi extern
... netDef.cpp

Progetto visual studio cpp
. vedere file lcd.h



