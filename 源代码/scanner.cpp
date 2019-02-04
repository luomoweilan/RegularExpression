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


#define TOKEN_LEN	100					//记号缓冲区的最大长度

static FILE * pfile ;					//输入文件流

static char TokenBuffer[TOKEN_LEN] ;	//记号缓冲区


//----------------初始化扫描器---------------------

extern int InitScanner ( char * FileName ) 
{
	pfile = fopen ( FileName, "r" ) ;
	
	if ( pfile != NULL )	
		
		return 1 ;

	else	
		
		return 0 ;
}


//----------------关闭扫描器-----------------------

extern void CloseScanner ( void )
{
	if ( pfile != NULL )

		fclose ( pfile ) ;
}


//------------------从输入源程序中读入一个字符--------------------

static char GetChar ( void )
{
	int Char = getc ( pfile ) ;

	return toupper ( Char ) ;

}



//-----------------------加入字符到记号缓冲区----------------------

static void AddCharTokenString ( char Char )
{
	int TokenLength = strlen ( TokenBuffer ) ;

	if ( TokenLength+1 >= sizeof( TokenBuffer ) )

		return ;

	TokenBuffer[TokenLength] = Char ;

	//TokenBuffer[TokenLength+1] = '\0' ;
}


//-------------------清空记号缓冲区-------------------

static void EmptyTokenString ()
{
	memset ( TokenBuffer, 0, TOKEN_LEN ) ;
}


//-------------------------取一个记号----------------

extern Token GetToken ( void )
{
	Token toke ; 

	int Char ;

	memset ( & toke, 0, sizeof(Token) ) ; 

	EmptyTokenString () ;

	for ( ; ; )							//过滤空格、回车等
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

	if ( isalpha(Char) )			//若是字母就返回一个记号
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




