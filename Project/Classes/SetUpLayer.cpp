#include "SetUpLayer.h"


bool SetUpLayer::init()
{
	if (!SetUpLayer::initWithColor(Color4B(0, 0, 0, 0)))
	{
		return false;
	}
	setOpenFlag(false);



	return true;
}

void SetUpLayer::onEnter()
{
	Layer::onEnter();
	setOpenFlag(false);


}

void SetUpLayer::onExit()
{
	Layer::onExit();
}

void SetUpLayer::Open()
{
	if (isOpenFlag() == true)
		return; // 이미 열린경우 
	Size winSize = CCDirector::getInstance()->getVisibleSize();

	// 메뉴창 틀 띄우기
	int w = winSize.width - 200;
	int h = winSize.height - 20;
	m_panel = Sprite::create("Menu/panel.png");  // 
	m_panel->setPosition(w * 3 / 4, h * 3 / 4);
	addChild(m_panel);

	setOpenFlag(true);

}
void SetUpLayer::Close()
{
	if (isOpenFlag() == false)
		return; //이미 닫힌경우 

	removeChild(m_panel);
	setOpenFlag(false);

}
SetUpLayer::SetUpLayer()
{
	//m_panel->retain();
	//this->retain();
}
SetUpLayer::~SetUpLayer()
{
	//m_panel->release();
	//this->release();
}

