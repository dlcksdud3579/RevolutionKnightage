#include "SkillLayer.h"


bool SkillLayer::init()
{
	if (!SkillLayer::initWithColor(Color4B(0, 0, 0, 0)))
	{
		return false;
	}
	setOpenFlag(false);

	return true;
}

void SkillLayer::onEnter()
{
	Layer::onEnter();
	setOpenFlag(false);


}

void SkillLayer::onExit()
{
	Layer::onExit();
}

void SkillLayer::Open()
{
	if (isOpenFlag() == true)
		return; // �̹� ������� 
	Size winSize = CCDirector::getInstance()->getVisibleSize();

	// �޴�â Ʋ ����
	int w = winSize.width - 200;
	int h = winSize.height - 20;
	m_panel = Sprite::create("Menu/Skill.png");
	m_panel->setPosition(w * 1 / 4, h * 3 / 4);
	addChild(m_panel);

	setOpenFlag(true);

}
void SkillLayer::Close()
{
	if (isOpenFlag() == false)
		return; //�̹� ������� 

	removeChild(m_panel);
	setOpenFlag(false);

}
SkillLayer::SkillLayer()
{
	//m_panel->retain();
	//this->retain();
}
SkillLayer::~SkillLayer()
{
	//m_panel->release();
	//this->release();
}

