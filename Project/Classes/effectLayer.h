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
	void printAttack(Vec2 point);
	void changeDice(int num);

	void removeAttack(float delta);
	CREATE_FUNC(effectLayer);


private:
	LabelTTF * Dice;
	LabelTTF * DiceNum;
	LabelTTF * Attack;
	string m_dicenum;
};


#endif //_FRAMELAYER_H_