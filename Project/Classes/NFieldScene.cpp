
#include "NFieldScene.h"


Scene* NFieldScene::createScene()
{
	auto scene = Scene::create();

	auto layer = NFieldScene::create();

	scene->addChild(layer);

	return scene;
}

bool NFieldScene::init()
{

	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
	{
		return false;
	}

	// 턴 컨트롤러 
	this->setTurnControler(new TurnControler());
	// 턴 컨트롤러 

	// 필드레이어 
	this->setFieldLayer(FieldLayer::create());
	this->getFieldLayer()->setPosition(90, 10);
	this->getFieldLayer()->setTurnControler(this->getTurnControler());
	this->addChild(this->getFieldLayer(), 1);
	// 필드레이어 

	// 화면 틀 레이어
	this->setFrameLayer(FrameLayer::create());
	this->getFrameLayer()->setPosition(0, 0);
	this->addChild(this->getFrameLayer(), 2);
	// 화면 틀 레이어

	// 행동 메뉴 레이어 띄우기
	this->setBattleMenuLayer(BattleMenuLayer::create());
	this->getBattleMenuLayer()->setPosition(0, 0);
	this->getBattleMenuLayer()->setTurnControler(this->getTurnControler());
	this->addChild(this->getBattleMenuLayer(), 3);
	// 행동 메뉴 레이어 띄우기

	//  메뉴 레이어 띄우기 
	this->setMenuLayer(MenuLayer::create());
	this->getMenuLayer()->setPosition(0, 0);
	this->getMenuLayer()->setTurnControler(this->getTurnControler());;
	this->addChild(this->getMenuLayer(), 4);
	//  메뉴 레이어 띄우기 

	return true;
}

void NFieldScene::onEnter()
{
	Layer::onEnter(); // 무조건 맨위 필수 함수 //아마도 레이어 시작 하는 함수 

	auto listener = EventListenerTouchOneByOne::create(); // 터치 리스너 생성 

	listener->setSwallowTouches(true); // 터치인식 가능 하게 // 불정확

	listener->onTouchBegan = CC_CALLBACK_2(MenuLayer::onTouchBegan, this); // 터치시작 할때 불려지는함수 등록 
	listener->onTouchMoved = CC_CALLBACK_2(MenuLayer::onTouchMoved, this); // 터치 이동 할때 불려지는함수 등록 
	listener->onTouchEnded = CC_CALLBACK_2(MenuLayer::onTouchEnded, this); // 터치 끝 날때 불려지는 함수 등록 
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);  // 리스너 적용 

}

void NFieldScene::onExit()
{
	_eventDispatcher->removeEventListenersForType(EventListener::Type::TOUCH_ONE_BY_ONE); // 리스너 종료 

	Layer::onExit(); // 무조건 맨밑 필수함수 // 아마도 레이어 끝내는 함수 
}

bool NFieldScene::onTouchBegan(Touch* touch, Event* event) //  터치 시작시 불려지는함수 
{

	Size winSize = CCDirector::getInstance()->getVisibleSize(); // 현재 윈도우 사이즈 

	int tileSiz = this->getFieldLayer()->getMap()->atTile(Vec2(0, 0))->getSize().x; // 타일 한칸의 사이즈 

	int x = tileSiz / 2 + 90 + (getFieldLayer()->getCharacter()->getPoint().x - getFieldLayer()->getViewPoint().x + 5) * tileSiz; // 터치 입력시 캐릭터 위치 X
	int y = tileSiz / 2 + 10 + (getFieldLayer()->getCharacter()->getPoint().y - getFieldLayer()->getViewPoint().y + 3) * tileSiz; // 터치 입력시 캐릭터 위치 Y

	int root3 = sqrt(3); // tan 기준으로 30도에경우 1/root3  60인경우 root3을 곱한다.

	//log("%f, %f ", touch->getLocation().x, winSize.width - 90);
	if (this->getMenuLayer()->isOpenFlag() == false) // 메뉴 판이 나온 상태가 아님 
	{

		if (touch->getLocation().x > winSize.width - 90)  // 매뉴판을 꺼내오는 위치 
		{
			getMenuLayer()->Open(); //메뉴 판을 꺼네어 온다 
			return true;
		}
		else
		{
			if (touch->getLocation().x < x + tileSiz / 2 &&
				touch->getLocation().x > x - tileSiz / 2 &&
				touch->getLocation().y > y - tileSiz / 2 &&
				touch->getLocation().y < y + tileSiz / 2) // 현재 타일을 가르킴 
			{
				log("stop");
				getBattleMenuLayer()->printNomalMenu();  // 기본 메뉴를 뛰워준다.

			}
			else if (touch->getLocation().x > x &&       // 오른쪽 대각선으로 각도가 30도가 눌려지면 걸림  
				touch->getLocation().y < y + (1 / root3)*(touch->getLocation().x - x) &&
				touch->getLocation().y > y - (1 / root3)*(touch->getLocation().x - x))
			{
				//log("right");
				if (getFieldLayer()->moveRight())// 오른쪽으로 이동 
				{
					getFieldLayer()->viewControl(); // 이동 성공시 사용자 시점 이동  
					getBattleMenuLayer()->removeMenu(); // 이동시 메뉴 사라짐 
					this->getTurnControler()->setUsedActionPoint(1.0);
					endTurn();
				}
				else
				{

				}
			}
			else if (touch->getLocation().x < x &&  // 왼쪽을 클릭되면 걸림 
				touch->getLocation().y < y + (1 / root3)*(x - touch->getLocation().x) &&
				touch->getLocation().y > y - (1 / root3)*(x - touch->getLocation().x))
			{
				//log("left");
				if (getFieldLayer()->moveLeft())// 왼쪽으로 이동 
				{
					getFieldLayer()->viewControl(); //이동 성공시 사용자 시점 이동
					getBattleMenuLayer()->removeMenu(); // 이동시 메뉴 사라짐 
					this->getTurnControler()->setUsedActionPoint(1.0);
					endTurn();
				}
				else
				{

				}
			}
			else if (touch->getLocation().y > y && // 위 60도 걸림
				touch->getLocation().x < x + (root3)*(touch->getLocation().y - y) &&
				touch->getLocation().x > x - (root3)*(touch->getLocation().y - y))
			{
				//	log("up");
				if (getFieldLayer()->moveUp()) //위로 이동 
				{
					getFieldLayer()->viewControl(); //이동 성공시 사용자 시점 이동
					getBattleMenuLayer()->removeMenu(); // 이동시 메뉴 사라짐 
					this->getTurnControler()->setUsedActionPoint(1.0);
					endTurn();
				}
				else
				{

				}
			}
			else if (touch->getLocation().y < y && //아래 걸림
				touch->getLocation().x < x + (root3)*(y - touch->getLocation().y) &&
				touch->getLocation().x > x - (root3)*(y - touch->getLocation().y))

			{
				//	log("down");
				if (getFieldLayer()->moveDown()) // 아래로 이동 
				{
					getFieldLayer()->viewControl(); //이동 성공시 사용자 시점 이동
					getBattleMenuLayer()->removeMenu(); // 이동시 메뉴 사라짐 
					this->getTurnControler()->setUsedActionPoint(1.0);
					endTurn();
					
				}
				else
				{

				}

			}
		}
	}
	else if (this->getMenuLayer()->isOpenFlag() == true)// 메뉴 판이 나온 상태임
	{
		if (touch->getLocation().x < winSize.width - 290) // 메뉴판이 나온 상태에서 다른곳 터치시 종료 
		{
			getMenuLayer()->Close(); // 메뉴 레이어 종료 

			return true;
		}
	}


	return true;

}

void NFieldScene::onTouchMoved(Touch* touch, Event* event) // 터치이동 일때 불려지는함수 
{
}

void NFieldScene::onTouchEnded(Touch* touch, Event* event) // 터치가 끝이 날때 불려지는함수 
{
}

void NFieldScene::monsterTurn()
{
	for (int i = 0; i < 10; i++)
	{
		if (DynamicContentsContainer::getInstance()->getMonster(i) == NULL)
			break;
		if (this->getTurnControler()->getMonActionPoint(i) >= 1.0)
			monstermove(i);
	}
}


void NFieldScene::monstermove(int index)
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
void NFieldScene::endTurn()
{
	
	this->getTurnControler()->CharacterTurnEnd();
	monsterTurn();
}