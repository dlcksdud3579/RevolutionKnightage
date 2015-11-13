#include "BattleControler.h" 
#include "DynamicContentsContainer.h"	
#include "time.h"
#include "stdlib.h"
BattleControler::BattleControler()
{
	srand(time(NULL));
	CharacterGauge = DynamicContentsContainer::getInstance()->getDice()->rollDice(20);// 출발속도 지정 
	for (int i = 0; i < 10; i++)// 몬스터들 지정
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
	CharacterGauge += DynamicContentsContainer::getInstance()->getCharacter()->getStatus().getSpeed(); // 출발속도 지정 
	for (int i = 0; i < 10; i++)// 몬스터들 지정
	{
		if (DynamicContentsContainer::getInstance()->getMonster(i) != NULL);
		this->MonGauge[i] += DynamicContentsContainer::getInstance()->getMonster(i)->getStatus().getSpeed();
	}
}
void BattleControler::run(float delta) // 0.2초마다
{
	timeUp();
	if (CharacterGauge >= 100)
	{

	}
	for (int i = 0; i < 10; i++)
	{
		if (this->MonGauge[i] >= 100)
		{

		}
	}
}
