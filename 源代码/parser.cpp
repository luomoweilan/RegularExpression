/*-------------------------------------------------------------
 *
 *
 *----------------parser.cpp
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

#include "parser.h"

Token token ;

static void Program () ;
static void Statement_1 () ;
static void Statement_2 () ;
static void Statement_3 () ;
static void Statement_4 () ;


//--------------------获取一个记号--------------

static void FetchToken ()
{
	token = GetToken () ;

	if ( token.type==ERRTOKEN )

		return ;

}


//-------------------匹配记号---------------------

static void MatchToken ( enum Token_Type token_type )
{
	if ( token.type!=token_type )
		
		return ;

	Link () ;

	FetchToken () ;

}



//----------------解释器入口----------------------

extern void Parser ( char * FileName )
{
	if ( !InitScanner(FileName) )
	{
		printf ( "error !" ) ;

		return ;
	}

	FetchToken () ;

	Program () ;

	CloseScanner () ;

}


//----------------Program------------------------

static void Program ()
{
	while ( token.type != NONTOKEN )
	{
		Statement_1 () ;
	}
}


//-------------Statement_1-------------------

static void Statement_1 ()
{
	Statement_2 () ;

	while ( token.type==SHUXIAN )
	{
		MatchToken ( SHUXIAN ) ;

		Statement_2 () ;

		Link_SHUXIAN () ;
	}
}


//-----------Statement_2--------------------

static void Statement_2 ()
{
	Statement_3 () ;

	while ( token.type==DIAN )
	{
		MatchToken ( DIAN ) ;

		Statement_2 () ;

		Link_DIAN () ;
	}
}

//---------------Statement_3--------------------

static void Statement_3 ()
{
	Statement_4 () ;

	while ( token.type==XINHAO )
	{
		MatchToken ( XINHAO ) ;

		Link_XINHAO () ;
	}
}


//--------------Statement_4-------------------

static void Statement_4 ()
{
	if ( token.type==L_KUOHAO )
	{
		MatchToken ( L_KUOHAO ) ;

		Statement_1 () ;

		MatchToken ( R_KUOHAO ) ;

		Link_KUOHAO () ;
	}
	else

		MatchToken ( CONST ) ;
	
}


