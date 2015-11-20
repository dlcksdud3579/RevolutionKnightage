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