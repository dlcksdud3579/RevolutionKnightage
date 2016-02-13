#include "effectLayer.h"


bool effectLayer::init()
{
	if (!effectLayer::initWithColor(Color4B(0, 0, 0, 0)))
	{
		return false;
	}
	printDice();
	return true;
}

void effectLayer::printDice()
{
	string m_dicenum = "";
	Dice = LabelTTF::create("Dice:", "fonts/arial.ttf", 40);
	Dice->setPosition(1000,100);
	DiceNum = LabelTTF::create(m_dicenum, "fonts/arial.ttf", 40);
	DiceNum->setPosition(1050, 100);

	addChild(Dice);
	addChild(DiceNum);
}

void effectLayer::printAttack(Vec2 point)
{
	Attack = LabelTTF::create("ATTACK", "fonts/arial.ttf", 40);
	Attack->setPosition(point);

	addChild(Attack);
	scheduleOnce(schedule_selector(effectLayer::removeAttack), 1.0f);
}

void effectLayer::changeDice(int num)
{
	string a = string(itoa(num,NULL,2));
	DiceNum->setString(a);

}

void effectLayer::removeAttack(float delta)
{
	removeChild(Attack);
}