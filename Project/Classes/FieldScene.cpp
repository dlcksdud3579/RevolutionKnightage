#include "FieldScene.h"
#include "BattleScene.h"
#include "StaticContentsContainer.h"
#include "CStatus.h"
USING_NS_CC;


Scene* FieldScene::createScene()
{
	auto scene = Scene::create();

	auto layer = FieldScene::create();

	scene->addChild(layer);

	return scene;
}

bool FieldScene::init()
{
	
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
	{
		return false;
	}


	// 필드레이어 
	this->setFieldLayer( FieldLayer::create());
	this->getFieldLayer()->setPosition(90, 10);
	this->addChild(this->getFieldLayer(),1);

	// 화면 틀 레이어
	this->setFrameLayer(FrameLayer::create());
	this->getFrameLayer()->setPosition(0, 0);
	this->addChild(this->getFrameLayer(),2);

	//  메뉴 레이어 띄우기 
	this->m_menuLayer = MenuLayer::create();
	this->m_menuLayer->setPosition(0, 0);
	this->addChild(m_menuLayer, 3);
	
	// 테스트용 몬스터 등장용 
	scheduleOnce(schedule_selector(FieldScene::Battle), 3.0f);

	return true;
}
void FieldScene::onEnter()
{
	Layer::onEnter();

	auto listener = EventListenerTouchOneByOne::create();

	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(MenuLayer::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(MenuLayer::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(MenuLayer::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

}

void FieldScene::onExit()
{
	_eventDispatcher->removeEventListenersForType(EventListener::Type::TOUCH_ONE_BY_ONE);

	Layer::onExit();
}

bool FieldScene::onTouchBegan(Touch* touch, Event* event)
{

	

	Size winSize = CCDirector::getInstance()->getVisibleSize();
	int tileSiz = this->getFieldLayer()->getMap()->atTile(Vec2(0, 0))->getSize().x;
	int x = tileSiz / 2 + 90 + (getFieldLayer()->getCharacter()->getPoint().x - getFieldLayer()->getViewPoint().x + 5) * tileSiz; // 터치 입력시 캐릭터 위치 X
	int y = tileSiz / 2 + 10 + (getFieldLayer()->getCharacter()->getPoint().y - getFieldLayer()->getViewPoint().y + 3) * tileSiz; // Y

	int root3 = sqrt(3); // tan 기준으로 30도에경우 1/root3  60인경우 root3을 곱한다.
	//log("%d %d, %f, %f",x,
	
	//log("%f, %f ", touch->getLocation().x, winSize.width - 90);
	if (this->getMenuLayer()->isOpenFlag() == false)
	{
		if (touch->getLocation().x > winSize.width - 90)
		{
			getMenuLayer()->Open();

			return true;
		}
		else
		{
			if (touch->getLocation().x < x + tileSiz / 2 &&
				touch->getLocation().x > x - tileSiz / 2 &&
				touch->getLocation().y > y - tileSiz / 2 &&
				touch->getLocation().y < y + tileSiz / 2) // 현재 타일을 가르킴 
			{
			//	log("stop");

			}
			else if (touch->getLocation().x > x &&       // 오른쪽 대각선으로 각도가 30도가 눌려지면 걸림  
				touch->getLocation().y < y + (1 / root3)*(touch->getLocation().x - x) &&
				touch->getLocation().y > y - (1 / root3)*(touch->getLocation().x - x))
			{
				//log("right");
				getFieldLayer()->moveRight();
				getFieldLayer()->viewControl();
			}
			else if (touch->getLocation().x < x &&  // 왼쪽을 클릭되면 걸림 
				touch->getLocation().y < y + (1 / root3)*(x - touch->getLocation().x) &&
				touch->getLocation().y > y - (1 / root3)*(x - touch->getLocation().x))
			{
				//log("left");
				getFieldLayer()->moveLeft();
				getFieldLayer()->viewControl();
			}
			else if (touch->getLocation().y > y && // 위 60도 걸림
				touch->getLocation().x < x + (root3)*(touch->getLocation().y - y) &&
				touch->getLocation().x > x - (root3)*(touch->getLocation().y - y))
			{
			//	log("up");
				getFieldLayer()->moveUp();
				getFieldLayer()->viewControl();
			}
			else if (touch->getLocation().y < y && //아래 걸림
				touch->getLocation().x < x + (root3)*(y - touch->getLocation().y) &&
				touch->getLocation().x > x - (root3)*(y - touch->getLocation().y))

			{
			//	log("down");
				getFieldLayer()->moveDown();
				getFieldLayer()->viewControl();
			}
		}
	}
	else if (this->getMenuLayer()->isOpenFlag() == true)
	{
		if (touch->getLocation().x < winSize.width - 290)
		{
			getMenuLayer()->Close();

			return true;
		}
	}

	
	return true;

}
void FieldScene::onTouchMoved(Touch* touch, Event* event)
{

}
void FieldScene::onTouchEnded(Touch* touch, Event* event)
{

}

void FieldScene::Battle(float delta) // 배틀로 넘어가는 하함수 
{
	CMap *map = DynamicContentsContainer::getInstance()->getMap();


	string mapKey = map->getKey();

	CMonster *temp;
	CMonster *monster[10];
	CObject **object = StaticContentsContainer::getMapMonsterArray()->find(mapKey)->second; // 여기담긴 내용을로 

	CSkill* tempSkill;
	int skillNum=0;
	; 
	for (int i=0; i < 10; i++)
	{
		if (object[i] == NULL)
			break;

		temp = StaticContentsContainer::getMapMonster()->find(object[i]->getName())->second;

		monster[i] = new CMonster(temp->getName(), temp->getSpriteRoot());
		monster[i]->setStatus(new Status(temp->getStatus()->getHp(),
			temp->getStatus()->getSpeed(),
			temp->getStatus()->getDef(),
			temp->getStatus()->getStr(),
			temp->getStatus()->getDex(),
			temp->getStatus()->getIns(),
			temp->getStatus()->getKno()));

		tempSkill = new CSkill(temp->getSkill(skillNum)->getName(),
			temp->getSkill(skillNum)->getRange(),
			temp->getSkill(skillNum)->getDiceType(),
			temp->getSkill(skillNum)->getDiceNum(),
			temp->getSkill(skillNum)->getAttribute(),
			temp->getSkill(skillNum)->getAccuracyRate());
		for (int j = 0; temp->getSkill(skillNum)->getSplash(j) != Vec2(0,0); j++)
			tempSkill->setSplash(temp->getSkill(skillNum)->getSplash(j), j);
		monster[i]->setSkill(tempSkill, skillNum);
		monster[i]->setPoint(object[i]->getPoint());
		monster[i]->setDir(2);
		DynamicContentsContainer::getInstance()->setMonster(monster[i],i);
	}

	auto * battleScene = BattleScene::createScene();
	Director::getInstance()->replaceScene(battleScene);
}

