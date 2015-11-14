#ifndef _BattleControler__
#define _BattleControler__
class BattleControler
{
public:
	BattleControler(); // 생성자
	~BattleControler(); // 소멸자

	void timeUp(); //  // 시간이 올라는 함수요 

	//void run(float delta); // 스케쥴러로 돌아갈 함수요, 안되면 씬 스케쥴에  ㅣㅇ함ㅅ구 넣으면 되요 

	
	void MonsterTurn(int index);



	void setTurnType(int turnType){ this->turnType = turnType; }
	int getTurnType(){ return this->turnType; }

	void setCharacterGauge(int CharacterGauge){ this->CharacterGauge = CharacterGauge; }
	int getCharacterGauge(){ return this->CharacterGauge; }
	
	void setMonGauge(int MonGauge,int index){ this->MonGauge[index] = MonGauge; }
	int getMonGauge(int index){ return this->MonGauge[index]; }

	void setStopFlag(bool stopflag){ this->stopflag = stopflag; }
	bool isStopFlag(){ return this->stopflag; }
	

private:
	int CharacterGauge;
	int MonGauge[10];
	bool stopflag; // 턴에 도달시	
	int turnType;
 };



#endif 