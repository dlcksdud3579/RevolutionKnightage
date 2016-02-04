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
		return; // �̹� ������� 
	Size winSize = CCDirector::getInstance()->getVisibleSize();

	// �޴�â Ʋ ����
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
		return; //�̹� ������� 

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

