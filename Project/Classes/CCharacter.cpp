#include  "CCharacter.h"
#include  "StaticContentsContainer.h"
CCharacter::CCharacter()
{
	this->setSpriteRoot("char/RKnight.png");
	this->setSprite(Sprite::create("char/RKnight.png"));
	this->getSprite()->retain();
	this->setStatus(new Status(10, 10, 10, 10, 10, 10, 10));
	for (int i=0; i < 10; i++)
	{
		setSkill(NULL, i);
		setItem(NULL, i);
	}
	CSkill *skill = StaticContentsContainer::getMapSkill()->find("1")->second;

	this->setSkill(StaticContentsContainer::getMapSkill()->find("1")->second, 0);
}

CCharacter::~CCharacter()
{
	this->getSprite()->release();
	delete(this->getStatus());
	delete(this->getSkill(0));
}

