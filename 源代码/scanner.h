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


enum Token_Type				//�Ǻ����
{
	CONST ,		DIAN ,

	SHUXIAN ,	XINHAO ,

	L_KUOHAO ,	R_KUOHAO ,

	NONTOKEN ,

	ERRTOKEN
};			


struct Token			//�ǺŽṹ
{
	Token_Type	type ;

	unsigned char lexeme ;

	struct Token * next ;
};



extern int InitScanner ( char * FIleName ) ;	//��ʼ��ɨ����

extern Token GetToken ( void ) ;			//�õ��Ǻ�

extern void CloseScanner ( void ) ;			//�ر�ɨ����


#endif
