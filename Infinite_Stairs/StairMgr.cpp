#include "stdafx.h"
#include "StairMgr.h"
#include "Stair.h"
#include "ObjMgr.h"

CStairMgr* CStairMgr::m_pInstance = nullptr;

CStairMgr::CStairMgr()
	: m_bLeft(true), m_iProbability(7)
{
}


CStairMgr::~CStairMgr()
{
}

void CStairMgr::Initialize()
{
	CObj* pFirstStair = new CStair(INFO(WINCX>>1, 600, STAIR_CX, STAIR_CY));
	pFirstStair->Initialize();
	m_dequeStair.emplace_back(pFirstStair);
	CObjMgr::Get_Instance()->Add_Object(pFirstStair, OBJID::STAIR);
	
	for (int i = 0; i < 20; ++i)
	{
		Add_Stair();
	}
}

void CStairMgr::Add_Stair()
{
	CObj* pLastStair = m_dequeStair.back();
	int iRand = rand() % 10;
	if (m_iProbability < iRand)
		m_bLeft = !m_bLeft;

	INFO tPrevInfo = pLastStair->Get_Info();

	INFO tInfo = {};

	if (m_bLeft)
		tInfo = INFO(tPrevInfo.fX - tPrevInfo.iCX, tPrevInfo.fY - tPrevInfo.iCY, STAIR_CX, STAIR_CY);
	else
		tInfo = INFO(tPrevInfo.fX + tPrevInfo.iCX, tPrevInfo.fY - tPrevInfo.iCY, STAIR_CX, STAIR_CY);

	CObj* pStair = new CStair(tInfo);
	pStair->Initialize();
	m_dequeStair.emplace_back(pStair);
	CObjMgr::Get_Instance()->Add_Object(pStair, OBJID::STAIR);
}
