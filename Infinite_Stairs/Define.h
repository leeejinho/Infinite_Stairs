#pragma once
#ifndef __DEFINE_H__
#define __DEFINE_H__

#define WINCX 450
#define WINCY 750

#define SAFE_DELETE(p) if(p) { delete p; p = nullptr; }

#define OBJ_NOEVENT		0
#define OBJ_DEAD		1

#define STAIR_CX 50
#define STAIR_CY 30

#endif // !__DEFINE_H__
