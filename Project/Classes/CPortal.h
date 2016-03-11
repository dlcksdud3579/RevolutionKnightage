#ifndef  _CWARP_H_
#define  _CWARP_H_

#include "cocos2d.h"
#include "CObject.h"


using namespace std;
USING_NS_CC;

class CPortal :public CObject

{
public:
	CPortal();
	CPortal(Vec2 a_Point);
	CPortal(string a_name, bool a_Moveable, int a_Type, string a_linkedMapKey, Vec2 a_linkedPoint);

	void setLinkedMapKey(string a_linkedMapKey){ this->m_linkedMapKey = a_linkedMapKey; }
	string getLinkedMapKey(){ return this->m_linkedMapKey; }

	void setLinkedPoint(Vec2 a_linkedPoint){ this->m_linkedPoint = a_linkedPoint; }
	Vec2 getLinkedPoint(){ return this->m_linkedPoint; }

private:
	string m_linkedMapKey; // 연결된 맵
	Vec2 m_linkedPoint; // 이동될 맵의 위치

};
#endif