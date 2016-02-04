#include "StatusLayer.h"


bool StatusLayer::init()
{
	if (!StatusLayer::initWithColor(Color4B(0, 0, 0, 0)))
	{
		return false;
	}
	setOpenFlag(false);



	return true;
}

void StatusLayer::onEnter()
{
	Layer::onEnter();
	setOpenFlag(false);


}

void StatusLayer::onExit()
{
	Layer::onExit();
}

void StatusLayer::Open()
{
	if (isOpenFlag() == true)
		return; // 이미 열린경우 
	Size winSize = CCDirector::getInstance()->getVisibleSize();

	// 메뉴창 틀 띄우기
	int w = winSize.width - 200;
	int h = winSize.height - 20;
	m_panel = Sprite::create("Menu/panel.png");  // 
	m_panel->setPosition(w * 3 / 4, h * 1 / 4);
	addChild(m_panel);

	setOpenFlag(true);

}
void StatusLayer::Close()
{
	if (isOpenFlag() == false)
		return; //이미 닫힌경우 

	removeChild(m_panel);
	setOpenFlag(false);

}
StatusLayer::StatusLayer()
{
	//m_panel->retain();
	//this->retain();
}
StatusLayer::~StatusLayer()
{
	//m_panel->release();
	//this->release();
}

