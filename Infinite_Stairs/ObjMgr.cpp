#include "stdafx.h"
#include "ObjMgr.h"
#include "Obj.h"

CObjMgr* CObjMgr::m_pInstance = nullptr;

CObjMgr::CObjMgr()
{
}


CObjMgr::~CObjMgr()
{
	Release();
}

void CObjMgr::Update()
{
	for (int i = 0; i < OBJID::END; ++i)
	{
		auto iter = m_listObj[i].begin();
		for (; iter != m_listObj[i].end(); )
		{
			int iEvent = (*iter)->Update();
			if (OBJ_DEAD == iEvent)
			{
				SAFE_DELETE(*iter);
				iter = m_listObj[i].erase(iter);
			}
			else
				++iter;
		}
	}
}

void CObjMgr::Late_Update()
{
	for (int i = 0; i < OBJID::END; ++i)
	{
		for (auto& pObj : m_listObj[i])
		{
			pObj->Late_Update();

			if (m_listObj[i].empty())
				break;
		}
	}
}

void CObjMgr::Render(HDC _DC)
{
	for (int i = 0; i < RENDERID::END; ++i)
	{
		for (auto& pObj : m_listObj[i])
			pObj->Render(_DC);
	}
}

void CObjMgr::Release()
{
	for (int i = 0; i < OBJID::END; ++i)
	{
		for_each(m_listObj[i].begin(), m_listObj[i].end(), Safe_Delete<CObj*>);
		m_listObj[i].clear();
	}
}

void CObjMgr::Delete_ID(OBJID::ID _eID)
{
	for_each(m_listObj[_eID].begin(), m_listObj[_eID].end(), Safe_Delete<CObj*>);
	m_listObj[_eID].clear();
}

