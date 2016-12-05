/*

   MODULE DESCRIPTION:  

   AUTHOR:  Marco Ing. Dau		 																									

   ****************************************************************************************************************************************************
   * SVN-keywords: fields managed by SVN - DO NOT MODIFY 
   *
   *	USER who run commit:    $Author: Administrator $																										
   *	REVISION NUMBER:        $Revision: 308 $																											
   *	LAST DATE REVISION:     $Date: 2015-12-08 16:39:05 +0100 (mar, 08 dic 2015) $															
   *	LOCATION FILE:          $HeadURL: file:///C:/Users/Administrator/Documents/SVN/Repository/fw2/15101-emphil/work/fnThermostatGlo.h $			
   *																																						
   ****************************************************************************************************************************************************

 */


#ifdef _FN_DEF_C
#define _EXTERN_FN_DEF
#else
#define _EXTERN_FN_DEF extern
#endif


//																Etichetta parametro							,ptr_parametro		,Default 	,Min		,Max		,sizeof()					,FLAG1		,FLAG2 		
#define	ROW_PAR_TERMOSTATO_SETPOINT			{	ID_STR_PAR_TERMOSTATO_SETPOINT			,&SetPoint			,0x7F			,0x00		,0xFF		,sizeof(SetPoint)			,WORD			,DIGIT_3		}
#define	ROW_PAR_TERMOSTATO_SETPOINT_MIN		{	ID_STR_PAR_TERMOSTATO_SETPOINT_MIN		,&SetPointMin		,0x7F			,0x00		,0xFF		,sizeof(SetPointMin)		,WORD			,DIGIT_3		}
#define	ROW_PAR_TERMOSTATO_SETPOINT_MAX		{	ID_STR_PAR_TERMOSTATO_SETPOINT_MAX		,&SetPointMax		,0x7F			,0x00		,0xFF		,sizeof(SetPointMax)		,WORD			,DIGIT_3		}
#define	ROW_PAR_TERMOSTATO_DELTA				{	ID_STR_PAR_TERMOSTATO_DELTA				,&Delta				,0x7F			,0x00		,0xFF		,sizeof(Delta)				,WORD			,DIGIT_3		}
#define	ROW_PAR_TERMOSTATO_TEMPO_MINUTI		{	ID_STR_PAR_TERMOSTATO_TEMPO_MINUTI		,&TempoMinuti		,0x7F			,0x00		,0xFF		,sizeof(TempoMinuti)		,WORD			,DIGIT_3		}
#define	ROW_PAR_TERMOSTATO_TEMPO_SECONDI		{	ID_STR_PAR_TERMOSTATO_TEMPO_SECONDI		,&TempoSecondi		,0x7F			,0x00		,0xFF		,sizeof(TempoSecondi)	,WORD			,DIGIT_3		}

//																Etichetta variabile di stato				,ptr_variabile		,sizeof()					,FLAG1		,FLAG2 		
#define	ROW_VAR_TERMOSTATO_TEMPERATURA		{	ID_STR_VAR_TERMOSTATO_TEMPERATURA		,&Temperatura		,sizeof(SetPointMax)		,WORD			,DIGIT_3		}
#define	ROW_VAR_TERMOSTATO_UMIDITA				{	ID_STR_VAR_TERMOSTATO_UMIDITA				,&Umidita			,sizeof(SetPointMax)		,WORD			,DIGIT_3		}

_EXTERN_FN_DEF	char SetPoint;		
_EXTERN_FN_DEF	char SetPointMin;	
_EXTERN_FN_DEF	char SetPointMax;	
_EXTERN_FN_DEF	char Delta;
_EXTERN_FN_DEF	char TempoMinuti;	
_EXTERN_FN_DEF	char TempoSecondi;	
_EXTERN_FN_DEF	char Temperatura;
_EXTERN_FN_DEF	char Umidita;







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
