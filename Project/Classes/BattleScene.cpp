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

	schedule(schedule_selector(BattleScene::run),1.0f); // 배틀에서 속도를 올려주는함수 
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

	getBattleMenuLayer()->printNomalMenu();
}

bool BattleScene::onTouchBegan(Touch* touch, Event* event)
{
	if (m_battleControler->getTurnType() != 3) // 이동이 아닐시 터치입력 X
		return false;


}

void BattleScene::onTouchMoved(Touch* touch, Event* event)  // 이동구현으로만 쓰임 
{
	if (m_battleControler->getTurnType() != 3) // 이동이 아닐시 터치입력 X
		return;

	if (this->getBattleControler()->getMoveCnt() >= 4)
	{
		m_battleControler->setTurnType(0);
		float movingTime = getBattleLayer()->moveSchedule();
		getBattleMenuLayer()->removeNomalMenu();
		scheduleOnce(schedule_selector(BattleScene::movedMenu), 5 * movingTime);
		return;
	}

	CCharacter * Character = DynamicContentsContainer::getInstance()->getCharacter();
	
	int touchX = touch->getLocation().x;
	int touchY = touch->getLocation().y;

	int movePointX = getBattleControler()->getTempPoint().x*100 + 140;
	int movePointY = getBattleControler()->getTempPoint().y*100 + 60;

	log("movePoint: %d %d \nTouch: %d %d \n", movePointX, movePointY, touchX, touchY);
	
	if (movePointX - 50 < touchX && touchX < movePointX + 50 && movePointY - 50 < touchY && touchY < movePointY + 50)
	{
		log("move::CUR");
	}
	else if (movePointX - 50 + 100< touchX && touchX  < movePointX + 50 + 100 && movePointY - 50 < touchY && touchY < movePointY + 50)
	{
		getBattleLayer()->setMoveQue(1); // 앞
		getBattleControler()->setTempPoint(Vec2(getBattleControler()->getTempPoint().x + 1, getBattleControler()->getTempPoint().y));
		log("move::RIGHT");
		getBattleControler()->setMoveCnt(getBattleControler()->getMoveCnt() + 1); // 카운터++;
	}
	else if (movePointX - 50 - 100< touchX && touchX  < movePointX + 50 - 100 && movePointY - 50 < touchY && touchY < movePointY + 50)
	{
		getBattleLayer()->setMoveQue(2); // 뒤
		getBattleControler()->setTempPoint(Vec2(getBattleControler()->getTempPoint().x - 1, getBattleControler()->getTempPoint().y));
		log("move::LEFT");
		getBattleControler()->setMoveCnt(getBattleControler()->getMoveCnt() + 1); // 카운터++;
	}
	else if (movePointX - 50 < touchX && touchX  < movePointX + 50 && movePointY - 50 + 100< touchY && touchY < movePointY + 50 + 100)
	{
		getBattleLayer()->setMoveQue(3);//위
		getBattleControler()->setTempPoint(Vec2(getBattleControler()->getTempPoint().x, getBattleControler()->getTempPoint().y+1));
		log("move::UP");
		getBattleControler()->setMoveCnt(getBattleControler()->getMoveCnt() + 1); // 카운터++;
	}
	else if (movePointX - 50 < touchX && touchX  < movePointX + 50 && movePointY - 50 - 100< touchY && touchY < movePointY + 50 - 100)
	{
		getBattleLayer()->setMoveQue(4); // 아래 
		getBattleControler()->setTempPoint(Vec2(getBattleControler()->getTempPoint().x , getBattleControler()->getTempPoint().y-1));
		log("move::DOWN");
		getBattleControler()->setMoveCnt(getBattleControler()->getMoveCnt() + 1); // 카운터++;
	}
	else
	{
		log("move::NOT");
		return;
	}
}
void BattleScene::onTouchEnded(Touch* touch, Event* event)
{
	m_battleControler->setTurnType(0);
	getBattleLayer()->moveSchedule();
	return;
}

void BattleScene::run(float delta) // 0.2초마다
{
	if (m_battleControler->isStopFlag() == 1)
		return;

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
/*
void BattleScene::printRapidMenu()
{
	int r3 = 1.7; //루트 3 

	int PointX = DynamicContentsContainer::getInstance()->getCharacter()->getPoint().x*100;
	int PointY = DynamicContentsContainer::getInstance()->getCharacter()->getPoint().y*100;

	Label* moveLable = Label::create("MOVE", "fonts/arial.ttf", 36);
	moveLable->setPosition(PointX + 50 * r3, PointY + 50);
	moveLable->setTag(10);

	Label* InvenLable = Label::create("BAG", "fonts/arial.ttf", 36);
	InvenLable->setPosition(PointX - 50 * r3, PointY - 50);
	InvenLable->setTag(11);

	Label* escLable = Label::create("ESC", "fonts/arial.ttf", 36);
	escLable->setPosition(PointX - 50 * r3, PointY + 50);
	escLable->setTag(12);

	this->addChild(moveLable,10);
	this->addChild(InvenLable,10);
	this->addChild(escLable,10);
}

void BattleScene::printNomalMenu()
{
	int r3 = 1.7; //루트 3 

	int PointX = DynamicContentsContainer::getInstance()->getCharacter()->getPoint().x*100;
	int PointY = DynamicContentsContainer::getInstance()->getCharacter()->getPoint().y*100;

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
void  BattleScene::printActionMenu()
{
	int r3 = 1.7; //루트 3 
	int PointX = DynamicContentsContainer::getInstance()->getCharacter()->getPoint().x*100;
	int PointY = DynamicContentsContainer::getInstance()->getCharacter()->getPoint().y*100;

	Label* Action1Lable = Label::create("MOVE", "fonts/arial.ttf", 36);
	Action1Lable->setPosition(PointX + 50 * r3, PointY + 50);
	Action1Lable->setTag(30);

	Label* Action2Lable = Label::create("BAG", "fonts/arial.ttf", 36);
	Action2Lable->setPosition(PointX - 50 * r3, PointY - 50);
	Action2Lable->setTag(31);

	Label* Action3Lable = Label::create("ESC", "fonts/arial.ttf", 36);
	Action3Lable->setPosition(PointX - 50 * r3, PointY + 50);
	Action3Lable->setTag(32);

	this->addChild(Action1Lable);
	this->addChild(Action2Lable);
	this->addChild(Action3Lable);
}
void  BattleScene::removeActionMenu()
{
	this->removeChildByTag(30);
	this->removeChildByTag(31);
	this->removeChildByTag(32);
}
*/
//void BattleScene::chooseRapidMenu(Object* pSender)
//{
//	auto item = (MenuItem*)pSender;
//	int index = item->getTag();
//
//	switch (index)
//	{
//	case 10:
//		m_battleControler->setTurnType(3); // move
//		break;
//	case 11:
//		m_battleControler->setTurnType(2); // 가방
//
//		break;
//	case 12:
//		m_battleControler->setTurnType(1); //도망
//		Director::getInstance()->popScene();
//		break;
//	default:
//		return;
//		break;
//	}
//	getBattleMenuLayer()->removeRapidMenu();
//}
//
//void BattleScene::chooseNomalMenu(Object* pSender)
//{
//	auto item = (MenuItem*)pSender;
//	int index = item->getTag();
//
//	switch (index)
//	{
//	case 20:
//		getBattleMenuLayer()->removeRapidMenu();
//		getBattleMenuLayer()->removeNomalMenu();
//		m_battleControler->setTurnType(4); // 액션
//		getBattleMenuLayer()->printActionMenu();
//		return;
//	case 21:
//		m_battleControler->setTurnType(5); //공격
//		break;
//	case 22:
//		m_battleControler->setTurnType(6); // 종료
//		m_battleControler->TurnEnd();
//		endCharacterTurn();
//		break;
//	default:
//		return;
//		break;
//	}
//	getBattleMenuLayer()->removeRapidMenu();
//	getBattleMenuLayer()->removeNomalMenu();
//}
//
//
//void  BattleScene::chooseActionMenu(Object* pSender)
//{
//	auto item = (MenuItem*)pSender;
//	int index = item->getTag();
//	switch (index)
//	{
//	case 30:
//		
//		m_battleControler->setTurnType(7); //
//
//		break;
//	case 31:
//		m_battleControler->setTurnType(8); //
//
//		break;
//	case 32:
//		m_battleControler->setTurnType(9); // 
//
//		break;
//	default:
//		return;
//		break;
//	}
//}

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

