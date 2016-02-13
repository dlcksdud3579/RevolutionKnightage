
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

	// �� ��Ʈ�ѷ� 
	this->setTurnControler(new TurnControler());
	// �� ��Ʈ�ѷ� 

	// �ʵ巹�̾� 
	this->setFieldLayer(FieldLayer::create());
	this->getFieldLayer()->setPosition(90, 10);
	this->getFieldLayer()->setTurnControler(this->getTurnControler());
	this->addChild(this->getFieldLayer(), 1);
	// �ʵ巹�̾� 

	// ȭ�� Ʋ ���̾�
	this->setFrameLayer(FrameLayer::create());
	this->getFrameLayer()->setPosition(0, 0);
	this->addChild(this->getFrameLayer(), 2);
	// ȭ�� Ʋ ���̾�

	// �ൿ �޴� ���̾� ����
	this->setBattleMenuLayer(BattleMenuLayer::create());
	this->getBattleMenuLayer()->setPosition(0, 0);
	this->getBattleMenuLayer()->setTurnControler(this->getTurnControler());
	this->addChild(this->getBattleMenuLayer(), 3);
	// �ൿ �޴� ���̾� ����

	//  �޴� ���̾� ���� 
	this->setMenuLayer(MenuLayer::create());
	this->getMenuLayer()->setPosition(0, 0);
	this->getMenuLayer()->setTurnControler(this->getTurnControler());;
	this->addChild(this->getMenuLayer(), 4);
	//  �޴� ���̾� ���� 

	return true;
}

void NFieldScene::onEnter()
{
	Layer::onEnter(); // ������ ���� �ʼ� �Լ� //�Ƹ��� ���̾� ���� �ϴ� �Լ� 

	auto listener = EventListenerTouchOneByOne::create(); // ��ġ ������ ���� 

	listener->setSwallowTouches(true); // ��ġ�ν� ���� �ϰ� // ����Ȯ

	listener->onTouchBegan = CC_CALLBACK_2(MenuLayer::onTouchBegan, this); // ��ġ���� �Ҷ� �ҷ������Լ� ��� 
	listener->onTouchMoved = CC_CALLBACK_2(MenuLayer::onTouchMoved, this); // ��ġ �̵� �Ҷ� �ҷ������Լ� ��� 
	listener->onTouchEnded = CC_CALLBACK_2(MenuLayer::onTouchEnded, this); // ��ġ �� ���� �ҷ����� �Լ� ��� 
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);  // ������ ���� 

}

void NFieldScene::onExit()
{
	_eventDispatcher->removeEventListenersForType(EventListener::Type::TOUCH_ONE_BY_ONE); // ������ ���� 

	Layer::onExit(); // ������ �ǹ� �ʼ��Լ� // �Ƹ��� ���̾� ������ �Լ� 
}

bool NFieldScene::onTouchBegan(Touch* touch, Event* event) //  ��ġ ���۽� �ҷ������Լ� 
{

	Size winSize = CCDirector::getInstance()->getVisibleSize(); // ���� ������ ������ 

	int tileSiz = this->getFieldLayer()->getMap()->atTile(Vec2(0, 0))->getSize().x; // Ÿ�� ��ĭ�� ������ 

	int x = tileSiz / 2 + 90 + (getFieldLayer()->getCharacter()->getPoint().x - getFieldLayer()->getViewPoint().x + 5) * tileSiz; // ��ġ �Է½� ĳ���� ��ġ X
	int y = tileSiz / 2 + 10 + (getFieldLayer()->getCharacter()->getPoint().y - getFieldLayer()->getViewPoint().y + 3) * tileSiz; // ��ġ �Է½� ĳ���� ��ġ Y

	int root3 = sqrt(3); // tan �������� 30������� 1/root3  60�ΰ�� root3�� ���Ѵ�.

	//log("%f, %f ", touch->getLocation().x, winSize.width - 90);
	if (this->getMenuLayer()->isOpenFlag() == false) // �޴� ���� ���� ���°� �ƴ� 
	{

		if (touch->getLocation().x > winSize.width - 90)  // �Ŵ����� �������� ��ġ 
		{
			getMenuLayer()->Open(); //�޴� ���� ���׾� �´� 
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
				getBattleMenuLayer()->printNomalMenu();  // �⺻ �޴��� �ٿ��ش�.

			}
			else if (touch->getLocation().x > x &&       // ������ �밢������ ������ 30���� �������� �ɸ�  
				touch->getLocation().y < y + (1 / root3)*(touch->getLocation().x - x) &&
				touch->getLocation().y > y - (1 / root3)*(touch->getLocation().x - x))
			{
				//log("right");
				if (getFieldLayer()->moveRight())// ���������� �̵� 
				{
					getFieldLayer()->viewControl(); // �̵� ������ ����� ���� �̵�  
					getBattleMenuLayer()->removeMenu(); // �̵��� �޴� ����� 
					this->getTurnControler()->setUsedActionPoint(1.0);
					endTurn();
				}
				else
				{

				}
			}
			else if (touch->getLocation().x < x &&  // ������ Ŭ���Ǹ� �ɸ� 
				touch->getLocation().y < y + (1 / root3)*(x - touch->getLocation().x) &&
				touch->getLocation().y > y - (1 / root3)*(x - touch->getLocation().x))
			{
				//log("left");
				if (getFieldLayer()->moveLeft())// �������� �̵� 
				{
					getFieldLayer()->viewControl(); //�̵� ������ ����� ���� �̵�
					getBattleMenuLayer()->removeMenu(); // �̵��� �޴� ����� 
					this->getTurnControler()->setUsedActionPoint(1.0);
					endTurn();
				}
				else
				{

				}
			}
			else if (touch->getLocation().y > y && // �� 60�� �ɸ�
				touch->getLocation().x < x + (root3)*(touch->getLocation().y - y) &&
				touch->getLocation().x > x - (root3)*(touch->getLocation().y - y))
			{
				//	log("up");
				if (getFieldLayer()->moveUp()) //���� �̵� 
				{
					getFieldLayer()->viewControl(); //�̵� ������ ����� ���� �̵�
					getBattleMenuLayer()->removeMenu(); // �̵��� �޴� ����� 
					this->getTurnControler()->setUsedActionPoint(1.0);
					endTurn();
				}
				else
				{

				}
			}
			else if (touch->getLocation().y < y && //�Ʒ� �ɸ�
				touch->getLocation().x < x + (root3)*(y - touch->getLocation().y) &&
				touch->getLocation().x > x - (root3)*(y - touch->getLocation().y))

			{
				//	log("down");
				if (getFieldLayer()->moveDown()) // �Ʒ��� �̵� 
				{
					getFieldLayer()->viewControl(); //�̵� ������ ����� ���� �̵�
					getBattleMenuLayer()->removeMenu(); // �̵��� �޴� ����� 
					this->getTurnControler()->setUsedActionPoint(1.0);
					endTurn();
					
				}
				else
				{

				}

			}
		}
	}
	else if (this->getMenuLayer()->isOpenFlag() == true)// �޴� ���� ���� ������
	{
		if (touch->getLocation().x < winSize.width - 290) // �޴����� ���� ���¿��� �ٸ��� ��ġ�� ���� 
		{
			getMenuLayer()->Close(); // �޴� ���̾� ���� 

			return true;
		}
	}


	return true;

}

void NFieldScene::onTouchMoved(Touch* touch, Event* event) // ��ġ�̵� �϶� �ҷ������Լ� 
{
}

void NFieldScene::onTouchEnded(Touch* touch, Event* event) // ��ġ�� ���� ���� �ҷ������Լ� 
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