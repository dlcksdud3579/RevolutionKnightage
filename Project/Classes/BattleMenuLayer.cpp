#include "BattleMenuLayer.h"
#include "DynamicContentsContainer.h"

bool BattleMenuLayer::init() // 기본 메인 
{ 
	if (!BattleMenuLayer::initWithColor(Color4B(0, 0, 0, 0)))
	{
		return false;
	}
	return true;
}

void BattleMenuLayer::printNomalMenu() // 노멀  메뉴 구현 
{
	BattleMenuLayer::removeMenu();
	menufalg = 1;
	float r3 = 1.732; //루트 3 
	//Vec2 Point = DynamicContentsContainer::getInstance()->getCharacter()->getPoint(); // 현재 캐릭터 위치 

	int PointX = this->getTurnControler()->getMenuPoint().x * 100 + 140; // 메뉴 위치  X 
	int PointY = this->getTurnControler()->getMenuPoint().y * 100 + 60;  // 메뉴 위치 Y

	// 메뉴 "mvoe"
	MenuItemFont* moveLable = MenuItemFont::create("BlANK",   
		CC_CALLBACK_1(BattleMenuLayer::chooseNomalMenu, this));
	moveLable->setPosition(50 * r3, 50);
	moveLable->setColor(Color3B(255, 255, 255));
	moveLable->setTag(10);
	// 메뉴 "mvoe"

	// 메뉴 "BAG"
	MenuItemFont* InvenLable = MenuItemFont::create("BAG", CC_CALLBACK_1(BattleMenuLayer::chooseNomalMenu, this));
	InvenLable->setPosition(-50 * r3, -50);
	InvenLable->setColor(Color3B(255, 255, 255));
	InvenLable->setTag(11);
	// 메뉴 "BAG"

	// 메뉴 "ESC"
	MenuItemFont* escLable = MenuItemFont::create("ESC", CC_CALLBACK_1(BattleMenuLayer::chooseNomalMenu, this));
	escLable->setPosition(-50 * r3, +50);
	escLable->setColor(Color3B(255, 255, 255));
	escLable->setTag(12);
	// 메뉴 "ESC"

	// 메뉴 "ACTION"
	MenuItemFont* actionLable = MenuItemFont::create("ACTION", CC_CALLBACK_1(BattleMenuLayer::chooseNomalMenu, this));
	actionLable->setPosition( + 50 * r3,  - 50);
	actionLable->setColor(Color3B(255, 255, 255));
	actionLable->setTag(13);
	// 메뉴 "ACTION"

	// 메뉴 "ATTACK"
	MenuItemFont* attakLable = MenuItemFont::create("ATTACK", CC_CALLBACK_1(BattleMenuLayer::chooseNomalMenu, this));
	attakLable->setPosition(0,  + 100);
	attakLable->setColor(Color3B(255, 255, 255));
	attakLable->setTag(14);
	// 메뉴 "ATTACK"

	// 메뉴 "END"
	MenuItemFont* endLable = MenuItemFont::create("END", CC_CALLBACK_1(BattleMenuLayer::chooseNomalMenu, this));
	endLable->setPosition(0,  - 100);
	endLable->setColor(Color3B(255, 255, 255));
	endLable->setTag(15);
	// 메뉴 "END"

	//메뉴 구현 
	auto pMenu = Menu::create(moveLable, InvenLable, escLable, actionLable, attakLable, endLable, NULL); 
	pMenu->setPosition(PointX, PointY);
	pMenu->setTag(200);
	addChild(pMenu);
	//메뉴 구현 


}

void BattleMenuLayer::removeMenu()
{
	switch (menufalg)
	{
	case 0:
		break;
	case 1:
		void removeNomalMenu();// 기본 행동 메뉴제거 
		break;
	case 2:	
		void removeActionMenu(); // 액션 메뉴 제거 
		break;
	case 3:
		void removeAttackMenu(); // 공격 메뉴 제거 
		break;
	default:
		break;
	}
	menufalg = 0;
}

void  BattleMenuLayer::removeNomalMenu() // 메뉴 제거 
{
	menufalg = 0;
	this->removeChildByTag(200);

}

void  BattleMenuLayer::printActionMenu() // 액션 메뉴 구현 
{
	float r3 = 1.732; //루트 3 
	menufalg = 2;
	Vec2 Point = DynamicContentsContainer::getInstance()->getCharacter()->getPoint(); // 현재 캐릭터 위치 

	int PointX = Point.x * 100 + 140; // 메뉴 위치  X 
	int PointY = Point.y * 100 + 60;  // 메뉴 위치 Y

	MenuItemFont* action1Lable = MenuItemFont::create("ACTION1", CC_CALLBACK_1(BattleMenuLayer::chooseActionMenu, this));
	action1Lable->setPosition(50 * r3, 50);
	action1Lable->setColor(Color3B(255, 255, 255));
	action1Lable->setTag(30);

	MenuItemFont* action2Lable = MenuItemFont::create("ACTION2", CC_CALLBACK_1(BattleMenuLayer::chooseActionMenu, this));
	action2Lable->setPosition(-50 * r3, -50);
	action2Lable->setColor(Color3B(255, 255, 255));
	action2Lable->setTag(31);

	MenuItemFont* action3Lable = MenuItemFont::create("ACTION3", CC_CALLBACK_1(BattleMenuLayer::chooseActionMenu, this));
	action3Lable->setPosition(-50 * r3, +50);
	action3Lable->setColor(Color3B(255, 255, 255));
	action3Lable->setTag(32);

	MenuItemFont* action4Lable = MenuItemFont::create("ACTION4", CC_CALLBACK_1(BattleMenuLayer::chooseActionMenu, this));
	action4Lable->setPosition(+50 * r3, -50);
	action4Lable->setColor(Color3B(255, 255, 255));
	action4Lable->setTag(33);

	MenuItemFont* action5Lable = MenuItemFont::create("ACTION5", CC_CALLBACK_1(BattleMenuLayer::chooseActionMenu, this));
	action4Lable->setPosition(0, 100);
	action4Lable->setColor(Color3B(255, 255, 255));
	action4Lable->setTag(34);

	MenuItemFont* BackLable = MenuItemFont::create("BACK", CC_CALLBACK_1(BattleMenuLayer::chooseActionMenu, this));
	action4Lable->setPosition(0, -100);
	action4Lable->setColor(Color3B(255, 255, 255));
	action4Lable->setTag(35);


	auto pMenu = Menu::create(action1Lable, action2Lable, action3Lable, action4Lable, action5Lable, BackLable, NULL);
	pMenu->setPosition(PointX, PointY);
	pMenu->setTag(300);
	addChild(pMenu);
}

void  BattleMenuLayer::removeActionMenu()// 액션 메뉴 제거 
{
	menufalg = 0;
	this->removeChildByTag(300);

}

void  BattleMenuLayer::printAttackMenu()// 공격 메뉴 구현 
{
	float r3 = 1.732; //루트 3 
	menufalg = 3;
	Vec2 Point = DynamicContentsContainer::getInstance()->getCharacter()->getPoint(); // 현재 캐릭터 위치 

	int PointX = Point.x * 100 + 140; // 메뉴 위치  X 
	int PointY = Point.y * 100 + 60;  // 메뉴 위치 Y

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
		skill1Lable->setColor(Color3B(255, 255, 255));
		skill1Lable->setTag(40);
	}
	MenuItemFont* skill2Lable = MenuItemFont::create(skillName[1], CC_CALLBACK_1(BattleMenuLayer::chooseAttackMenu, this));
	if (skill[0] != NULL)
	{
		skill2Lable->setPosition(+50 * r3, +50);
		skill2Lable->setColor(Color3B(255, 255, 255));
		skill2Lable->setTag(41);
	}

	MenuItemFont* skill3Lable = MenuItemFont::create(skillName[2], CC_CALLBACK_1(BattleMenuLayer::chooseAttackMenu, this));
	if (skill[0] != NULL)
	{
		skill3Lable->setPosition(-50 * r3, +50);
		skill3Lable->setColor(Color3B(255, 255, 255));
		skill3Lable->setTag(42);
	}

	MenuItemFont* skill4Lable = MenuItemFont::create(skillName[3], CC_CALLBACK_1(BattleMenuLayer::chooseAttackMenu, this));
	if (skill[0] != NULL)
	{
		skill4Lable->setPosition(-50 * r3, -50);
		skill4Lable->setColor(Color3B(255, 255, 255));
		skill4Lable->setTag(43);
	}

	MenuItemFont* skill5Lable = MenuItemFont::create(skillName[4], CC_CALLBACK_1(BattleMenuLayer::chooseAttackMenu, this));
	if (skill[0] != NULL)
	{
		skill5Lable->setPosition(0, 100);
		skill5Lable->setColor(Color3B(255, 255, 255));
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

void  BattleMenuLayer::removeAttackMenu() // 공격 메뉴 삭제 
{
	menufalg = 0;
	this->removeChildByTag(400); 
}

void BattleMenuLayer::chooseNomalMenu(Object* pSender) // 메뉴를 선택 했을 때 불려지는 함수 
{
	auto item = (MenuItem*)pSender;
	int index = item->getTag();
	Scene* fieldScene = NULL;
	removeNomalMenu();
	
	switch (index)
	{
	case 10:// 
		break;
	case 11:// 가방
		break;
	case 12://도망
		Director::getInstance()->replaceScene(fieldScene);
		break;
	case 13:// 액션
		printActionMenu();
		return;
	case 14:
		this->printAttackMenu();
		break;

	case 15:// 종료

		break;
	default:
		return;
		break;
	}

}

void  BattleMenuLayer::chooseActionMenu(Object* pSender) // 액션 에서 메뉴 사용시 불려지는함수 
{
	auto item = (MenuItem*)pSender;
	int index = item->getTag();
	removeActionMenu();

	switch (index)
	{
	case 30:// 액션 1

		break;
	case 31:// 액션 2


		break;
	case 32:// 액션 3


		break;
	case 33:// 액션 4

		break;
	case 34:// 액션 5

	case 35:// BACK
		printNomalMenu();
		break;
	default:
		return;
		break;
	}
}

void  BattleMenuLayer::chooseAttackMenu(Object* pSender) // 공격 메뉴 에서 불려  지는 함수 
{
	auto item = (MenuItem*)pSender;
	int index = item->getTag();
	removeAttackMenu();
	int skillIndex=0;// 스킬 넘버 


	switch (index)
	{
	case 40:
		skillIndex = index - 40; // 0번 스킬 
		if (DynamicContentsContainer::getInstance()->getCharacter()->getSkill(skillIndex) != NULL)
			//getBattleControler()->setCurSkill(DynamicContentsContainer::getInstance()->getCharacter()->getSkill(skillIndex)); // 스킬 사용 
		break;
	case 41:

		skillIndex = index - 40; // 1번 스킬 
		if (DynamicContentsContainer::getInstance()->getCharacter()->getSkill(skillIndex) != NULL)
			//getBattleControler()->setCurSkill(DynamicContentsContainer::getInstance()->getCharacter()->getSkill(skillIndex));// 스킬 사용 
		break;
	case 42:
	
		skillIndex = index - 40; //2번 스킬
		if (DynamicContentsContainer::getInstance()->getCharacter()->getSkill(skillIndex) != NULL)
			//getBattleControler()->setCurSkill(DynamicContentsContainer::getInstance()->getCharacter()->getSkill(skillIndex));// 스킬 사용 
		break;
	case 43:


		skillIndex = index - 40; //3번 스킬
		if (DynamicContentsContainer::getInstance()->getCharacter()->getSkill(skillIndex) != NULL)
			//getBattleControler()->setCurSkill(DynamicContentsContainer::getInstance()->getCharacter()->getSkill(skillIndex));// 스킬 사용 

		break;
	case 44:
		skillIndex = index - 40; //4번 스킬
		if (DynamicContentsContainer::getInstance()->getCharacter()->getSkill(skillIndex) != NULL)
			//getBattleControler()->setCurSkill(DynamicContentsContainer::getInstance()->getCharacter()->getSkill(skillIndex));// 스킬 사용 
		break;
	case 45:
		skillIndex = index - 40; //BACK

		if (DynamicContentsContainer::getInstance()->getCharacter()->getSkill(skillIndex) != NULL)
			//getBattleControler()->setCurSkill(DynamicContentsContainer::getInstance()->getCharacter()->getSkill(skillIndex));// 스킬 사용 
		break;
	default:
		return;
		break;

	}
}