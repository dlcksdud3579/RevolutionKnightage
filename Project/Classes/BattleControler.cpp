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
	int dice;
	for (int i = 0; i < 10; i++)
	{
		if (DynamicContentsContainer::getInstance()->getMonster(i) == NULL)
			continue;
		mon[i] = DynamicContentsContainer::getInstance()->getMonster(i);
		for (int j = 0; j < 10; j++)
		{
			if (mon[i]->getPoint().x == Point.x + getCurSkill()->getSplash(j).x &&mon[i]->getPoint().y == Point.y + getCurSkill()->getSplash(j).y)
			{
				dice = DynamicContentsContainer::getInstance()->getDice()->rollDice(getCurSkill()->getDiceType(), getCurSkill()->getDiceNum());
				mon[i]->getStatus()->setHp(mon[i]->getStatus()->getHp() - dice);
				log("attacked:monseter[%d]", i);
				getEffectLayer()->changeDice(dice);
				
				break;
			}
		}
	}
	setCurSkill(NULL);
}
void BattleControler::dieMon(int index)
{
	CMonster* mon = DynamicContentsContainer::getInstance()->getMonster(index);
	delete(mon);

	DynamicContentsContainer::getInstance()->setMonster(NULL,index);
	log("die:monseter[%d]", index);
}

void BattleControler::monsterAttack(int index)
{
	CMonster *mon = DynamicContentsContainer::getInstance()->getMonster(index);
	CCharacter *hero = DynamicContentsContainer::getInstance()->getCharacter();
	for (int i = 0; i < 10; i++)
	{
		if (mon->getSkill(i) == NULL)
			return;
		CSkill* skill = mon->getSkill(i);
		int range = skill->getRange();

		if (mon->getPoint().x - range<= hero->getPoint().x && hero->getPoint().x <= mon->getPoint().x + range && 
			mon->getPoint().y - range<= hero->getPoint().y && hero->getPoint().y <= mon->getPoint().y + range)
		{
			hero->getStatus()->setHp(hero->getStatus()->getHp() - rand()%6);
			getEffectLayer()->printAttack(Vec2(m_tempPoint.x*100 +140, m_tempPoint.y*100+60));
		}


	}
}

void BattleControler::setMonsterDir(int index)
{
	CMonster *mon = DynamicContentsContainer::getInstance()->getMonster(index);
	CCharacter *hero = DynamicContentsContainer::getInstance()->getCharacter();

	if (hero->getPoint().x < mon->getPoint().x)
	{
		mon->setDir(2);
		return;
	}
	else if (hero->getPoint().x > mon->getPoint().x)
	{
		mon->setDir(1);
		return;
	}
	if (hero->getPoint().y < mon->getPoint().y)
	{
		mon->setDir(4);
		return;
	}
	else if (hero->getPoint().y > mon->getPoint().y)
	{
		mon->setDir(3);
		return;
	}
}