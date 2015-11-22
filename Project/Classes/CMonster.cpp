#include "CMonster.h"

CMonster::CMonster()
{

}
CMonster::CMonster(string a_name, string a_spriteRoot)
{
	setName(a_name);
	setSpriteRoot(a_spriteRoot);
	this->setSprite(Sprite::create(getSpriteRoot()));
	this->getSprite()->retain();
}
CMonster::~CMonster()
{

}