#include "BattleLayer.h"

bool BattleLayer::init()
{
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
	{
		return false;
	}

	printTileField(); // �ʵ� ��ȯ 
	printCharacter(); // ĳ���� ��ȯ


	return true;
}

void BattleLayer::moveCharacter(float delta)
{
	if (MovequeMax == MovequeMIn)
	{
		// ���곡
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

	int MovequeMax=0; // ���� ť�� �� �� 
	int MovequeMIn=0; //  ���� ���� 

	getMap()->setStartPoint(Vec2(0, 0));
	getCharacter()->setPoint(getMap()->getStartPoint()); // �ɸ��͸� ���� ��ġ�� ����
	this->setViewPoint(getMap()->getStartPoint());// ���̾��� ���� ����ũ�� ���� 
	viewControl();



}

void BattleLayer::onExit()
{

	Layer::onExit();
}