#include "BattleControler.h" 
#include "DynamicContentsContainer.h"	
#include "time.h"
#include "stdlib.h"

BattleControler::BattleControler()
{
	srand(time(NULL));
	CharacterGauge = DynamicContentsContainer::getInstance()->getDice()->rollDice(20);// ��߼ӵ� ���� 
	for (int i = 0; i < 10; i++)// ���͵� ����
	{
		if (DynamicContentsContainer::getInstance()->getMonster(i) != NULL);
		this->MonGauge[i] = rand() % 20 + 1;
	}


}

BattleControler::~BattleControler()
{

}
void BattleControler::timeUp()
{
	if (stopflag ==1) // �������߿��� ����;
		return;

	CharacterGauge += DynamicContentsContainer::getInstance()->getCharacter()->getStatus().getSpeed(); // ��߼ӵ� ���� 
	for (int i = 0; i < 10; i++)// ���͵� ����
	{
		if (DynamicContentsContainer::getInstance()->getMonster(i) != NULL);
		this->MonGauge[i] += DynamicContentsContainer::getInstance()->getMonster(i)->getStatus().getSpeed();
	}
}
void BattleControler::TurnEnd()
{
	stopflag == 0;
	setTurnType(0);
}


void BattleControler::MonsterTurn(int index)
{

}
