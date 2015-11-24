#ifndef _EFFECTLAYER_H_
#define _EFFECTLAYER_H_

#include "cocos2d.h"

USING_NS_CC;


using namespace std;

class effectLayer : public cocos2d::LayerColor
{
public:
	virtual bool init();
	void printDice();
	void printAttack();
	void changeDice();

	void removeAttack(float delta);
	CREATE_FUNC(effectLayer);


private:
	LabelTTF * Dice;
	LabelTTF * Attack;
};


#endif //_FRAMELAYER_H_