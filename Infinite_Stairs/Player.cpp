#include "stdafx.h"
#include "Player.h"
#include "KeyMgr.h"
#include "ScrollMgr.h"

CPlayer::CPlayer()
	: m_bStretch(false)
{
}


CPlayer::~CPlayer()
{
}


void CPlayer::Initialize()
{
	m_tInfo.fX = WINCX / 2;
	m_tInfo.fY = WINCY - 200;

	m_tInfo.iCX = 100;
	m_tInfo.iCY = 150;
}

int CPlayer::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	//Update_Frame();
	Update_Rect();
	Key_Check();

	return OBJ_NOEVENT;
}

void CPlayer::Late_Update()
{
}

void CPlayer::Render(HDC _DC)
{
	Rectangle(_DC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CPlayer::Release()
{
	int i = 0;
}

void CPlayer::Update_Rect()
{
	m_tRect.left = (LONG)(m_tInfo.fX - (m_tInfo.iCX >> 1));
	m_tRect.top = (LONG)(m_tInfo.fY - m_tInfo.iCY);
	m_tRect.right = (LONG)(m_tInfo.fX + (m_tInfo.iCX >> 1));
	m_tRect.bottom = (LONG)m_tInfo.fY;
}

void CPlayer::Update_Frame()
{
	if (m_tFrame.dwDelayTime + m_tFrame.dwTime < GetTickCount())
	{
		++m_tFrame.iStartX;
		m_tFrame.dwTime = GetTickCount();

		if (m_tFrame.iStartX >= m_tFrame.iEndX)
			m_tFrame.iStartX = 0;
	}
}

void CPlayer::Key_Check()
{
	if (CKeyMgr::Get_Instance()->Key_Down(VK_LEFT))
	{

		m_bStretch = !m_bStretch;

		if (m_bStretch)
		{
			m_tInfo.fX -= STAIR_CX;
			m_tInfo.fY -= STAIR_CY;
		}
		else
		{
			m_tInfo.fX += STAIR_CX;
			m_tInfo.fY -= STAIR_CY;
		}
	}
	else if (CKeyMgr::Get_Instance()->Key_Down(VK_RIGHT))
	{
		if (m_bStretch)
		{
			m_tInfo.fX -= STAIR_CX;
			m_tInfo.fY -= STAIR_CY;
		}
		else
		{
			m_tInfo.fX += STAIR_CX;
			m_tInfo.fY -= STAIR_CY;
		}
	}
}
