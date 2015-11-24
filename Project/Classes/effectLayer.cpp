#include "effectLayer.h"


bool effectLayer::init()
{
	if (!effectLayer::initWithColor(Color4B(0, 0, 0, 0)))
	{
		return false;
	}




	return true;
}

void effectLayer::printDice()
{
	Dice = LabelTTF::create("%d", "fonts/arial.ttf", 40);
}
void effectLayer::printAttack()
{
	Attack = LabelTTF::create("ATTACK", "fonts/arial.ttf", 40);
}
void effectLayer::changeDice()
{

}
void effectLayer::removeAttack(float delta)
{
	removeChild(Attack);
}