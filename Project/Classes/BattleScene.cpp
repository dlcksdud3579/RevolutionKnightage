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
		CharacterTurn();
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		if (m_battleControler->getMonGauge(i) >= 100)
		{
			m_battleControler->MonsterTurn(i);
			return;
		}
	}
}

void BattleScene::CharacterTurn()
{

}

void BattleScene::rapidAction() // 빠른 행동
{

}
void BattleScene::nomalAction() // 노말 행동
{

}

void BattleScene::endCharacterTurn()
{
	m_battleControler->setStopFlag(0);
	m_battleControler->setTurnType(0);
}