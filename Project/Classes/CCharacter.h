#ifndef _CCHARACTER_H_
#define _CCHARACTER_H_

#include "cocos2d.h"
#include "CObject.h"
USING_NS_CC;

// ÁÖÀÎ°ø¾¾ 
class CCharacter : public CObject
{
public:
	CCharacter();
	~CCharacter();

	void setSprite(Sprite* a_sprite){ this->m_sprite = a_sprite; }
	Sprite* getSprite(){ return this->m_sprite; }

private:
	Vec2 m_Point;
	Sprite* m_sprite;
};
#endif