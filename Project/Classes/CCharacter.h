#ifndef _CCHARACTER_H_
#define _CCHARACTER_H_

#include "cocos2d.h"
#include "CObject.h"
#include "CStatus.h"
#include "CSkill.h"
#include "CItem.h"
USING_NS_CC;

class CCharacter : public CObject // 주인공씨 
{
public:
	CCharacter();
	~CCharacter();




	// get set 
	void setSprite(Sprite* a_sprite){ this->m_sprite = a_sprite; }
	Sprite* getSprite(){ return this->m_sprite; }

	void setPoint(Vec2 a_Point){ this->m_Point = a_Point; }
	Vec2 getPoint(){ return this->m_Point; }

	void setStatus(Status* a_status){ this->m_status = a_status; }
	Status* getStatus(){ return this->m_status; }

	void setSpriteRoot(std::string m_spriteRoot){ this-> m_spriteRoot =  m_spriteRoot;}
	std::string getSpriteRoot(){ return this->m_spriteRoot; }

	void setSkill(CSkill* a_skill,int index){ this->m_skill[index] = a_skill; }
	CSkill* getSkill(int index){ return m_skill[index]; }

	void setItem(CItem* a_item, int index){ this->m_item[index] = a_item; }
	CItem* getItem(int index){ return this->m_item[index]; }

	void setName(std::string a_name){ this->m_name = a_name; }
	std::string getName(){return this->m_name; }
	// get set 
private:
	std::string m_name; // 이름 
	Vec2 m_Point; // 위치 
	std::string m_spriteRoot; // 이미지 위치 
	Sprite* m_sprite; // 이미지 
	Status*  m_status; //스텟
	CSkill* m_skill[6]; //  스킬 
	CItem* m_item[10]; // 아이템
};
#endif