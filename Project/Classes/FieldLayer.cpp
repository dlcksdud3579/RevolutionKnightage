#include "FieldLayer.h"
#include "math.h"
#include "StaticContentsContainer.h"
#include "NFieldScene.h"

USING_NS_CC;

bool FieldLayer::init()
{
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
	{
		return false;
	}

	setCharacterSprite(Sprite::create(getCharacter()->getSpriteRoot())); // ĳ����� �̹��� ���

	printTileField();// 
	printCharacter(); // ĳ���� ����Ʈ 
	makeMonster(); // ���� 
	printMonster(); // ����Ʈ ���� 

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

bool FieldLayer::moveRight()
{
	checkPortal(); // ��Ż���� üũ 

	if (getCharacter()->getPoint().x >= getMap()->getSizeTile().x - 1) //  �̵� �Ұ� �������� üũ // �ʻ����� �̻� �Ұ� üũ 
		return false;

	if (this->getCharacterControler()->moveRight()) // ���� ���� üũ ? 
	{
		moveCharacter(getCharacter()->getPoint()); // �̵� 
		if (getCharacter()->getPoint().x > 5) // ���̾� �̵� üũ 
			setViewPoint(Vec2(getViewPoint().x + 1, getViewPoint().y)); // ���̾� �̵� 
		this->getTurnControler()->setMenuPoint(Vec2(getCharacter()->getPoint().x - getViewPoint().x + 5
			, getCharacter()->getPoint().y - getViewPoint().y + 3));

		return true;
	}
	return false;
}

bool FieldLayer::moveLeft()
{
	checkPortal();// ��Ż���� üũ 

	if (getCharacter()->getPoint().x <= 0) //  �̵� �Ұ� �������� üũ 
		return false;
	if (this->getCharacterControler()->moveLeft()) // ���� ���� üũ ?
	{

		moveCharacter(getCharacter()->getPoint());// �̵� 

		if (getCharacter()->getPoint().x < getMap()->getSizeTile().x - 6)// ���̾� �̵� üũ 
			setViewPoint(Vec2(getViewPoint().x - 1, getViewPoint().y)); // ���̾� �̵� 
		this->getTurnControler()->setMenuPoint(Vec2(getCharacter()->getPoint().x - getViewPoint().x + 5
			, getCharacter()->getPoint().y - getViewPoint().y + 3));

		return true;
	}
	return false;
}

bool FieldLayer::moveUp()
{
	checkPortal();// ��Ż���� üũ 

	if (getCharacter()->getPoint().y >= getMap()->getSizeTile().y-1) //  �̵� �Ұ� �������� üũ 
		return false;
	if (this->getCharacterControler()->moveUp())// ���� ���� üũ ?
	{

		moveCharacter(getCharacter()->getPoint());// �̵� 
		if (getCharacter()->getPoint().y > 3)// ���̾� �̵� üũ 
			setViewPoint(Vec2(getViewPoint().x, getViewPoint().y + 1));// ���̾� �̵�
		this->getTurnControler()->setMenuPoint(Vec2(getCharacter()->getPoint().x - getViewPoint().x + 5
			, getCharacter()->getPoint().y - getViewPoint().y + 3));

		return true;
	}
	return false;
}

bool FieldLayer::moveDown()
{
	checkPortal();// ��Ż���� üũ 

	if (getCharacter()->getPoint().y <= 0)//  �̵� �Ұ� �������� üũ
		return false;

	if (this->getCharacterControler()->moveDown())// ���� ���� üũ ?
	{

		moveCharacter(getCharacter()->getPoint());// �̵� 

		if (getCharacter()->getPoint().y < getMap()->getSizeTile().y - 4)// ���̾� �̵� üũ 
			setViewPoint(Vec2(getViewPoint().x, getViewPoint().y - 1));// ���̾� �̵�
		this->getTurnControler()->setMenuPoint(Vec2(getCharacter()->getPoint().x - getViewPoint().x + 5
			, getCharacter()->getPoint().y - getViewPoint().y + 3));

		return true;
	}
	return false;
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
	this->getTurnControler()->setMenuPoint(Vec2(getCharacter()->getPoint().x - getViewPoint().x + 5
		, getCharacter()->getPoint().y - getViewPoint().y + 3));

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

void FieldLayer::changeMap(int PortalIndex) // �ʸ�ü����
{
	
	CMap * map = StaticContentsContainer::readMapMap(DynamicContentsContainer::getInstance()->getMap()->getPortal(PortalIndex)->getLinkedMapKey()); // ����ʸ�
	DynamicContentsContainer::getInstance()->setStartingPoint(DynamicContentsContainer::getInstance()->getMap()->getPortal(PortalIndex)->getLinkedPoint()); // ��������Ʈ ���� 

	CCharacter * hero = DynamicContentsContainer::getInstance()->getCharacter();
	DynamicContentsContainer::getInstance()->setMap(map); // ���ʸ� ���� 

	DynamicContentsContainer::getInstance()->getCharacter()->
		setPoint(DynamicContentsContainer::getInstance()->getStartingPoint()); // �ð�����Ʈ ���� 

	deleteMonster(); // ��Ÿ ����

	auto	fieldScene = NFieldScene::createScene(); // ���� 
	Director::getInstance()->replaceScene(fieldScene); // ����ü

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
			changeMap(i);
	}
}

void FieldLayer::printMonster()
{
	CMonster* mon[10];

	for (int i = 0; i < 10; i++)
	{
		if (DynamicContentsContainer::getInstance()->getMonster(i) == NULL)
			continue;
		mon[i] = DynamicContentsContainer::getInstance()->getMonster(i);
		mon[i]->getSprite()->setPosition(Vec2(mon[i]->getPoint().x * 100 + 50, mon[i]->getPoint().y * 100 + 50));
		addChild(mon[i]->getSprite());
	}
}

void FieldLayer::removeMonster()
{
	CMonster* mon[10];
	for (int i = 0; i < 10; i++)
	{
		mon[i] = DynamicContentsContainer::getInstance()->getMonster(i);
		removeChild(mon[i]->getSprite());
	}
}

void FieldLayer::removeMonster(int index)
{
	CMonster*mon = DynamicContentsContainer::getInstance()->getMonster(index);
	removeChild(mon->getSprite());
}

void FieldLayer::monstermove(int index)
{
	CMonster*mon = DynamicContentsContainer::getInstance()->getMonster(index);
	CMap* map = DynamicContentsContainer::getInstance()->getMap();
	Vec2 a_Point;


	Vec2 moveVec2 = mon->getMove();
	if (mon->getPoint().x + moveVec2.x >= map->getSizeTile().x - 1 ||
		mon->getPoint().y + moveVec2.y >= map->getSizeTile().y - 1 ||
		mon->getPoint().x + moveVec2.x <= 0 || mon->getPoint().y + moveVec2.y <= 0)
		return;

	CCharacterControler *monCon = new CCharacterControler(mon);
	switch ((int)moveVec2.x)
	{
	case 1:
		if (moveVec2.y == 0)
			monCon->moveRight();
		break;
	case 0:
		switch ((int)moveVec2.y)
		{
		case 1:
			monCon->moveUp();
			break;
		case 0:
			break;
		case -1:
			monCon->moveDown();
			break;
		default:
			break;
		}
		break;
	case -1:
		if (moveVec2.y == 0)
			monCon->moveLeft();
		break;
	default:
		break;
	}
	a_Point = mon->getPoint();
	int tileSiz = 100;
	mon->getSprite()->runAction(MoveTo::create(0.1, Vec2(tileSiz / 2 + tileSiz * a_Point.x, tileSiz / 2 + tileSiz * a_Point.y)));

}

void FieldLayer::makeMonster() // ���� ��� 
{
	CMap *map = DynamicContentsContainer::getInstance()->getMap(); //���� �� 
	string mapKey = map->getKey(); // ���� Ű��ȣ�� �޾ƿ�

	CMonster *temp; 
	CMonster *monster[10]; // 10���� ���� ��ȯ
	CObject **object = StaticContentsContainer::getMapMonsterArray()->find(mapKey)->second; // ������ �������� 

	CSkill* tempSkill; //���� ��ų?
	int skillNum = 0;
	;
	for (int i = 0; i < 10; i++) // �� 10������ �ս��� 
	{
		if (object[i] == NULL)
			continue;

		temp = StaticContentsContainer::getMapMonster()->find(object[i]->getName())->second; // ���ʹ� 

		monster[i] = new CMonster(temp->getName(), temp->getSpriteRoot()); //���� ������ 
		monster[i]->setStatus(new Status(temp->getStatus()->getHp(), // ���� �������ͽ� 
			temp->getStatus()->getSpeed(),
			temp->getStatus()->getDef(),
			temp->getStatus()->getStr(),
			temp->getStatus()->getDex(),
			temp->getStatus()->getIns(),
			temp->getStatus()->getKno()));


		// ���� ���� ���� ��ų ������ ���� �ϵ��� �սô�.//
		tempSkill = new CSkill(temp->getSkill(skillNum)->getName(), //���� ��ų 
			temp->getSkill(skillNum)->getRange(),
			temp->getSkill(skillNum)->getDiceType(),
			temp->getSkill(skillNum)->getDiceNum(),
			temp->getSkill(skillNum)->getAttribute(),
			temp->getSkill(skillNum)->getAccuracyRate());
		for (int j = 0; temp->getSkill(skillNum)->getSplash(j) != Vec2(0, 0); j++)
			tempSkill->setSplash(temp->getSkill(skillNum)->getSplash(j), j);
		monster[i]->setSkill(tempSkill, skillNum);
		monster[i]->setPoint(object[i]->getPoint());
		monster[i]->setDir(2);
		DynamicContentsContainer::getInstance()->setMonster(monster[i], i);
	}

}
void FieldLayer::deleteMonster() // ��Ÿ�� ����
{
	for (int i = 0; i < 10; i++)
	{
		DynamicContentsContainer::getInstance()->setMonster(NULL, i);
	}

}
