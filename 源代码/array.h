/*-------------------------------------------------------------
 *
 *
 *----------------array.h
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


#ifndef ARRAY_H
#define ARRAY_H

#include "scanner.h"
#include "parser.h"
#include <malloc.h>


extern void Link () ;					//连接函数

extern void Link_SHUXIAN () ;			//当是'|'记号时的连接函数

extern void Link_DIAN () ;				//当是'.'记号时的连接函数

extern void Link_XINHAO () ;			//当是'*'记号时的连接函数

extern void Link_KUOHAO () ;			//当是')'记号时的连接函数

#endif




