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


	return true;
}
void BattleLayer::printTileField()
{
	int tileSiz = getMap()->atTile(Vec2(0, 0))->getSize().x;

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			getMap()->atTile(Vec2(j, i))->getSprite()->setPosition(tileSiz / 2 + tileSiz * j, tileSiz / 2 + tileSiz * i);
			this->addChild(getMap()->atTile(Vec2(j, i))->getSprite(), 1);
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

void BattleLayer::moveCharacter(float delta)
{
	if (MovequeMax == MovequeMIn)
	{
		// 무브끝
		getBattleControler()->TurnEnd();
		return;
	}
		switch (getMoveQue())
		{
		case 1: //right
			moveRight();
		case 2: // left
			moveLeft();
		case 3: // up 
			moveUp();
		case 4: //down
			moveDown();
		default:
			break;
		}
		scheduleOnce(schedule_selector(BattleLayer::moveCharacter), 1.0f);
}

void BattleLayer::onEnter()
{
	Layer::onEnter();

	int MovequeMax=0; // 무브 큐에 서 씀 
	int MovequeMIn=0; //  위와 동일 

	getMap()->setStartPoint(Vec2(0, 0));
	getCharacter()->setPoint(getMap()->getStartPoint()); // 케릭터를 시작 위치로 설정
	this->setViewPoint(getMap()->getStartPoint());// 레이어의 시작 포인크를 설정 
	viewControl();



}

void BattleLayer::onExit()
{

	Layer::onExit();
}

void BattleLayer::makeMap()
{
	CMap *map = DynamicContentsContainer::getInstance()->getMap();  //  맵
	CCharacter* character = DynamicContentsContainer::getInstance()->getCharacter(); // 케릭터 
	Vec2 battlePoint = character->getPoint(); // x 의 기준 
	m_map = new CMap();
	

	if (battlePoint.x < 5)
		battlePoint.x = 5;

	else if (battlePoint.x > map->getSizeTile().x - 6)
		battlePoint.x = map->getSizeTile().x - 6;

	if (battlePoint.y < 3)
		battlePoint.y = 3;

	else if (battlePoint.y> map->getSizeTile().y - 4)
		battlePoint.y = map->getSizeTile().y - 4;

	int x = 0, y = 0;

	for (int i = battlePoint.x - 5; i <= battlePoint.x + 5; i++)
	{
		for (int j = battlePoint.x - 5; j <= battlePoint.x + 5; j++)
		{
			m_map->addTile(Vec2(x, y), new CTile(map->atTile(Vec2(j, i))->getName(), map->atTile(Vec2(j, i))->getSpriteRoot(), map->atTile(Vec2(j, i))->getObject(2)));
			x++;
		}
		x = 0;
		y++;
	}
}