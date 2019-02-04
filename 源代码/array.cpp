/*-------------------------------------------------------------
 *
 *
 *----------------array.cpp
 *
 *
 *
 *
 *
 *
 *
 *
 *						2008.7.23	( zhushouyuan )
 *
 *
------------------------------------------------------------*/

#include "array.h"


#define ARRAY_LEN	100					//����ĳ���

static struct Token * array[ARRAY_LEN] ;		//����ָ������

static int i =0 ;				//������α�

static int count = 1 ;			//������

extern Token token ;


//-------------��ӼǺŵ�������---------------------

extern void Link ()
{

	array[i] = (struct Token *)malloc ( sizeof(Token) ) ;

	array[i]->type = token.type ;

	array[i]->lexeme = token.lexeme ;

	array[i]->next = NULL ;

	i++ ;
}


//-------------����һ�εĺ���----------------------

static void Link_one ()
{
	struct Token * ptr = array[i-2] ;

	while ( ptr->next != NULL )
	
		ptr = ptr->next ;

	ptr->next = array[i-1] ;

	array[i-1] = NULL ;

	ptr = NULL ;

	i-- ;

}


//-----------------��ӡ�������---------------------------

static void Print ()
{
	struct Token * pt = array[i-1] ;

	printf ( "��%-2d���ֽ�:	", count++ ) ;

	while ( pt != NULL )
	{
		printf ( "%c", pt->lexeme ) ;

		pt = pt->next ;
	}

	printf ( "\n" ) ;
}


//-----------------����'|'�Ǻ�ʱ�����Ӻ���----------------

extern void Link_SHUXIAN ()
{
	Link_one () ;

	Link_one () ;

	Print () ;
}


//------------------����'.'�Ǻ�ʱ�����Ӻ���--------------------

extern void Link_DIAN ()
{
	Link_one () ;

	Link_one () ;

	Print () ;
}


//----------------����'*'�Ǻ�ʱ�����Ӻ���----------------------

extern void Link_XINHAO ()
{
	Link_one () ;

	Print () ;
}


//--------------����')'�Ǻ�ʱ�����Ӻ���------------------------

extern void Link_KUOHAO ()
{
	Link_one () ;

	Link_one () ;

	Print () ;
}

