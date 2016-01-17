#include "FieldLayer.h"
#include "math.h"
#include "FieldScene.h"
#include "StaticContentsContainer.h"

USING_NS_CC;

bool FieldLayer::init()
{
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
	{
		return false;
	}

	setCharacterSprite(Sprite::create(getCharacter()->getSpriteRoot()));

	printTileField();
	printCharacter();

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


void FieldLayer::moveRight()
{
	checkPortal(); // 포탈인지 체크 

	if (getCharacter()->getPoint().x >= getMap()->getSizeTile().x-1) //  이동 불가 지역인지 체크 
		return;  

	if (this->getCharacterControler()->moveRight()) // 무브 가능 체크 ? 
	{
		moveCharacter(getCharacter()->getPoint()); // 이동 
		if (getCharacter()->getPoint().x > 5) // 레이어 이동 체크 
			setViewPoint(Vec2(getViewPoint().x + 1, getViewPoint().y)); // 레이어 이동 
	}
}
void FieldLayer::moveLeft()
{
	checkPortal();// 포탈인지 체크 

	if (getCharacter()->getPoint().x <= 0) //  이동 불가 지역인지 체크 
		return;
	if (this->getCharacterControler()->moveLeft()) // 무브 가능 체크 ?
	{

		moveCharacter(getCharacter()->getPoint());// 이동 

		if (getCharacter()->getPoint().x < getMap()->getSizeTile().x - 6)// 레이어 이동 체크 
			setViewPoint(Vec2(getViewPoint().x - 1, getViewPoint().y)); // 레이어 이동 
	}
}
void FieldLayer::moveUp()
{
	checkPortal();// 포탈인지 체크 

	if (getCharacter()->getPoint().y >= getMap()->getSizeTile().y-1) //  이동 불가 지역인지 체크 
		return;
	if (this->getCharacterControler()->moveUp())// 무브 가능 체크 ?
	{

		moveCharacter(getCharacter()->getPoint());// 이동 
		if (getCharacter()->getPoint().y > 3)// 레이어 이동 체크 
			setViewPoint(Vec2(getViewPoint().x, getViewPoint().y + 1));// 레이어 이동
	}
}
void FieldLayer::moveDown()
{
	checkPortal();// 포탈인지 체크 

	if (getCharacter()->getPoint().y <= 0)//  이동 불가 지역인지 체크
		return;

	if (this->getCharacterControler()->moveDown())// 무브 가능 체크 ?
	{

		moveCharacter(getCharacter()->getPoint());// 이동 

		if (getCharacter()->getPoint().y < getMap()->getSizeTile().y - 4)// 레이어 이동 체크 
			setViewPoint(Vec2(getViewPoint().x, getViewPoint().y - 1));// 레이어 이동
	}
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

void FieldLayer::changeMap(string MapKey) // 맵체인지
{
	CMap * map = StaticContentsContainer::getMapMap()->find(MapKey)->second;
	CCharacter * hero = DynamicContentsContainer::getInstance()->getCharacter();
	DynamicContentsContainer::getInstance()->setMap(map);
	DynamicContentsContainer::getInstance()->getCharacter()->setPoint(DynamicContentsContainer::getInstance()->getMap()->getStartPoint());
	auto	fieldScene = FieldScene::createScene();
	Director::getInstance()->replaceScene(fieldScene);
	for (int i = 0; i < 10; i++)
	{
		if (DynamicContentsContainer::getInstance()->getMonster(i) == NULL)
			break;
	///	delete(DynamicContentsContainer::getInstance()->getMonster(i));
		DynamicContentsContainer::getInstance()->setMonster(NULL, i);
	}
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
			changeMap(map->getPortal(i)->getName());
	}
}