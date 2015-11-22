#include "BattleMenuLayer.h"
#include "DynamicContentsContainer.h"
#include "BattleScene.h"
#include "FieldScene.h"

bool BattleMenuLayer::init()
{
	if (!BattleMenuLayer::initWithColor(Color4B(0, 0, 0, 0)))
	{
		return false;
	}
	



	return true;
}
void BattleMenuLayer::printRapidMenu()
{
	float r3 = 1.732; //루트 3 
	Vec2 Point = DynamicContentsContainer::getInstance()->getCharacter()->getPoint();
	
	int PointX = getBattleControler()->getTempPoint().x * 100 + 140;
	int PointY = getBattleControler()->getTempPoint().y * 100 + 60;

	MenuItemFont* moveLable = MenuItemFont::create("MOVE",
		CC_CALLBACK_1(BattleMenuLayer::chooseRapidMenu, this));
	moveLable->setPosition( 50 * r3,  50);
	moveLable->setColor(Color3B(0, 0, 0));
	moveLable->setTag(10);
	
	
	MenuItemFont* InvenLable = MenuItemFont::create("BAG", CC_CALLBACK_1(BattleMenuLayer::chooseRapidMenu, this));
	InvenLable->setPosition( - 50 * r3,  - 50);
	InvenLable->setColor(Color3B(0, 0, 0));
	InvenLable->setTag(11);

	MenuItemFont* escLable = MenuItemFont::create("ESC", CC_CALLBACK_1(BattleMenuLayer::chooseRapidMenu, this));
	escLable->setPosition( - 50 * r3,  + 50);
	escLable->setColor(Color3B(0, 0, 0));
	escLable->setTag(12);

	auto pMenu = Menu::create(moveLable, InvenLable, escLable, NULL);
	pMenu->setPosition(PointX , PointY);
	pMenu->setTag(100);
	addChild(pMenu);
}

void BattleMenuLayer::printNomalMenu()
{
	float r3 = 1.732; //루트 3 
	Vec2 Point = DynamicContentsContainer::getInstance()->getCharacter()->getPoint();

	int PointX = getBattleControler()->getTempPoint().x*100+140;
	int PointY = getBattleControler()->getTempPoint().y*100+60;



	MenuItemFont* actionLable = MenuItemFont::create("ACTION", CC_CALLBACK_1(BattleMenuLayer::chooseNomalMenu, this));
	actionLable->setPosition( + 50 * r3,  - 50);
	actionLable->setColor(Color3B(0, 0, 0));
	actionLable->setTag(20);

	MenuItemFont* attakLable = MenuItemFont::create("ATTACK", CC_CALLBACK_1(BattleMenuLayer::chooseNomalMenu, this));
	attakLable->setPosition(0,  + 100);
	attakLable->setColor(Color3B(0, 0, 0));
	attakLable->setTag(21);

	MenuItemFont* endLable = MenuItemFont::create("END", CC_CALLBACK_1(BattleMenuLayer::chooseNomalMenu, this));
	endLable->setPosition(0,  - 100);
	endLable->setColor(Color3B(0, 0, 0));
	endLable->setTag(22);

	auto pMenu = Menu::create(actionLable, attakLable, endLable, NULL);
	pMenu->setPosition(PointX, PointY);
	pMenu->setTag(200);
	addChild(pMenu);

}
void  BattleMenuLayer::removeRapidMenu()
{
	this->removeChildByTag(100);


}
void  BattleMenuLayer::removeNomalMenu()
{
	this->removeChildByTag(200);

}
void  BattleMenuLayer::printActionMenu()
{
	float r3 = 1.732; //루트 3 

	int PointX = getBattleControler()->getTempPoint().x * 100 + 140;
	int PointY = getBattleControler()->getTempPoint().y * 100 + 60;



	MenuItemFont* action1Lable = MenuItemFont::create("ACTION1", CC_CALLBACK_1(BattleMenuLayer::chooseActionMenu, this));
	action1Lable->setPosition(+50 * r3, -50);
	action1Lable->setColor(Color3B(0, 0, 0));
	action1Lable->setTag(30);

	MenuItemFont* action2Lable = MenuItemFont::create("ACTION2", CC_CALLBACK_1(BattleMenuLayer::chooseActionMenu, this));
	action2Lable->setPosition(+50 * r3, +50);
	action2Lable->setColor(Color3B(0, 0, 0));
	action2Lable->setTag(31);

	MenuItemFont* action3Lable = MenuItemFont::create("ACTION3", CC_CALLBACK_1(BattleMenuLayer::chooseActionMenu, this));
	action3Lable->setPosition(-50 * r3, +50);
	action3Lable->setColor(Color3B(0, 0, 0));
	action3Lable->setTag(32);

	MenuItemFont* action4Lable = MenuItemFont::create("ACTION4", CC_CALLBACK_1(BattleMenuLayer::chooseActionMenu, this));
	action4Lable->setPosition(-50 * r3, -50);
	action4Lable->setColor(Color3B(0, 0, 0));
	action4Lable->setTag(33);

	auto pMenu = Menu::create(action1Lable, action2Lable, action3Lable, action4Lable, NULL);
	pMenu->setPosition(PointX, PointY);
	pMenu->setTag(300);
	addChild(pMenu);
}
void  BattleMenuLayer::removeActionMenu()
{
	this->removeChildByTag(300);

}
void  BattleMenuLayer::printAttackMenu()
{
	float r3 = 1.732; //루트 3 

	int PointX = getBattleControler()->getTempPoint().x * 100 + 140;
	int PointY = getBattleControler()->getTempPoint().y * 100 + 60;
	CSkill* skill[6];
	std::string  skillName[6];
	for (int i = 0; i < 6; i++)
	{
		skill[i] = DynamicContentsContainer::getInstance()->getCharacter()->getSkill(i);
		if (skill[i] == NULL)
			skillName[i] = " ";
		else
			skillName[i] = skill[i]->getName();
	}

	MenuItemFont* 	skill1Lable = MenuItemFont::create(skillName[0], CC_CALLBACK_1(BattleMenuLayer::chooseAttackMenu, this));

	if (skill[0] != NULL)
	{
		skill1Lable->setPosition(+50 * r3, -50);
		skill1Lable->setColor(Color3B(0, 0, 0));
		skill1Lable->setTag(40);
	}
	MenuItemFont* skill2Lable = MenuItemFont::create(skillName[1], CC_CALLBACK_1(BattleMenuLayer::chooseAttackMenu, this));
	if (skill[0] != NULL)
	{
		skill2Lable->setPosition(+50 * r3, +50);
		skill2Lable->setColor(Color3B(0, 0, 0));
		skill2Lable->setTag(41);
	}

	MenuItemFont* skill3Lable = MenuItemFont::create(skillName[2], CC_CALLBACK_1(BattleMenuLayer::chooseAttackMenu, this));
	if (skill[0] != NULL)
	{
		skill3Lable->setPosition(-50 * r3, +50);
		skill3Lable->setColor(Color3B(0, 0, 0));
		skill3Lable->setTag(42);
	}

	MenuItemFont* skill4Lable = MenuItemFont::create(skillName[3], CC_CALLBACK_1(BattleMenuLayer::chooseAttackMenu, this));
	if (skill[0] != NULL)
	{
		skill4Lable->setPosition(-50 * r3, -50);
		skill4Lable->setColor(Color3B(0, 0, 0));
		skill4Lable->setTag(43);
	}

	MenuItemFont* skill5Lable = MenuItemFont::create(skillName[4], CC_CALLBACK_1(BattleMenuLayer::chooseAttackMenu, this));
	if (skill[0] != NULL)
	{
		skill5Lable->setPosition(0, 100);
		skill5Lable->setColor(Color3B(0, 0, 0));
		skill5Lable->setTag(44);
	}

	auto pMenu = Menu::create(skill1Lable, skill2Lable, skill3Lable, skill4Lable, skill5Lable,NULL);
	if (skill[0] != NULL)
	{
		pMenu->setPosition(PointX, PointY);
		pMenu->setTag(400);
		addChild(pMenu);
	}
}
void  BattleMenuLayer::removeAttackMenu()
{
	this->removeChildByTag(400); 
}

void BattleMenuLayer::chooseRapidMenu(Object* pSender)
{
	auto item = (MenuItem*)pSender;
	int index = item->getTag();
	Scene* fieldScene = NULL;
	removeRapidMenu();
	switch (index)
	{
	case 10:
		m_battleControler->setTurnType(3); // move
		break;
	case 11:
		m_battleControler->setTurnType(2); // 가방

		break;
	case 12:
		m_battleControler->setTurnType(1); //도망
		fieldScene = FieldScene::createScene();
		Director::getInstance()->replaceScene(fieldScene);
		break;
	default:
		return;
		break;
	}
	
}

void BattleMenuLayer::chooseNomalMenu(Object* pSender)
{

	auto item = (MenuItem*)pSender;
	int index = item->getTag();

	removeRapidMenu();
	removeNomalMenu();
	switch (index)
	{
	case 20:

		m_battleControler->setTurnType(4); // 액션
		printActionMenu();
		return;
	case 21:
		this->printAttackMenu();

		break;
	case 22:
		m_battleControler->setTurnType(0); // 종료
		m_battleControler->TurnEnd();
		m_battleControler->setStopFlag(0);

		break;
	default:
		return;
		break;
	}

}


void  BattleMenuLayer::chooseActionMenu(Object* pSender)
{
	auto item = (MenuItem*)pSender;
	int index = item->getTag();
	removeActionMenu();

	switch (index)
	{
	case 30:

		m_battleControler->setTurnType(7); //

		break;
	case 31:
		m_battleControler->setTurnType(8); //

		break;
	case 32:
		m_battleControler->setTurnType(9); // 
		break;
	case 33:
		m_battleControler->setTurnType(10); // 
		break;
	default:
		return;
		break;
	}
	m_battleControler->TurnEnd();
}
void  BattleMenuLayer::chooseAttackMenu(Object* pSender)
{
	auto item = (MenuItem*)pSender;
	int index = item->getTag();
	m_battleControler->setTurnType(5); //공격
	removeAttackMenu();
	int i=0;
	switch (index)
	{
	case 40:
		i = index - 40;
		if (DynamicContentsContainer::getInstance()->getCharacter()->getSkill(i) != NULL)
			getBattleControler()->setCurSkill(DynamicContentsContainer::getInstance()->getCharacter()->getSkill(i));
		break;
	case 41:

		i = index - 40;
		if (DynamicContentsContainer::getInstance()->getCharacter()->getSkill(i) != NULL)
			getBattleControler()->setCurSkill(DynamicContentsContainer::getInstance()->getCharacter()->getSkill(i));
		break;
	case 42:
	
		i = index - 40;
		if (DynamicContentsContainer::getInstance()->getCharacter()->getSkill(i) != NULL)
			getBattleControler()->setCurSkill(DynamicContentsContainer::getInstance()->getCharacter()->getSkill(i));
		break;
	case 43:


		i = index - 40;
		if (DynamicContentsContainer::getInstance()->getCharacter()->getSkill(i) != NULL)
			getBattleControler()->setCurSkill(DynamicContentsContainer::getInstance()->getCharacter()->getSkill(i));

		break;
	case 44:
		i = index - 40;
		if (DynamicContentsContainer::getInstance()->getCharacter()->getSkill(i) != NULL)
			getBattleControler()->setCurSkill(DynamicContentsContainer::getInstance()->getCharacter()->getSkill(i));
		break;
	case 45:
		i = index - 40;
		if (DynamicContentsContainer::getInstance()->getCharacter()->getSkill(i) != NULL)
			getBattleControler()->setCurSkill(DynamicContentsContainer::getInstance()->getCharacter()->getSkill(i));
		break;
	default:
		return;
		break;

	}
}