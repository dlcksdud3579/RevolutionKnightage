#include "CTile.h"

CTile::CTile()
{
	this->setName("");
	this->setPoint(Vec2(0, 0));
	this->setSize();
	this->setSpriteRoot("");
	this->setSprite(NULL);
	this->setObject(NULL, 0);
	this->setObject(NULL, 1);
	this->setObject(NULL, 2);
}

CTile::CTile(string a_szName, string a_SpriteRoot, CObject* m_Object2)
{
	this->setName(a_szName);
	this->setPoint(Vec2(0, 0));
	this->setSize();
	this->setSpriteRoot(a_SpriteRoot);
	this->setSprite(Sprite::create(this->getSpriteRoot()));

	this->setObject(NULL, 0);
	this->setObject(NULL, 1);
	this->setObject(m_Object2, 2);
}

CTile::CTile(CTile* a_CopyCTile, Vec2 a_Point, CObject* a_Object0, CObject* a_Object1) // 복사 생성자
{
	this->setName(a_CopyCTile->getName());
	this->setSize();
	this->setSpriteRoot(a_CopyCTile->getSpriteRoot());

	this->setSprite( Sprite::create(this->getSpriteRoot()));//  스프라이트 생성 깊은 복사 
	this->getSprite()->retain();

	this->setPoint(a_Point);
	this->setObject(a_Object0, 0);
	this->setObject(a_Object1, 1);
	this->setObject(a_CopyCTile->getObject(2), 2);
}

CTile::~CTile()
{
	log("%d %d 타일 소멸자",getPoint().x,getPoint().y);
	this->getSprite()->release();
}