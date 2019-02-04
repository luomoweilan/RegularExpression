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


#define ARRAY_LEN	100					//数组的长度

static struct Token * array[ARRAY_LEN] ;		//定义指针数组

static int i =0 ;				//数组的游标

static int count = 1 ;			//计数器

extern Token token ;


//-------------添加记号到数组上---------------------

extern void Link ()
{

	array[i] = (struct Token *)malloc ( sizeof(Token) ) ;

	array[i]->type = token.type ;

	array[i]->lexeme = token.lexeme ;

	array[i]->next = NULL ;

	i++ ;
}


//-------------连接一次的函数----------------------

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


//-----------------打印结果函数---------------------------

static void Print ()
{
	struct Token * pt = array[i-1] ;

	printf ( "第%-2d步分解:	", count++ ) ;

	while ( pt != NULL )
	{
		printf ( "%c", pt->lexeme ) ;

		pt = pt->next ;
	}

	printf ( "\n" ) ;
}


//-----------------当是'|'记号时的连接函数----------------

extern void Link_SHUXIAN ()
{
	Link_one () ;

	Link_one () ;

	Print () ;
}


//------------------当是'.'记号时的连接函数--------------------

extern void Link_DIAN ()
{
	Link_one () ;

	Link_one () ;

	Print () ;
}


//----------------当是'*'记号时的连接函数----------------------

extern void Link_XINHAO ()
{
	Link_one () ;

	Print () ;
}


//--------------当是')'记号时的连接函数------------------------

extern void Link_KUOHAO ()
{
	Link_one () ;

	Link_one () ;

	Print () ;
}

