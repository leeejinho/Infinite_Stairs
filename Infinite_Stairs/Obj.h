#pragma once
#ifndef __OBJ_H__
#define __OBJ_H__

class CObj
{
public:
	CObj();
	virtual ~CObj();

	virtual void Initialize() = 0;
	virtual int Update() = 0;
	virtual void Late_Update() = 0;
	virtual void Render(HDC _DC) = 0;
	virtual void Release() = 0;

public:
	const INFO& Get_Info() const { return m_tInfo; }
	const RECT& Get_Rect() const { return m_tRect; }

protected:
	INFO	m_tInfo;
	RECT	m_tRect;
	FRAME	m_tFrame;

	bool	m_bDead;

	const TCHAR*	m_pFrameKey;
};

#endif // !__OBJ_H__
