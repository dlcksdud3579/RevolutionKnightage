#include  "CCharacter.h"
CCharacter::CCharacter()
{
	this->setSpriteRoot("char/RKnight.png");
	this->setSprite(Sprite::create("char/RKnight.png"));
	this->getSprite()->retain();
	this->setStatus(new Status(100, 10, 10, 10, 10, 10, 10));
}

CCharacter::~CCharacter()
{
	this->getSprite()->release();
}

