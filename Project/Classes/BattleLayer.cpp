#include "BattleLayer.h"

bool BattleLayer::init()
{
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
	{
		return false;
	}

	printTileField(); // 필드 소환 
	printCharacter(); // 캐릭터 소환


	return true;
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