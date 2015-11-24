#include "BattleScene.h"
#include "DynamicContentsContainer.h"

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

	setBattleControler(new BattleControler());

	this->setBattleLayer(BattleLayer::create());
	getBattleLayer()->setBattleControler(getBattleControler());

	setBattleMenuLayer(BattleMenuLayer::create());
	getBattleMenuLayer()->setBattleControler(getBattleControler());

	m_invenLayer = InvenLayer::create();


	this->addChild(m_battleLayer);
	this->addChild(getBattleMenuLayer());
	this->setInvenLayer(m_invenLayer);

	schedule(schedule_selector(BattleScene::run),0.5f); // 배틀에서 속도를 올려주는함수 
	this->getBattleControler()->setTempPoint(Vec2(getBattleLayer()->getCharacter()->getPoint().x - getBattleLayer()->getViewPoint().x + 5
		, getBattleLayer()->getCharacter()->getPoint().y - getBattleLayer()->getViewPoint().y + 3));


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

void BattleScene::movedMenu(float delta)
{
	this->getBattleControler()->setTempPoint(Vec2(getBattleLayer()->getCharacter()->getPoint().x - getBattleLayer()->getViewPoint().x + 5
		, getBattleLayer()->getCharacter()->getPoint().y - getBattleLayer()->getViewPoint().y + 3));
	getBattleMenuLayer()->printNomalMenu();

}

bool BattleScene::onTouchBegan(Touch* touch, Event* event)
{
	if (m_battleControler->getTurnType() != 3&&m_battleControler->getTurnType() != 5) // 이동이 아닐시 터치입력 X
		return false;

	int touchX = touch->getLocation().x;
	int touchY = touch->getLocation().y;

	int movePointX = getBattleControler()->getTempPoint().x * 100 + 140;
	int movePointY = getBattleControler()->getTempPoint().y * 100 + 60;

	if (m_battleControler->getTurnType() == 5)
	{
		if (m_battleControler->getCurSkill() == NULL)
		{
			log("attack:NULL");
			getBattleControler()->TurnEnd();
			return false;
		}

		int r = getBattleControler()->getCurSkill()->getRange();

		if (movePointX - 50 - 100 * r < touchX && touchX < movePointX + 50 + 100 * r && movePointY - 50 - 100 * r < touchY && touchY < movePointY + 50 + 100 * r)
		{
			Vec2 attackPoint;
			attackPoint.x = (touchX - 140) / 100 + getBattleLayer()->getViewPoint().x - 5;
			attackPoint.y = (touchY - 60) / 100 + getBattleLayer()->getViewPoint().y - 3;
			getBattleControler()->damageMon(attackPoint);
			checkdie();
			log("attack");
			endCharacterTurn();
			getBattleControler()->TurnEnd();
		}
		else
		{
			log("attack::NOT");
			return false;
		}
	}
	return true;
}

void BattleScene::onTouchMoved(Touch* touch, Event* event)  // 이동구현으로만 쓰임 
{
	int touchX = touch->getLocation().x;
	int touchY = touch->getLocation().y;

	int movePointX = getBattleControler()->getTempPoint().x * 100 + 140;
	int movePointY = getBattleControler()->getTempPoint().y * 100 + 60;

	if (m_battleControler->getTurnType() == 3) // 이동이 아닐시 터치입력 X
	{
		if (this->getBattleControler()->getMoveCnt() >= DynamicContentsContainer::getInstance()->getCharacter()->getStatus()->getMvp())  // mvp 만큼 이동 가능 체크
		{
			m_battleControler->setTurnType(0);
			float movingTime = getBattleLayer()->moveSchedule();
			getBattleMenuLayer()->removeNomalMenu();
			scheduleOnce(schedule_selector(BattleScene::movedMenu), 5 * movingTime);
			return;
		}

		log("movePoint: %d %d \nTouch: %d %d \n", movePointX, movePointY, touchX, touchY);

		if (movePointX - 50 < touchX && touchX < movePointX + 50 && movePointY - 50 < touchY && touchY < movePointY + 50)
		{
			log("move::CUR");
		}
		else if (movePointX - 50 + 100 < touchX && touchX < movePointX + 50 + 100 && movePointY - 50 < touchY && touchY < movePointY + 50)
		{
			getBattleLayer()->setMoveQue(1); // 앞
			getBattleControler()->setTempPoint(Vec2(getBattleControler()->getTempPoint().x + 1, getBattleControler()->getTempPoint().y));
			log("move::RIGHT");
			getBattleControler()->setMoveCnt(getBattleControler()->getMoveCnt() + 1); // 카운터++;
		}
		else if (movePointX - 50 - 100 < touchX && touchX < movePointX + 50 - 100 && movePointY - 50 < touchY && touchY < movePointY + 50)
		{
			getBattleLayer()->setMoveQue(2); // 뒤
			getBattleControler()->setTempPoint(Vec2(getBattleControler()->getTempPoint().x - 1, getBattleControler()->getTempPoint().y));
			log("move::LEFT");
			getBattleControler()->setMoveCnt(getBattleControler()->getMoveCnt() + 1); // 카운터++;
		}
		else if (movePointX - 50 < touchX && touchX < movePointX + 50 && movePointY - 50 + 100 < touchY && touchY < movePointY + 50 + 100)
		{
			getBattleLayer()->setMoveQue(3);//위
			getBattleControler()->setTempPoint(Vec2(getBattleControler()->getTempPoint().x, getBattleControler()->getTempPoint().y + 1));
			log("move::UP");
			getBattleControler()->setMoveCnt(getBattleControler()->getMoveCnt() + 1); // 카운터++;
		}
		else if (movePointX - 50 < touchX && touchX < movePointX + 50 && movePointY - 50 - 100 < touchY && touchY < movePointY + 50 - 100)
		{
			getBattleLayer()->setMoveQue(4); // 아래 
			getBattleControler()->setTempPoint(Vec2(getBattleControler()->getTempPoint().x, getBattleControler()->getTempPoint().y - 1));
			log("move::DOWN");
			getBattleControler()->setMoveCnt(getBattleControler()->getMoveCnt() + 1); // 카운터++;
		}
		else
		{
			log("move::NOT");
			return;
		}
	}

}

void BattleScene::onTouchEnded(Touch* touch, Event* event)
{
	if (m_battleControler->getTurnType() == 3) // 이동이 아닐시 터치입력 X
	{
		m_battleControler->setTurnType(0);
		float movingTime = getBattleLayer()->moveSchedule();
		getBattleMenuLayer()->removeNomalMenu();
		scheduleOnce(schedule_selector(BattleScene::movedMenu), 5 * movingTime);
		return;
	}
}

void BattleScene::run(float delta) // 0.2초마다
{
	if (m_battleControler->isStopFlag() == 1)
		return;

	m_battleControler->timeUp();
	if (m_battleControler->getCharacterGauge() >= 100)
	{
		m_battleControler->setStopFlag(1);
		m_battleControler->setCharacterGauge(0);
		CharacterTurn();
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		if (m_battleControler->getMonGauge(i) >= 100)
		{
			log("Monster");
			getBattleLayer()->monstermove(i);
			m_battleControler->setMonsterDir(i);
			m_battleControler->monsterAttack(i);
			m_battleControler->MonsterTurn(i);
			m_battleControler->setMonGauge(0, i);
			dieCharacter();
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
	getBattleMenuLayer()->printRapidMenu();

}
void BattleScene::nomalAction() // 노말 행동
{
	getBattleMenuLayer()->printNomalMenu();

}

void BattleScene::endCharacterTurn()
{
	m_battleControler->setStopFlag(0);
	m_battleControler->setTurnType(0);
}

void  BattleScene::openInven()
{
	if (getInvenLayer()->isOpenFlag() == false)
	{
		log("open");
		getInvenLayer()->Open();
	}
	else if (getInvenLayer()->isOpenFlag() == true)
	{
		log("close");
		getInvenLayer()->Close();
	}
}


void BattleScene::checkdie()
{
	CMonster* mon[10];
	for (int i = 0; i < 10; i++)
	{
		if (DynamicContentsContainer::getInstance()->getMonster(i) == NULL)
			continue;
		mon[i] = DynamicContentsContainer::getInstance()->getMonster(i);

		if (mon[i]->getStatus()->getHp() <= 0)
		{
			getBattleLayer()->removeMonster(i);
			getBattleControler()->dieMon(i);
		}
	}
}
void BattleScene::dieCharacter()
{
	if (DynamicContentsContainer::getInstance()->getCharacter()->getStatus()->getHp() <= 0)
	{
		Director::getInstance()->restart();
	}

}