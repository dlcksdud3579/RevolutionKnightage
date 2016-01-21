#ifndef _TURNControler__
#define _TURNControler__
#include "cocos2d.h"

USING_NS_CC;

class TurnControler
{
public:
	TurnControler(); // »ý¼ºÀÚ

	//set get 
	void setMenuPoint(Vec2 a_menuPoint){ this->m_menuPoint = a_menuPoint; }
	Vec2 getMenuPoint(){ return this->m_menuPoint; }
	//set get


private:
	Vec2 m_menuPoint;
};



#endif 