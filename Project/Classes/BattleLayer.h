#ifndef _BATTLELAYER_H_
#define _BATTLELAYER_H_

#include "FieldLayer.h"
#include "BattleControler.h"

class BattleLayer :public FieldLayer
{
public:

	virtual bool init();
	CREATE_FUNC(FieldLayer);

	void moveCharacter(float delta);
	
	int getMaxMovePoint(){ return this->maxMovePoint; }
	void setMaxMovePoint(int a_maxMovePoint){ this->maxMovePoint = a_maxMovePoint; }

	int getMoveQue(){ return this->MoveQue[MovequeMIn++]; }
	void setMoveQue(int a_Move){ this->MoveQue[MovequeMax++] = a_Move; }

	virtual void onEnter();
	virtual void onExit();

	void setBattleControler(BattleControler *a_battleControler){ m_BattleControler = a_battleControler; }
	BattleControler *getBattleControler(){ return m_BattleControler; }

private:
	int maxMovePoint;
	int MoveQue[10]; // right: 1 left: 2  up : 3  down : 4
	int MovequeMax;
	int MovequeMIn;
	
	BattleControler *m_BattleControler;


};
#endif
