#ifndef  _COBJECT_H_
#define  _COBJECT_H_
#include "cocos2d.h"
using namespace std;
USING_NS_CC;

class CObject
{
public:
	CObject();
	CObject(Vec2 a_Point);
	CObject(string a_name, bool a_Moveable, int a_Type);

	void setPoint(Vec2 a_Point){ this->m_Point = a_Point; }
	Vec2 getPoint(){ return this->m_Point; }

	void setName(string a_name){ this->m_name = a_name; }
	string getName(){ return this->m_name; }

	void setType(int a_Type){ this->m_Type = a_Type; }
	int getType(){ return this->m_Type; }
	
	void setMoveable(bool a_Moveable){ this->m_Moveable = a_Moveable; }
	bool isMoveable(){ return this->m_Moveable; }



private:
	Vec2 m_Point;

	string m_name;
	bool m_Moveable;
	int m_Type; //0,1,2  3개중 하나
	



};
#endif