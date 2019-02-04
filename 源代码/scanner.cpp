/*-------------------------------------------------------------
 *
 *
 *----------------scanner.cpp
 *
 *
 *
 *
 *
 *
 *
 *
 *						2008.7.22	( zhushouyuan )
 *
 *
------------------------------------------------------------*/

#include "scanner.h"


#define TOKEN_LEN	100					//�ǺŻ���������󳤶�

static FILE * pfile ;					//�����ļ���

static char TokenBuffer[TOKEN_LEN] ;	//�ǺŻ�����


//----------------��ʼ��ɨ����---------------------

extern int InitScanner ( char * FileName ) 
{
	pfile = fopen ( FileName, "r" ) ;
	
	if ( pfile != NULL )	
		
		return 1 ;

	else	
		
		return 0 ;
}


//----------------�ر�ɨ����-----------------------

extern void CloseScanner ( void )
{
	if ( pfile != NULL )

		fclose ( pfile ) ;
}


//------------------������Դ�����ж���һ���ַ�--------------------

static char GetChar ( void )
{
	int Char = getc ( pfile ) ;

	return toupper ( Char ) ;

}



//-----------------------�����ַ����ǺŻ�����----------------------

static void AddCharTokenString ( char Char )
{
	int TokenLength = strlen ( TokenBuffer ) ;

	if ( TokenLength+1 >= sizeof( TokenBuffer ) )

		return ;

	TokenBuffer[TokenLength] = Char ;

	//TokenBuffer[TokenLength+1] = '\0' ;
}


//-------------------��ռǺŻ�����-------------------

static void EmptyTokenString ()
{
	memset ( TokenBuffer, 0, TOKEN_LEN ) ;
}


//-------------------------ȡһ���Ǻ�----------------

extern Token GetToken ( void )
{
	Token toke ; 

	int Char ;

	memset ( & toke, 0, sizeof(Token) ) ; 

	EmptyTokenString () ;

	for ( ; ; )							//���˿ո񡢻س���
	{
		Char = GetChar () ;

		if ( Char==EOF )
		{
			toke.type = NONTOKEN ;

			return toke ;
		}

		if ( !isspace(Char) ) break ;

	}//end of for

	AddCharTokenString ( Char ) ;

	toke.lexeme = TokenBuffer[0] ;

	if ( isalpha(Char) )			//������ĸ�ͷ���һ���Ǻ�
	{
		toke.type = CONST ;

		return toke ;
	}
	else
	{
		switch ( Char )
		{
			case '|' :	toke.type = SHUXIAN ;	break ;

			case '*' :	toke.type = XINHAO  ;	break ;

			case '(' :	toke.type = L_KUOHAO;	break ;

			case ')' :	toke.type = R_KUOHAO;	break ;

			case '.' :	toke.type = DIAN	 ;	break ;

			default  :	toke.type = ERRTOKEN;	break ;
		}
	}

	return toke ;

}//end of GetToken




