#ifndef _BattleControler__
#define _BattleControler__
#include "cocos2d.h"
#include "CSkill.h"
#include "effectLayer.h"
USING_NS_CC;

class BattleControler
{
public:
	BattleControler(); // 생성자
	~BattleControler(); // 소멸자

	void timeUp(); //  // 시간이 올라는 함수요 

	void MonsterTurn(int index);
	void AttackStart(int index);
	void damageMon(Vec2 Point);


	void setTurnType(int turnType);
	int getTurnType(){ return this->turnType; }

	void setCharacterGauge(int CharacterGauge){ this->CharacterGauge = CharacterGauge; }
	int getCharacterGauge(){ return this->CharacterGauge; }
	
	void setMonGauge(int MonGauge,int index){ this->MonGauge[index] = MonGauge; }
	int getMonGauge(int index){ return this->MonGauge[index]; }

	void setStopFlag(bool stopflag){ this->stopflag = stopflag; }
	bool isStopFlag(){ return this->stopflag; }
	
	void TurnEnd();

	void setTempPoint(Vec2 a_tempPoint){ this->m_tempPoint = a_tempPoint; }
	Vec2 getTempPoint(){ return this->m_tempPoint; }

	void setMoveCnt(int a_moveCnt){ this->m_moveCnt = a_moveCnt; }
	int getMoveCnt(){ return this->m_moveCnt; }



	void setCurSkill(CSkill* a_CurSkill){ this->m_CurSkill = a_CurSkill; }
	CSkill* getCurSkill(){ return this->m_CurSkill; }

	void dieMon(int index);
	void monsterAttack(int index);

	void setMonsterDir(int index);

	void setEffectLayer(effectLayer *a_effectLayer){ this->m_effectLayer = a_effectLayer; }
	effectLayer* getEffectLayer(){ return m_effectLayer; }

private:
	int CharacterGauge;
	int MonGauge[10];
	bool stopflag; // 턴에 도달시	
	int turnType; // 무브턴 3// 
	Vec2 m_tempPoint;
	int m_moveCnt;
	CSkill* m_CurSkill; // 현재 사용할 스킬
	effectLayer * m_effectLayer;

 };



#endif 