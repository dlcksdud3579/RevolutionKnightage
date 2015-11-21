#include "FieldLayer.h"
#include "math.h"

USING_NS_CC;

bool FieldLayer::init()
{
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
	{
		return false;
	}

	setCharacterSprite(Sprite::create(getCharacter()->getSpriteRoot()));


	printTileField();
	printCharacter();

	return true;
}

FieldLayer::FieldLayer()
{	
	this->setCharacterControler(new CCharacterControler());
	this->setMapControler(new CMapControler());

}

void FieldLayer::printTileField()
{
	int tileSiz = getMap()->atTile(Vec2(0, 0))->getSize().x;

	for (int i = 0; i < getMap()->getSizeTile().y; i++)
	{
		for (int j = 0; j < getMap()->getSizeTile().x; j++)
		{
			getMap()->atTile(Vec2(j, i))->getSprite()->setPosition(tileSiz / 2 + tileSiz * j, tileSiz/2 + tileSiz * i);
			this->addChild(getMap()->atTile(Vec2(j, i))->getSprite(), 0);
		}
	}
}

void  FieldLayer::removeTileField()
{
	
	for (int i = 0; i < getMap()->getSizeTile().y; i++)
	{
		for (int j = 0; j < getMap()->getSizeTile().x; j++)
		{
			this->removeChild(getMap()->atTile(Vec2(j, i))->getSprite());
		}
	}
}


void FieldLayer::moveRight()
{
	if (getCharacter()->getPoint().x >= getMap()->getSizeTile().x-1)
		return;
	if (this->getCharacterControler()->moveRight())
	{
		moveCharacter(getCharacter()->getPoint());
		if (getCharacter()->getPoint().x > 5)
			setViewPoint(Vec2(getViewPoint().x + 1, getViewPoint().y));
	}
}
void FieldLayer::moveLeft()
{
	if (getCharacter()->getPoint().x <= 0)
		return;
	if (this->getCharacterControler()->moveLeft())
	{

		moveCharacter(getCharacter()->getPoint());
		if (getCharacter()->getPoint().x < getMap()->getSizeTile().x - 6)
			setViewPoint(Vec2(getViewPoint().x - 1, getViewPoint().y));
	}
}
void FieldLayer::moveUp()
{
	if (getCharacter()->getPoint().y >= getMap()->getSizeTile().y-1)
		return;
	if (this->getCharacterControler()->moveUp())
	{

		moveCharacter(getCharacter()->getPoint());
		if (getCharacter()->getPoint().y > 3)
			setViewPoint(Vec2(getViewPoint().x, getViewPoint().y + 1));
	}
}
void FieldLayer::moveDown()
{
	if (getCharacter()->getPoint().y <= 0)
		return;

	if (this->getCharacterControler()->moveDown())
	{

		moveCharacter(getCharacter()->getPoint());

		if (getCharacter()->getPoint().y < getMap()->getSizeTile().y - 4)
			setViewPoint(Vec2(getViewPoint().x, getViewPoint().y - 1));
	}
}

void FieldLayer::printCharacter()
{
	int tileSiz = getMap()->atTile(Vec2(0, 0))->getSize().x;
	getCharacterSprite()->setPosition(Vec2(tileSiz / 2 + getCharacter()->getPoint().x * tileSiz, tileSiz / 2 + getCharacter()->getPoint().y * tileSiz));
	this->addChild(getCharacterSprite(), 1);
}
void FieldLayer::removeCharacter()
{
	this->removeChild(getCharacterSprite());
}

void FieldLayer::onEnter()
{
	Layer::onEnter();
	
	
	this->setViewPoint(getCharacter()->getPoint());// ���̾��� ���� ����ũ�� ���� 
	viewControl();

}

void FieldLayer::onExit()
{
	
	Layer::onExit();
}

void FieldLayer::moveLayerPoint(Vec2 a_Point)
{
	int tileSiz = getMap()->atTile(Vec2(0, 0))->getSize().x;
	this->runAction(MoveTo::create(0.1f, Vec2(590 - tileSiz * (a_Point.x),310 - tileSiz * (a_Point.y))));
}

void FieldLayer::setViewPoint(Vec2 a_viewPoint) 
{
	if (a_viewPoint.x < 5)
		a_viewPoint.x = 5;

	else if (a_viewPoint.x > getMap()->getSizeTile().x - 6)
		a_viewPoint.x = getMap()->getSizeTile().x - 6;

	if (a_viewPoint.y < 3)
		a_viewPoint.y = 3;

	else if (a_viewPoint.y> getMap()->getSizeTile().y- 4)
		a_viewPoint.y = getMap()->getSizeTile().y - 4;

	this->m_viewPoint = a_viewPoint;
	this->moveLayerPoint(getViewPoint());
}

void FieldLayer::moveCharacter(Vec2 a_Point)
{
	int tileSiz = getMap()->atTile(Vec2(0, 0))->getSize().x;
	this->getCharacterSprite()->runAction(MoveTo::create(0.1, Vec2(tileSiz / 2 + tileSiz * a_Point.x, tileSiz / 2 + tileSiz * a_Point.y)));
}

void FieldLayer::viewControl()
{
	for (int i = 0; i < getMap()->getSizeTile().y; i++)
	{
		for (int j = 0; j < getMap()->getSizeTile().x; j++)
		{
			if (getViewPoint().x - 6 <= j && getViewPoint().x + 6 >= j &&
				getViewPoint().y - 4 <= i && getViewPoint().y + 4 >=i)
			{
				getMap()->atTile(Vec2(j, i))->getSprite()->setVisible(true);
			}
			else
			{
				getMap()->atTile(Vec2(j, i))->getSprite()->setVisible(false);
			}
		}
	}
}

void FieldLayer::changeMap(int index)
{
	//getMapControler()->mapChange(index);
	removeTileField();
	printTileField();
}