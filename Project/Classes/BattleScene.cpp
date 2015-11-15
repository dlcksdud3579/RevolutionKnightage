#include "BattleScene.h"

Scene* BattleScene::createScene()
{
	auto scene = Scene::create();

	auto layer = BattleScene::create();

	scene->addChild(layer);

	return scene;
}

bool BattleScene::init()
{

	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
	{
		return false;
	}

	m_battleControler = new BattleControler();
	m_battleLayer = new BattleLayer();

	schedule(schedule_selector(BattleScene::run),1.0f);

	return true;
}
void BattleScene::onEnter()
{
	Layer::onEnter();

	auto listener = EventListenerTouchOneByOne::create();

	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(BattleScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(BattleScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(BattleScene::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

}

void BattleScene::onExit()
{
	_eventDispatcher->removeEventListenersForType(EventListener::Type::TOUCH_ONE_BY_ONE);

	Layer::onExit();
}

bool BattleScene::onTouchBegan(Touch* touch, Event* event)
{
	if (m_battleControler->getTurnType() != 3)
		return false;
}
void BattleScene::onTouchMoved(Touch* touch, Event* event)
{

}
void BattleScene::onTouchEnded(Touch* touch, Event* event)
{

}

void BattleScene::run(float delta) // 0.2초마다
{
	m_battleControler->timeUp();
	if (m_battleControler->getCharacterGauge() >= 100)
	{
		m_battleControler->setStopFlag(1);
		CharacterTurn();
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		if (m_battleControler->getMonGauge(i) >= 100)
		{
			m_battleControler->setStopFlag(1);
			m_battleControler->MonsterTurn(i);
			return;
		}
	}
}

void BattleScene::CharacterTurn()
{
	rapidAction();
	nomalAction();
}

void BattleScene::rapidAction() // 빠른 행동
{
	printRapidMenu();

}
void BattleScene::nomalAction() // 노말 행동
{
	printNomalMenu();

}

void BattleScene::endCharacterTurn()
{
	m_battleControler->setStopFlag(0);
	m_battleControler->setTurnType(0);
}

void BattleScene::printRapidMenu()
{
	int r3 = 1.7; //루트 3 
	int PointX = DynamicContentsContainer::getInstance()->getCharacter()->getPoint().x;
	int PointY = DynamicContentsContainer::getInstance()->getCharacter()->getPoint().y;

	Label* moveLable = Label::create("MOVE", "fonts/arial.ttf", 36);
	moveLable->setPosition(PointX + 50 * r3, PointY + 50);
	moveLable->setTag(10);

	Label* InvenLable = Label::create("BAG", "fonts/arial.ttf", 36);
	InvenLable->setPosition(PointX - 50 * r3, PointY - 50);
	InvenLable->setTag(11);

	Label* escLable = Label::create("ESC", "fonts/arial.ttf", 36);
	escLable->setPosition(PointX - 50 * r3, PointY + 50);
	escLable->setTag(12);

	this->addChild(moveLable);
	this->addChild(InvenLable);
	this->addChild(escLable);
}



void BattleScene::printNomalMenu()
{
	int r3 = 1.7; //루트 3 

	int PointX = DynamicContentsContainer::getInstance()->getCharacter()->getPoint().x;
	int PointY = DynamicContentsContainer::getInstance()->getCharacter()->getPoint().y;

	Label* actionLable = Label::create("ACTION", "fonts/arial.ttf", 36);
	actionLable->setPosition(PointX + 50 * r3, PointY + 50);
	actionLable->setTag(20);

	Label* attakLable = Label::create("ATTACK", "fonts/arial.ttf", 36);
	attakLable->setPosition(PointX, PointY + 100);
	attakLable->setTag(21);

	Label* endLable = Label::create("END", "fonts/arial.ttf", 36);
	endLable->setPosition(PointX, PointY - 100);
	endLable->setTag(22);

	this->addChild(actionLable);
	this->addChild(attakLable);
	this->addChild(endLable);
}
void  BattleScene::removeRapidMenu()
{
	this->removeChildByTag(10);
	this->removeChildByTag(11);
	this->removeChildByTag(12);
		
}
void  BattleScene::removeNomalMenu()
{
	this->removeChildByTag(20);
	this->removeChildByTag(21);
	this->removeChildByTag(22);
}
void BattleScene::chooseRapidMenu(Object* pSender)
{
	auto item = (MenuItem*)pSender;
	int index = item->getTag();

	switch (index)
	{
	case 10:
		m_battleControler->setTurnType(3); // move
		break;
	case 11:
		m_battleControler->setTurnType(2); // 가방
		break;
	case 12:
		m_battleControler->setTurnType(1); //도망
		break;
	default:
		return;
		break;
	}
	removeRapidMenu();
}
void BattleScene::chooseNomalMenu(Object* pSender)
{
	auto item = (MenuItem*)pSender;
	int index = item->getTag();

	switch (index)
	{
	case 20:
		m_battleControler->setTurnType(4); // 액션
		break;
	case 21:
		m_battleControler->setTurnType(5); //공격
		break;
	case 22:
		m_battleControler->setTurnType(6); // 종료

		break;
	default:
		return;
		break;
	}
	removeRapidMenu();
	removeNomalMenu();
}