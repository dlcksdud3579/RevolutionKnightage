#include "FieldLayer.h"
#include "math.h"
#include "FieldScene.h"
#include "StaticContentsContainer.h"

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
	this->setCharacterControler(new CCharacterControler()); //ĳ���� ��Ʈ�ѷ� ���� 
	this->setMapControler(new CMapControler()); // �� ��Ʈ�ѷ� ���� 

}

void FieldLayer::printTileField()// �� ���� 
{
	int tileSiz = getMap()->atTile(Vec2(0, 0))->getSize().x; // Ÿ�� �ϳ��� ũ�� 

	for (int i = 0; i < getMap()->getSizeTile().y; i++) //Y�� 
	{
		for (int j = 0; j < getMap()->getSizeTile().x; j++) //X�� 
		{
			getMap()->atTile(Vec2(j, i))->getSprite()->setPosition(tileSiz / 2 + tileSiz * j, tileSiz/2 + tileSiz * i);
			this->addChild(getMap()->atTile(Vec2(j, i))->getSprite(), 0);
		}
	}
}

void  FieldLayer::removeTileField()// �� ���� 
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
	checkPortal(); // ��Ż���� üũ 

	if (getCharacter()->getPoint().x >= getMap()->getSizeTile().x-1) //  �̵� �Ұ� �������� üũ 
		return;  

	if (this->getCharacterControler()->moveRight()) // ���� ���� üũ ? 
	{
		moveCharacter(getCharacter()->getPoint()); // �̵� 
		if (getCharacter()->getPoint().x > 5) // ���̾� �̵� üũ 
			setViewPoint(Vec2(getViewPoint().x + 1, getViewPoint().y)); // ���̾� �̵� 
	}
}
void FieldLayer::moveLeft()
{
	checkPortal();// ��Ż���� üũ 

	if (getCharacter()->getPoint().x <= 0) //  �̵� �Ұ� �������� üũ 
		return;
	if (this->getCharacterControler()->moveLeft()) // ���� ���� üũ ?
	{

		moveCharacter(getCharacter()->getPoint());// �̵� 

		if (getCharacter()->getPoint().x < getMap()->getSizeTile().x - 6)// ���̾� �̵� üũ 
			setViewPoint(Vec2(getViewPoint().x - 1, getViewPoint().y)); // ���̾� �̵� 
	}
}
void FieldLayer::moveUp()
{
	checkPortal();// ��Ż���� üũ 

	if (getCharacter()->getPoint().y >= getMap()->getSizeTile().y-1) //  �̵� �Ұ� �������� üũ 
		return;
	if (this->getCharacterControler()->moveUp())// ���� ���� üũ ?
	{

		moveCharacter(getCharacter()->getPoint());// �̵� 
		if (getCharacter()->getPoint().y > 3)// ���̾� �̵� üũ 
			setViewPoint(Vec2(getViewPoint().x, getViewPoint().y + 1));// ���̾� �̵�
	}
}
void FieldLayer::moveDown()
{
	checkPortal();// ��Ż���� üũ 

	if (getCharacter()->getPoint().y <= 0)//  �̵� �Ұ� �������� üũ
		return;

	if (this->getCharacterControler()->moveDown())// ���� ���� üũ ?
	{

		moveCharacter(getCharacter()->getPoint());// �̵� 

		if (getCharacter()->getPoint().y < getMap()->getSizeTile().y - 4)// ���̾� �̵� üũ 
			setViewPoint(Vec2(getViewPoint().x, getViewPoint().y - 1));// ���̾� �̵�
	}
}

void FieldLayer::printCharacter()
{
	int tileSiz = getMap()->atTile(Vec2(0, 0))->getSize().x; //Ÿ�� ũ�� 

	getCharacterSprite()->setPosition(Vec2(tileSiz / 2 + getCharacter()->getPoint().x * tileSiz, tileSiz / 2 + getCharacter()->getPoint().y * tileSiz)); //ĳ������ġ ���� 
	this->addChild(getCharacterSprite(), 1); // ���� 
}
void FieldLayer::removeCharacter()
{
	this->removeChild(getCharacterSprite()); //���� 
}

void FieldLayer::onEnter()
{
	Layer::onEnter();
	
	
	this->setViewPoint(getCharacter()->getPoint());// ���̾��� ���� ����ũ�� ���� 
	viewControl(); //������ ���� 

}

void FieldLayer::onExit()
{
	
	Layer::onExit();
}

void FieldLayer::moveLayerPoint(Vec2 a_Point)
{
	int tileSiz = getMap()->atTile(Vec2(0, 0))->getSize().x; // Ÿ�� ũ�� 
	this->runAction(MoveTo::create(0.1f, Vec2(590 - tileSiz * (a_Point.x),310 - tileSiz * (a_Point.y)))); //�̵� 
}

void FieldLayer::setViewPoint(Vec2 a_viewPoint) 
{
	if (a_viewPoint.x < 5) // x�� 5���������� 5�� 
		a_viewPoint.x = 5;

	else if (a_viewPoint.x > getMap()->getSizeTile().x - 6) // x�� ��ũ�� -6 ���������� ��ũ�� -6�� 
		a_viewPoint.x = getMap()->getSizeTile().x - 6;

	if (a_viewPoint.y < 3) //y�� 3���������� 3��
		a_viewPoint.y = 3; //y�� 3���������� 3��

	else if (a_viewPoint.y> getMap()->getSizeTile().y- 4) // y�� ��ũ�� -4 ���������� ��ũ�� -4�� 
		a_viewPoint.y = getMap()->getSizeTile().y - 4; // y�� ��ũ�� -4 ���������� ��ũ�� -4��  

	this->m_viewPoint = a_viewPoint; //���� 
	this->moveLayerPoint(getViewPoint()); //�̵� 
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

void FieldLayer::changeMap(string MapKey) // ��ü����
{
	CMap * map = StaticContentsContainer::getMapMap()->find(MapKey)->second;
	CCharacter * hero = DynamicContentsContainer::getInstance()->getCharacter();
	DynamicContentsContainer::getInstance()->setMap(map);
	DynamicContentsContainer::getInstance()->getCharacter()->setPoint(DynamicContentsContainer::getInstance()->getMap()->getStartPoint());
	auto	fieldScene = FieldScene::createScene();
	Director::getInstance()->replaceScene(fieldScene);
	for (int i = 0; i < 10; i++)
	{
		if (DynamicContentsContainer::getInstance()->getMonster(i) == NULL)
			break;
	///	delete(DynamicContentsContainer::getInstance()->getMonster(i));
		DynamicContentsContainer::getInstance()->setMonster(NULL, i);
	}
}
void FieldLayer::checkPortal() // ��Ż ��ġ�� ����� 
{
	CCharacter * hero = DynamicContentsContainer::getInstance()->getCharacter();
	CMap * map = DynamicContentsContainer::getInstance()->getMap();

	for (int i = 0; i < 10; i++)
	{
		if (map->getPortal(i) == NULL) //  ����Ż üũ 
			continue;
		if (hero->getPoint() == map->getPortal(i)->getPoint())  // ���� ��ġ���� üũ
			changeMap(map->getPortal(i)->getName());
	}
}