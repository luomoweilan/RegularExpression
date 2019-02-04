/*-------------------------------------------------------------
 *
 *
 *----------------scanner.h
 *
 *
 *
 *
 *
 *
 *
 *
 *						2008.7.21	( zhushouyuan )
 *
 *
------------------------------------------------------------*/


#ifndef SCANNER_H
#define SCANNER_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdarg.h>


enum Token_Type				//记号类别
{
	CONST ,		DIAN ,

	SHUXIAN ,	XINHAO ,

	L_KUOHAO ,	R_KUOHAO ,

	NONTOKEN ,

	ERRTOKEN
};			


struct Token			//记号结构
{
	Token_Type	type ;

	unsigned char lexeme ;

	struct Token * next ;
};



extern int InitScanner ( char * FIleName ) ;	//初始化扫描器

extern Token GetToken ( void ) ;			//得到记号

extern void CloseScanner ( void ) ;			//关闭扫描器


#endif
