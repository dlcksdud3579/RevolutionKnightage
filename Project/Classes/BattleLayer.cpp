#include "BattleLayer.h"

bool BattleLayer::init()
{
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
	{
		return false;
	}
	setCharacterSprite(Sprite::create(getCharacter()->getSpriteRoot()));
	makeMap();
	printTileField(); // 필드 소환 
	printCharacter(); // 캐릭터 소환
	printMonster();
	MovequeMax=0;
	MovequeMIn=0;
	this->setViewPoint(getCharacter()->getPoint());// 레이어의 시작 포인크를 설정 

	return true;
}
void BattleLayer::printTileField()
{
	int tileSiz = getMap()->atTile(Vec2(0, 0))->getSize().x;

	for (int i = 0; i < getMap()->getSizeTile().y; i++)
	{
		for (int j = 0; j < getMap()->getSizeTile().x; j++)
		{
			getMap()->atTile(Vec2(j, i))->getSprite()->setPosition(tileSiz / 2 + tileSiz * j, tileSiz / 2 + tileSiz * i);
			this->addChild(getMap()->atTile(Vec2(j, i))->getSprite(), 0);
		}
	}
}

void  BattleLayer::removeTileField()
{

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			this->removeChild(getMap()->atTile(Vec2(j, i))->getSprite());
		}
	}
}

float BattleLayer::moveSchedule()
{
	float rv = 0.2f; //인터발 타임
	schedule(schedule_selector(BattleLayer::move), rv);
	return rv;
}

void BattleLayer::move(float delta)
{
	if (MovequeMax <= MovequeMIn)
	{
		// 무브끝
		this->getBattleControler()->setTempPoint(Vec2(getCharacter()->getPoint().x - getViewPoint().x + 5
			,getCharacter()->getPoint().y- getViewPoint().y + 3));

		unschedule(schedule_selector(BattleLayer::move));
		MovequeMax = 0;
		MovequeMIn = 0;
		return;
	}
		switch (getMoveQue())
		{
		case 1: //right
			moveRight();
			break;
		case 2: // left
			moveLeft();
			break;
		case 3: // up 
			moveUp();
			break;
		case 4: //down
			moveDown();
			break;
		default:
			break;
		}
		this->viewControl();
}

void BattleLayer::onEnter()
{
	Layer::onEnter();

	int MovequeMax=0; // 무브 큐에 서 씀 
	int MovequeMIn=0; //  위와 동일 

	//getMap()->setStartPoint(Vec2(0, 0));
	//getCharacter()->setPoint(getMap()->getStartPoint()); // 케릭터를 시작 위치로 설정
	
	viewControl();

}

void BattleLayer::onExit()
{

	Layer::onExit();
}

void BattleLayer::makeMap()
{
	CMap *map = DynamicContentsContainer::getInstance()->getMap();  //  맵
	m_map = new CMap();
	m_map->setSizeTile(map->getSizeTile());
	for (int i = 0; i < map->getSizeTile().x; i++)
	{
		for (int j = 0; j < map->getSizeTile().y ; j++)
		{
			m_map->addTile(Vec2(j, i), new CTile(map->atTile(Vec2(j, i))->getName(), map->atTile(Vec2(j, i))->getSpriteRoot(), map->atTile(Vec2(j, i))->getObject(2)));
		}
	}
}

void BattleLayer::printMonster()
{
	CMonster* mon[10];
	for (int i = 0; i < 10; i++)
	{
		if (DynamicContentsContainer::getInstance()->getMonster(i) == NULL)
			continue;
		mon[i] = DynamicContentsContainer::getInstance()->getMonster(i);
		mon[i]->getSprite()->setPosition(Vec2(mon[i]->getPoint().x * 100 + 140, mon[i]->getPoint().y * 100 + 60));
		addChild(mon[i]->getSprite());
	}
}
void BattleLayer::removeMonster()
{
	CMonster* mon[10];
	for (int i = 0; i < 10; i++)
	{
		mon[i] = DynamicContentsContainer::getInstance()->getMonster(i);
		removeChild(mon[i]->getSprite());
	}
}

void BattleLayer::removeMonster(int index)
{
	CMonster*mon = DynamicContentsContainer::getInstance()->getMonster(index);
	removeChild(mon->getSprite());
}
void BattleLayer::monstermove(int index)
{
	CMonster*mon = DynamicContentsContainer::getInstance()->getMonster(index);
	CMap* map = DynamicContentsContainer::getInstance()->getMap();
	Vec2 a_Point;

	Vec2 moveVec2  = mon->getMove();

	if (mon->getPoint().x + moveVec2.x >= map->getSizeTile().x - 1 ||
		mon->getPoint().y + moveVec2.y >= map->getSizeTile().y - 1 ||
		mon->getPoint().x + moveVec2.x <= 0 || mon->getPoint().y + moveVec2 .y<= 0)
		return;

	a_Point = Vec2(mon->getPoint().x + moveVec2.x, mon->getPoint().y + moveVec2.y);

	int tileSiz = 100;
	mon->getSprite()->runAction(MoveTo::create(0.1, Vec2(tileSiz / 2 + tileSiz * a_Point.x, tileSiz / 2 + tileSiz * a_Point.y)));
}