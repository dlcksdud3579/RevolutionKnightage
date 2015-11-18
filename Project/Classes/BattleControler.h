#ifndef _BattleControler__
#define _BattleControler__
#include "cocos2d.h"
USING_NS_CC;

class BattleControler
{
public:
	BattleControler(); // 생성자
	~BattleControler(); // 소멸자

	void timeUp(); //  // 시간이 올라는 함수요 

	void MonsterTurn(int index);

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

private:
	int CharacterGauge;
	int MonGauge[10];
	bool stopflag; // 턴에 도달시	
	int turnType;
	Vec2 m_tempPoint;
 };



#endif 