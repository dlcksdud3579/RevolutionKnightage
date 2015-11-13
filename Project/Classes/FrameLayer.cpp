#include "FrameLayer.h"


USING_NS_CC;

bool FrameLayer::init()
{
	if (!LayerColor::initWithColor(Color4B(0, 0, 0, 0)))
	{
		return false;
	}
	auto l1 = Sprite::create("frame/l.png");
	auto l2 = Sprite::create("frame/l.png");


	l1->setPosition(45, 360);
	this->addChild(l1);

	l2->setPosition(1280-45, 360);
	this->addChild(l2);





	return true;
}