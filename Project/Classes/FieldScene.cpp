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


	// �ʵ巹�̾� 
	this->setFieldLayer( FieldLayer::create());
	this->getFieldLayer()->setPosition(90, 10);
	this->addChild(this->getFieldLayer(),1);

	// ȭ�� Ʋ ���̾�
	this->setFrameLayer(FrameLayer::create());
	this->getFrameLayer()->setPosition(0, 0);
	this->addChild(this->getFrameLayer(),2);

	//  �޴� ���̾� ���� 
	this->m_menuLayer = MenuLayer::create();
	this->m_menuLayer->setPosition(0, 0);
	this->addChild(m_menuLayer, 3);
	
	// �׽�Ʈ�� ���� ����� 
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
	int x = tileSiz / 2 + 90 + (getFieldLayer()->getCharacter()->getPoint().x - getFieldLayer()->getViewPoint().x + 5) * tileSiz; // ��ġ �Է½� ĳ���� ��ġ X
	int y = tileSiz / 2 + 10 + (getFieldLayer()->getCharacter()->getPoint().y - getFieldLayer()->getViewPoint().y + 3) * tileSiz; // Y

	int root3 = sqrt(3); // tan �������� 30������� 1/root3  60�ΰ�� root3�� ���Ѵ�.
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
				touch->getLocation().y < y + tileSiz / 2) // ���� Ÿ���� ����Ŵ 
			{
				log("stop");

			}
			else if (touch->getLocation().x > x &&       // ������ �밢������ ������ 30���� �������� �ɸ�  
				touch->getLocation().y < y + (1 / root3)*(touch->getLocation().x - x) &&
				touch->getLocation().y > y - (1 / root3)*(touch->getLocation().x - x))
			{
				log("right");
				getFieldLayer()->moveRight();
				getFieldLayer()->viewControl();
			}
			else if (touch->getLocation().x < x &&  // ������ Ŭ���Ǹ� �ɸ� 
				touch->getLocation().y < y + (1 / root3)*(x - touch->getLocation().x) &&
				touch->getLocation().y > y - (1 / root3)*(x - touch->getLocation().x))
			{
				log("left");
				getFieldLayer()->moveLeft();
				getFieldLayer()->viewControl();
			}
			else if (touch->getLocation().y > y && // �� 60�� �ɸ�
				touch->getLocation().x < x + (root3)*(touch->getLocation().y - y) &&
				touch->getLocation().x > x - (root3)*(touch->getLocation().y - y))
			{
				log("up");
				getFieldLayer()->moveUp();
				getFieldLayer()->viewControl();
			}
			else if (touch->getLocation().y < y && //�Ʒ� �ɸ�
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

