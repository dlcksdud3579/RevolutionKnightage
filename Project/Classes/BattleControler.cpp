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
	setMoveCnt(0);
	setCurSkill(NULL);

}

BattleControler::~BattleControler()
{

}
void BattleControler::timeUp()
{
	if (stopflag ==1) // 턴진행중에는 멈춤;
		return;

	CharacterGauge += DynamicContentsContainer::getInstance()->getCharacter()->getStatus()->getSpeed(); // 출발속도 지정 
	for (int i = 0; i < 10; i++)// 몬스터들 지정
	{
		if (DynamicContentsContainer::getInstance()->getMonster(i) != NULL)
			this->MonGauge[i] += DynamicContentsContainer::getInstance()->getMonster(i)->getStatus()->getSpeed();
	}
}
void BattleControler::TurnEnd()
{
	stopflag == 0;
	setTurnType(0);
	setMoveCnt(0);
	setCurSkill(NULL);
}


void BattleControler::MonsterTurn(int index)
{

}


void BattleControler::setTurnType(int turnType)
{
	CCharacter * Character = DynamicContentsContainer::getInstance()->getCharacter();
	switch (turnType)
	{
	case 2:
	case 3://무브 
		break;
	default:
		
		break;
	}
	this->turnType = turnType;
}
void  BattleControler::AttackStart(int index)
{
	this->setCurSkill(DynamicContentsContainer::getInstance()->getCharacter()->getSkill(index));

}
void BattleControler::damageMon(Vec2 Point)
{
	CMonster* mon[10];

	for (int i = 0; i < 10; i++)
	{
		if (DynamicContentsContainer::getInstance()->getMonster(i) == NULL)
			continue;
		mon[i] = DynamicContentsContainer::getInstance()->getMonster(i);
		for (int j = 0; j < 10; j++)
		{
			if (mon[i]->getPoint().x == getCurSkill()->getSplash(j).x &&mon[i]->getPoint().y == getCurSkill()->getSplash(j).y)
			{
				mon[i]->getStatus()->setHp(mon[i]->getStatus()->getHp() - DynamicContentsContainer::getInstance()->getDice()->rollDice(getCurSkill()->getDiceType(), getCurSkill()->getDiceNum()));
				if (mon[i]->getStatus()->getHp() <= 0)
					dieMon(i);
			}
		}
	}
	setCurSkill(NULL);
}
void BattleControler::dieMon(int index)
{
	DynamicContentsContainer::getInstance()->setMonster(NULL,index);
}