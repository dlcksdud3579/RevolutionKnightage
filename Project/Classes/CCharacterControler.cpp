#include "CCharacterControler.h"
#include "DynamicContentsContainer.h"
CCharacterControler::CCharacterControler()
{
	setCharacter(DynamicContentsContainer::getInstance()->getCharacter());

}
CCharacterControler::CCharacterControler(CCharacter *a_Character)
{
	setCharacter(a_Character);
}
CCharacterControler::~CCharacterControler()
{

}

bool CCharacterControler::moveRight()
{
	if (checkMoveable(Vec2(getCharacter()->getPoint().x + 1, getCharacter()->getPoint().y)) == false)
		return false;
	getCharacter()->setPoint(Vec2(getCharacter()->getPoint().x + 1, getCharacter()->getPoint().y));
	return true;
}

bool CCharacterControler::moveLeft()
{
	if (checkMoveable(Vec2(getCharacter()->getPoint().x - 1, getCharacter()->getPoint().y)) == false)
		return false;
	getCharacter()->setPoint(Vec2(getCharacter()->getPoint().x - 1, getCharacter()->getPoint().y));
	return true;
}
bool CCharacterControler::moveUp()
{
	if (checkMoveable(Vec2(getCharacter()->getPoint().x, getCharacter()->getPoint().y + 1)) == false)
		return false;
	getCharacter()->setPoint(Vec2(getCharacter()->getPoint().x, getCharacter()->getPoint().y + 1));
	return true;
}
bool CCharacterControler::moveDown()
{
	if (checkMoveable(Vec2(getCharacter()->getPoint().x, getCharacter()->getPoint().y - 1)) == false)
		return false;
	getCharacter()->setPoint(Vec2(getCharacter()->getPoint().x, getCharacter()->getPoint().y - 1));
	return true;
}

bool CCharacterControler::checkMoveable(Vec2 a_checkPoint)
{
	CMap * map = DynamicContentsContainer::getInstance()->getMap();

	if (map->atTile(a_checkPoint)->getObject(2)->isMoveable() == false || map->atTile(a_checkPoint)->getObject(0) != NULL)
		return false;
	return true;
}

