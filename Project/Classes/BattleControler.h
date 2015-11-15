#ifndef _BattleControler__
#define _BattleControler__


class BattleControler
{
public:
	BattleControler(); // ������
	~BattleControler(); // �Ҹ���

	void timeUp(); //  // �ð��� �ö�� �Լ��� 

	void MonsterTurn(int index);

	void setTurnType(int turnType){ this->turnType = turnType; }
	int getTurnType(){ return this->turnType; }

	void setCharacterGauge(int CharacterGauge){ this->CharacterGauge = CharacterGauge; }
	int getCharacterGauge(){ return this->CharacterGauge; }
	
	void setMonGauge(int MonGauge,int index){ this->MonGauge[index] = MonGauge; }
	int getMonGauge(int index){ return this->MonGauge[index]; }

	void setStopFlag(bool stopflag){ this->stopflag = stopflag; }
	bool isStopFlag(){ return this->stopflag; }
	

	void TurnEnd();

private:
	int CharacterGauge;
	int MonGauge[10];
	bool stopflag; // �Ͽ� ���޽�	
	int turnType;
 };



#endif 