#include "stdafx.h"
#include "Stair.h"


CStair::CStair()
{
}

CStair::CStair(INFO & _tInfo)
	: CObj(_tInfo)
{
}


CStair::~CStair()
{
	Release();
}

void CStair::Initialize()
{
	Update_Rect();
}

int CStair::Update()
{
	if (m_bDead)
		return OBJ_DEAD;




	return OBJ_NOEVENT;
}

void CStair::Late_Update()
{
}

void CStair::Render(HDC _DC)
{
	Rectangle(_DC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CStair::Release()
{
}
