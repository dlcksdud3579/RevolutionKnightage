#include  "CCharacter.h"
CCharacter::CCharacter()
{
	this->setSprite(Sprite::create("char/RKnight.png"));
	this->getSprite()->retain();
}

CCharacter::~CCharacter()
{
	this->getSprite()->release();
}

