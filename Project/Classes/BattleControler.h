#ifndef _BattleControler__
#define _BattleControler__
class BattleControler
{
public:
	BattleControler();
	~BattleControler();

	void timeUp();

	void run(float delta);
private:
	int CharacterGauge;
	int MonGauge[10];
};



#endif 