#include "FieldLayer.h"
#include "math.h"
#include "StaticContentsContainer.h"
#include "NFieldScene.h"

USING_NS_CC;

bool FieldLayer::init()
{
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
	{
		return false;
	}

	setCharacterSprite(Sprite::create(getCharacter()->getSpriteRoot())); // 캐릭토ㅓ 이미지 출력

	printTileField();// 
	printCharacter(); // 캐릭터 프린트 
	makeMonster(); // 몬스터 
	printMonster(); // 프린트 몬스터 

	return true;
}

FieldLayer::FieldLayer()
{	
	this->setCharacterControler(new CCharacterControler()); //캐릭터 콘트롤러 생성 
	this->setMapControler(new CMapControler()); // 맵 컨트롤러 생성 

}

void FieldLayer::printTileField()// 맵 구현 
{
	int tileSiz = getMap()->atTile(Vec2(0, 0))->getSize().x; // 타일 하나의 크기 

	for (int i = 0; i < getMap()->getSizeTile().y; i++) //Y축 
	{
		for (int j = 0; j < getMap()->getSizeTile().x; j++) //X축 
		{
			getMap()->atTile(Vec2(j, i))->getSprite()->setPosition(tileSiz / 2 + tileSiz * j, tileSiz/2 + tileSiz * i);
			this->addChild(getMap()->atTile(Vec2(j, i))->getSprite(), 0);
		}
	}
}

void  FieldLayer::removeTileField()// 맵 제거 
{
	
	for (int i = 0; i < getMap()->getSizeTile().y; i++)
	{
		for (int j = 0; j < getMap()->getSizeTile().x; j++)
		{
			this->removeChild(getMap()->atTile(Vec2(j, i))->getSprite());
		}
	}
}

bool FieldLayer::moveRight()
{
	checkPortal(); // 포탈인지 체크 

	if (getCharacter()->getPoint().x >= getMap()->getSizeTile().x - 1) //  이동 불가 지역인지 체크 // 맵사잉즈 이상 불가 체크 
		return false;

	if (this->getCharacterControler()->moveRight()) // 무브 가능 체크 ? 
	{
		moveCharacter(getCharacter()->getPoint()); // 이동 
		if (getCharacter()->getPoint().x > 5) // 레이어 이동 체크 
			setViewPoint(Vec2(getViewPoint().x + 1, getViewPoint().y)); // 레이어 이동 
		this->getTurnControler()->setMenuPoint(Vec2(getCharacter()->getPoint().x - getViewPoint().x + 5
			, getCharacter()->getPoint().y - getViewPoint().y + 3));

		return true;
	}
	return false;
}

bool FieldLayer::moveLeft()
{
	checkPortal();// 포탈인지 체크 

	if (getCharacter()->getPoint().x <= 0) //  이동 불가 지역인지 체크 
		return false;
	if (this->getCharacterControler()->moveLeft()) // 무브 가능 체크 ?
	{

		moveCharacter(getCharacter()->getPoint());// 이동 

		if (getCharacter()->getPoint().x < getMap()->getSizeTile().x - 6)// 레이어 이동 체크 
			setViewPoint(Vec2(getViewPoint().x - 1, getViewPoint().y)); // 레이어 이동 
		this->getTurnControler()->setMenuPoint(Vec2(getCharacter()->getPoint().x - getViewPoint().x + 5
			, getCharacter()->getPoint().y - getViewPoint().y + 3));

		return true;
	}
	return false;
}

bool FieldLayer::moveUp()
{
	checkPortal();// 포탈인지 체크 

	if (getCharacter()->getPoint().y >= getMap()->getSizeTile().y-1) //  이동 불가 지역인지 체크 
		return false;
	if (this->getCharacterControler()->moveUp())// 무브 가능 체크 ?
	{

		moveCharacter(getCharacter()->getPoint());// 이동 
		if (getCharacter()->getPoint().y > 3)// 레이어 이동 체크 
			setViewPoint(Vec2(getViewPoint().x, getViewPoint().y + 1));// 레이어 이동
		this->getTurnControler()->setMenuPoint(Vec2(getCharacter()->getPoint().x - getViewPoint().x + 5
			, getCharacter()->getPoint().y - getViewPoint().y + 3));

		return true;
	}
	return false;
}

bool FieldLayer::moveDown()
{
	checkPortal();// 포탈인지 체크 

	if (getCharacter()->getPoint().y <= 0)//  이동 불가 지역인지 체크
		return false;

	if (this->getCharacterControler()->moveDown())// 무브 가능 체크 ?
	{

		moveCharacter(getCharacter()->getPoint());// 이동 

		if (getCharacter()->getPoint().y < getMap()->getSizeTile().y - 4)// 레이어 이동 체크 
			setViewPoint(Vec2(getViewPoint().x, getViewPoint().y - 1));// 레이어 이동
		this->getTurnControler()->setMenuPoint(Vec2(getCharacter()->getPoint().x - getViewPoint().x + 5
			, getCharacter()->getPoint().y - getViewPoint().y + 3));

		return true;
	}
	return false;
}

void FieldLayer::printCharacter()
{
	int tileSiz = getMap()->atTile(Vec2(0, 0))->getSize().x; //타일 크기 

	getCharacterSprite()->setPosition(Vec2(tileSiz / 2 + getCharacter()->getPoint().x * tileSiz, tileSiz / 2 + getCharacter()->getPoint().y * tileSiz)); //캐릭터위치 설정 
	this->addChild(getCharacterSprite(), 1); // 구현 
}

void FieldLayer::removeCharacter()
{
	this->removeChild(getCharacterSprite()); //지움 
}

void FieldLayer::onEnter()
{
	Layer::onEnter();
	
	
	this->setViewPoint(getCharacter()->getPoint());// 레이어의 시작 포인크를 설정 
	viewControl(); //뷰포인 설정 
	this->getTurnControler()->setMenuPoint(Vec2(getCharacter()->getPoint().x - getViewPoint().x + 5
		, getCharacter()->getPoint().y - getViewPoint().y + 3));

}

void FieldLayer::onExit()
{
	
	Layer::onExit();
}

void FieldLayer::moveLayerPoint(Vec2 a_Point)
{
	int tileSiz = getMap()->atTile(Vec2(0, 0))->getSize().x; // 타일 크기 
	this->runAction(MoveTo::create(0.1f, Vec2(590 - tileSiz * (a_Point.x),310 - tileSiz * (a_Point.y)))); //이동 

}

void FieldLayer::setViewPoint(Vec2 a_viewPoint) 
{
	if (a_viewPoint.x < 5) // x가 5보다작으면 5로 
		a_viewPoint.x = 5;

	else if (a_viewPoint.x > getMap()->getSizeTile().x - 6) // x가 맵크기 -6 보다작으면 맵크기 -6로 
		a_viewPoint.x = getMap()->getSizeTile().x - 6;

	if (a_viewPoint.y < 3) //y가 3보다작으면 3로
		a_viewPoint.y = 3; //y가 3보다작으면 3로

	else if (a_viewPoint.y> getMap()->getSizeTile().y- 4) // y가 맵크기 -4 보다작으면 맵크기 -4로 
		a_viewPoint.y = getMap()->getSizeTile().y - 4; // y가 맵크기 -4 보다작으면 맵크기 -4로  

	this->m_viewPoint = a_viewPoint; //설정 
	this->moveLayerPoint(getViewPoint()); //이동 
}

void FieldLayer::moveCharacter(Vec2 a_Point)
{
	int tileSiz = getMap()->atTile(Vec2(0, 0))->getSize().x;
	this->getCharacterSprite()->runAction(MoveTo::create(0.1, Vec2(tileSiz / 2 + tileSiz * a_Point.x, tileSiz / 2 + tileSiz * a_Point.y)));
}

void FieldLayer::viewControl()
{
	for (int i = 0; i < getMap()->getSizeTile().y; i++)
	{
		for (int j = 0; j < getMap()->getSizeTile().x; j++)
		{
			if (getViewPoint().x - 6 <= j && getViewPoint().x + 6 >= j &&
				getViewPoint().y - 4 <= i && getViewPoint().y + 4 >=i)
			{
				getMap()->atTile(Vec2(j, i))->getSprite()->setVisible(true);
			}
			else
			{
				getMap()->atTile(Vec2(j, i))->getSprite()->setVisible(false);
			}
		}
	}
}

void FieldLayer::changeMap(int PortalIndex) // 맵맵체인지
{
	
	CMap * map = StaticContentsContainer::readMapMap(DynamicContentsContainer::getInstance()->getMap()->getPortal(PortalIndex)->getLinkedMapKey()); // 리드맵맵
	DynamicContentsContainer::getInstance()->setStartingPoint(DynamicContentsContainer::getInstance()->getMap()->getPortal(PortalIndex)->getLinkedPoint()); // 시작포인트 변경 

	CCharacter * hero = DynamicContentsContainer::getInstance()->getCharacter();
	DynamicContentsContainer::getInstance()->setMap(map); // 새맵맵 적용 

	DynamicContentsContainer::getInstance()->getCharacter()->
		setPoint(DynamicContentsContainer::getInstance()->getStartingPoint()); // 시각포인트 설정 

	deleteMonster(); // 몬스타 제거

	auto	fieldScene = NFieldScene::createScene(); // 새씬 
	Director::getInstance()->replaceScene(fieldScene); // 씬교체

}

void FieldLayer::checkPortal() // 포탈 위치와 히어로 
{
	CCharacter * hero = DynamicContentsContainer::getInstance()->getCharacter();
	CMap * map = DynamicContentsContainer::getInstance()->getMap();

	for (int i = 0; i < 10; i++)
	{
		if (map->getPortal(i) == NULL) //  빈포탈 체크 
			continue;
		if (hero->getPoint() == map->getPortal(i)->getPoint())  // 같은 위치임을 체크
			changeMap(i);
	}
}

void FieldLayer::printMonster()
{
	CMonster* mon[10];

	for (int i = 0; i < 10; i++)
	{
		if (DynamicContentsContainer::getInstance()->getMonster(i) == NULL)
			continue;
		mon[i] = DynamicContentsContainer::getInstance()->getMonster(i);
		mon[i]->getSprite()->setPosition(Vec2(mon[i]->getPoint().x * 100 + 50, mon[i]->getPoint().y * 100 + 50));
		addChild(mon[i]->getSprite());
	}
}

void FieldLayer::removeMonster()
{
	CMonster* mon[10];
	for (int i = 0; i < 10; i++)
	{
		mon[i] = DynamicContentsContainer::getInstance()->getMonster(i);
		removeChild(mon[i]->getSprite());
	}
}

void FieldLayer::removeMonster(int index)
{
	CMonster*mon = DynamicContentsContainer::getInstance()->getMonster(index);
	removeChild(mon->getSprite());
}

void FieldLayer::monstermove(int index)
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

void FieldLayer::makeMonster() // 몬스터 출력 
{
	CMap *map = DynamicContentsContainer::getInstance()->getMap(); //현재 맵 
	string mapKey = map->getKey(); // 맵의 키번호를 받아옴

	CMonster *temp; 
	CMonster *monster[10]; // 10마리 몬스터 소환
	CObject **object = StaticContentsContainer::getMapMonsterArray()->find(mapKey)->second; // 여기담긴 내용을로 

	CSkill* tempSkill; //몬스터 스킬?
	int skillNum = 0;
	;
	for (int i = 0; i < 10; i++) // 총 10마리의 먼스터 
	{
		if (object[i] == NULL)
			continue;

		temp = StaticContentsContainer::getMapMonster()->find(object[i]->getName())->second; // 몬스터다 

		monster[i] = new CMonster(temp->getName(), temp->getSpriteRoot()); //몬스터 생성자 
		monster[i]->setStatus(new Status(temp->getStatus()->getHp(), // 몬스터 스테이터스 
			temp->getStatus()->getSpeed(),
			temp->getStatus()->getDef(),
			temp->getStatus()->getStr(),
			temp->getStatus()->getDex(),
			temp->getStatus()->getIns(),
			temp->getStatus()->getKno()));


		// 수정 사항 몬스터 스킬 여러개 가능 하도록 합시다.//
		tempSkill = new CSkill(temp->getSkill(skillNum)->getName(), //몬스터 스킬 
			temp->getSkill(skillNum)->getRange(),
			temp->getSkill(skillNum)->getDiceType(),
			temp->getSkill(skillNum)->getDiceNum(),
			temp->getSkill(skillNum)->getAttribute(),
			temp->getSkill(skillNum)->getAccuracyRate());
		for (int j = 0; temp->getSkill(skillNum)->getSplash(j) != Vec2(0, 0); j++)
			tempSkill->setSplash(temp->getSkill(skillNum)->getSplash(j), j);
		monster[i]->setSkill(tempSkill, skillNum);
		monster[i]->setPoint(object[i]->getPoint());
		monster[i]->setDir(2);
		DynamicContentsContainer::getInstance()->setMonster(monster[i], i);
	}

}
void FieldLayer::deleteMonster() // 몬스타를 삭제
{
	for (int i = 0; i < 10; i++)
	{
		DynamicContentsContainer::getInstance()->setMonster(NULL, i);
	}

}
