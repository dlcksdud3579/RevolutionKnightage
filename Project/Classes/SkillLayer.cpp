#include "InvenLayer.h"


bool InvenLayer::init()
{
	if (!InvenLayer::initWithColor(Color4B(0, 0, 0, 0)))
	{
		return false;
	}
	setOpenFlag(false);



	return true;
}

void InvenLayer::onEnter()
{
	Layer::onEnter();
	setOpenFlag(false);


}

void InvenLayer::onExit()
{
	Layer::onExit();
}

void InvenLayer::Open()
{
	if (isOpenFlag() == true)
		return; // 이미 열린경우 
	Size winSize = CCDirector::getInstance()->getVisibleSize();

	// 메뉴창 틀 띄우기
	int w = winSize.width - 200;
	int h = winSize.height - 20;
	m_panel = Sprite::create("Menu/panel.png");  // 
	m_panel->setPosition(w * 1 / 4, h * 1 / 4);
	addChild(m_panel);

	setOpenFlag(true);

}
void InvenLayer::Close()
{
	if (isOpenFlag() == false)
		return; //이미 닫힌경우 

	removeChild(m_panel);
	setOpenFlag(false);

}
InvenLayer::InvenLayer()
{
	//m_panel->retain();
	//this->retain();
}
InvenLayer::~InvenLayer()
{
	//m_panel->release();
	//this->release();
}

