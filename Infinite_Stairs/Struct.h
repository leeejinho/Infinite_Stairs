#pragma once
#ifndef __STRUCT_H__
#define __STRUCT_H__

typedef struct tagInfo
{
	float	fX;
	float	fY;
	int		iCX;
	int		iCY;
}INFO;


typedef struct tagFrame
{
	int		iStartX;
	int		iEndX;
	int		iStateY;
	DWORD	dwDelayTime;
	DWORD	dwTime;
}FRAME;


#endif // !__STRUCT_H__
