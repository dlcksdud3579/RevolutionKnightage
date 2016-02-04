#include "MenuLayer.h"




bool MenuLayer::init()
{
	if (!LayerColor::initWithColor(Color4B(0, 0, 0, 0)))
	{
		return false;
	}
	
	Size winSize = CCDirector::getInstance()->getVisibleSize();  // 화면 사이즈
	


	// 메뉴 판을 띄운다
	MenuPanel = Sprite::create("Menu/menu.png");
	
	MenuPanel->setPosition(winSize.width + (80 / 2), winSize.height - (720 / 2));
	this->addChild(MenuPanel,1);
	// 메뉴 판을 띄웠다

	// 메뉴판위 메뉴들

	Inven = MenuItemFont::create("inven",
		CC_CALLBACK_1(MenuLayer::clickMenu, this));
	Inven->setTag(1);
	Inven->setPosition(winSize.width/2 + (150 / 2), winSize.height*2/5 * 3 / 5);
	Inven->setScale(1.5);
	Inven->setColor(Color3B(0,0,0));

	status = MenuItemFont::create("status",
		CC_CALLBACK_1(MenuLayer::clickMenu, this));
	status->setPosition(winSize.width / 2 + (150 / 2), winSize.height * 2 / 5 * 1 / 5);
	status->setTag(2);
	status->setScale(1.5);
	status->setColor(Color3B(0, 0, 0));

	skill = MenuItemFont::create("skill",
		CC_CALLBACK_1(MenuLayer::clickMenu, this));
	skill->setPosition(winSize.width / 2 + (150 / 2), winSize.height * 2 / 5 * -1 / 5);
	skill->setTag(3);
	skill->setScale(1.5);
	skill->setColor(Color3B(0, 0, 0));

	setUp = MenuItemFont::create("option",
		CC_CALLBACK_1(MenuLayer::clickMenu, this));
	setUp->setTag(4);
	setUp->setPosition(winSize.width / 2 + (150 / 2), winSize.height * 2 / 5 * -3 / 5);
	setUp->setScale(1.5);
	setUp->setColor(Color3B(0, 0, 0));
	// ~메뉴판위 메뉴들

	pMenu = Menu::create(Inven, status, skill, setUp, NULL);
	// 메뉴들
	this->addChild(pMenu, 2); // 자녀 추가 


	this->setInvenLayer(InvenLayer::create());  // 인벤 레이어 
	this->setSetupLayer(SetUpLayer::create());  // setUp 레이어 
	this->setSkillLayer(SkillLayer::create());  // skill 레이어 
	this->setStatusLayer(StatusLayer::create());  // 스텟 레이어 

	addChild(getInvenLayer(),3);



	return true;
}

void MenuLayer::onEnter()
{
	Layer::onEnter();
	setOpenFlag(false);

}

void MenuLayer::onExit()
{
	Layer::onExit();
}

void MenuLayer::Open()
{
	if (isOpenFlag() == true)
		return;
	auto move1 = MoveBy::create(0.5, Vec2(-370 / 2, 0));
	auto move2 = MoveBy::create(0.5, Vec2(-370 / 2, 0));
	MenuPanel->runAction(move1);
	pMenu->runAction(move2);
	setOpenFlag(true);
	
}
void MenuLayer::Close()
{
	if (isOpenFlag() == false)
		return;
	if (getInvenLayer()->isOpenFlag() == true)
		return;
	if (getSetupLayer()->isOpenFlag() == true)
		return;
	if (getStatusLayer()->isOpenFlag() == true)
		return;
	if (getSkillLayer()->isOpenFlag() == true)
		return;

	auto move1 = MoveBy::create(0.5, Vec2(370 / 2, 0));
	auto move2 = MoveBy::create(0.5, Vec2(370 / 2, 0));

	MenuPanel->runAction(move1);
	pMenu->runAction(move2);
	setOpenFlag(false);
}
void MenuLayer::clickMenu(Object* pSender)
{
	auto item = (MenuItem*)pSender;
	int index = item->getTag();
	log("%d", index);
	switch (index)
	{
	case 1:
		openInven();
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		  break;
	default:
		break;
	}
}

void  MenuLayer::openInven()
{
	if (getInvenLayer()->isOpenFlag() == false)
	{
		log("open");
		getInvenLayer()->Open();
	}
	else if (getInvenLayer()->isOpenFlag() == true)
	{
		log("close");
		getInvenLayer()->Close();
	}
}


void  MenuLayer::openStatus()
{
	if (getStatusLayer()->isOpenFlag() == false)
	{
		log("open");
		getStatusLayer()->Open();
	}
	else if (getStatusLayer()->isOpenFlag() == true)
	{
		log("close");
		getStatusLayer()->Close();
	}
}

void  MenuLayer::openSkill()
{
	if (getSkillLayer()->isOpenFlag() == false)
	{
		log("open");
		getSkillLayer()->Open();
	}
	else if (getSkillLayer()->isOpenFlag() == true)
	{
		log("close");
		getSkillLayer()->Close();
	}
}

void  MenuLayer::openOption()
{
	if (getSetupLayer()->isOpenFlag() == false)
	{
		log("open");
		getSetupLayer()->Open();
	}
	else if (getSetupLayer()->isOpenFlag() == true)
	{
		log("close");
		getSetupLayer()->Close();
	}
}

