#ifndef  _CWARP_H_
#define  _CWARP_H_
#include "cocos2d.h"
#include "CObject.h"
#include "CMap.h"

using namespace std;
USING_NS_CC;

class CPortal:public CObject

{
public:
	CPortal();
	CPortal(Vec2 a_Point);
	CPortal(string a_name, bool a_Moveable, int a_Type, CMap* a_linkedMap, Vec2* a_linkedPoint);

	void setLinkedMap(CMap* a_linkedMap){ this->m_linkedMap = a_linkedMap; }
	CMap* getLinkedMap(){return this->m_linkedMap; }

	void setLinkedPoint(Vec2* a_linkedPoint){ this->m_linkedPoint = a_linkedPoint; }
	Vec2* getLinkedPoint(){ return this->m_linkedPoint; }

private:
	CMap* m_linkedMap; // 연결된 맵
	Vec2* m_linkedPoint; // 이동될 맵의 위치

};
#endif