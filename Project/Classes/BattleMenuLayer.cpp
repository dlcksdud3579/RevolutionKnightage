#include "BattleMenuLayer.h"
#include "DynamicContentsContainer.h"

void BattleMenuLayer::printRapidMenu()
{
	int r3 = 1.7; //루트 3 
	int PointX = DynamicContentsContainer::getInstance()->getCharacter()->getPoint().x;
	int PointY = DynamicContentsContainer::getInstance()->getCharacter()->getPoint().y;

	moveLable = Label::create("MOVE", "fonts/arial.ttf", 36);
	moveLable->setPosition(PointX + 50 * r3, PointY+50);
	moveLable->setTag(10);

	InvenLable = Label::create("BAG", "fonts/arial.ttf", 36);
	InvenLable->setPosition(PointX  - 50 *r3, PointY-50);
	InvenLable->setTag(11);

	escLable = Label::create("ESC", "fonts/arial.ttf", 36);
	escLable->setPosition(PointX - 50 * r3, PointY + 50);
	escLable->setTag(12);

	this->addChild(moveLable);
	this->addChild(InvenLable);
	this->addChild(escLable);
}



void BattleMenuLayer::printNomalMenu()
{
	int r3 = 1.7; //루트 3 

	int PointX = DynamicContentsContainer::getInstance()->getCharacter()->getPoint().x;
	int PointY = DynamicContentsContainer::getInstance()->getCharacter()->getPoint().y;

	actionLable = Label::create("ACTION", "fonts/arial.ttf", 36);
	actionLable->setPosition(PointX + 50 * r3, PointY + 50);
	actionLable->setTag(20);

	attakLable = Label::create("ATTACK", "fonts/arial.ttf", 36);
	attakLable->setPosition(PointX , PointY + 100);
	attakLable->setTag(21);

	endLable = Label::create("END", "fonts/arial.ttf", 36);
	endLable->setPosition(PointX, PointY - 100);
	endLable->setTag(22);

	this->addChild(actionLable);
	this->addChild(attakLable);
	this->addChild(endLable);
}
void  BattleMenuLayer::removeRapidMenu()
{
	this->removeChild(moveLable);
	this->removeChild(InvenLable);
	this->removeChild(escLable);
	
}
void  BattleMenuLayer::removeNomalMenu()
{
	this->removeChild(moveLable);
	this->removeChild(InvenLable);
	this->removeChild(escLable);
}
void BattleMenuLayer::chooseRapidMenu(Object* pSender)
{
	auto item = (MenuItem*)pSender;
	int index = item->getTag();

	switch (index)
	{
	case 10:
		getBattleControler()->setTurnType(3); // move
	case 11:
		getBattleControler()->setTurnType(2);
	case 12:
		getBattleControler()->setTurnType(1);
	default:
		break;
	}
}
void BattleMenuLayer::chooseNomalMenu(Object* pSender)
{
	auto item = (MenuItem*)pSender;
	int index = item->getTag();

	switch (index)
	{
	case 20:
		getBattleControler()->setTurnType(4);
	case 21:
		getBattleControler()->setTurnType(5);
	case 22:
		getBattleControler()->setTurnType(6);
	default:
		break;
	}
}