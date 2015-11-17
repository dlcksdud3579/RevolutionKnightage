#include  "CCharacter.h"
CCharacter::CCharacter()
{
	this->setSpriteRoot("char/RKnight.png");
	this->setSprite(Sprite::create("char/RKnight.png"));
	this->getSprite()->retain();
}

CCharacter::~CCharacter()
{
	this->getSprite()->release();
}

