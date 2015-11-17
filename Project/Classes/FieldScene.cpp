#include "FieldScene.h"
#include "BattleScene.h"

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
	
	log("%f, %f ", touch->getLocation().x, winSize.width - 90);
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
				log("stop");

			}
			else if (touch->getLocation().x > x &&       // 오른쪽 대각선으로 각도가 30도가 눌려지면 걸림  
				touch->getLocation().y < y + (1 / root3)*(touch->getLocation().x - x) &&
				touch->getLocation().y > y - (1 / root3)*(touch->getLocation().x - x))
			{
				log("right");
				getFieldLayer()->moveRight();
				getFieldLayer()->viewControl();
			}
			else if (touch->getLocation().x < x &&  // 왼쪽을 클릭되면 걸림 
				touch->getLocation().y < y + (1 / root3)*(x - touch->getLocation().x) &&
				touch->getLocation().y > y - (1 / root3)*(x - touch->getLocation().x))
			{
				log("left");
				getFieldLayer()->moveLeft();
				getFieldLayer()->viewControl();
			}
			else if (touch->getLocation().y > y && // 위 60도 걸림
				touch->getLocation().x < x + (root3)*(touch->getLocation().y - y) &&
				touch->getLocation().x > x - (root3)*(touch->getLocation().y - y))
			{
				log("up");
				getFieldLayer()->moveUp();
				getFieldLayer()->viewControl();
			}
			else if (touch->getLocation().y < y && //아래 걸림
				touch->getLocation().x < x + (root3)*(y - touch->getLocation().y) &&
				touch->getLocation().x > x - (root3)*(y - touch->getLocation().y))

			{
				log("down");
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

void FieldScene::Battle(float delta)
{
	auto * battleScene = BattleScene::createScene();
	Director::getInstance()->pushScene(battleScene);
}

