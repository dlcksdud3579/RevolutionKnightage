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
		return; // �̹� ������� 
	Size winSize = CCDirector::getInstance()->getVisibleSize();

	// �޴�â Ʋ ����
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
		return; //�̹� ������� 

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

