#ifndef _CMONSTER_H_
#define _CMONSTER_H_
#include "CObject.h"
#include "CStatus.h"

class CMonster :public CObject
{
public:
	CMonster();
	~CMonster();

	void setSprite(Sprite* a_sprite){ this->m_sprite = a_sprite; }
	Sprite* getSprite(){ return this->m_sprite; }

	void setPoint(Vec2 a_Point){ this->m_Point = a_Point; }
	Vec2 getPoint(){ return this->m_Point; }

	void setStatus(Vec2 a_status){ this->m_status = a_status; }
	Status getStatus(){ return this->m_status; }

private:
	Vec2 m_Point;
	Sprite* m_sprite;
	Status  m_status;
};
#endif
