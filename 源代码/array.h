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


extern void Link () ;					//���Ӻ���

extern void Link_SHUXIAN () ;			//����'|'�Ǻ�ʱ�����Ӻ���

extern void Link_DIAN () ;				//����'.'�Ǻ�ʱ�����Ӻ���

extern void Link_XINHAO () ;			//����'*'�Ǻ�ʱ�����Ӻ���

extern void Link_KUOHAO () ;			//����')'�Ǻ�ʱ�����Ӻ���

#endif




