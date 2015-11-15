#ifndef _BATTLEMENULAYER_H_
#define _BATTLEMENULAYER_H_
#include "cocos2d.h"
#include "BattleControler.h"
USING_NS_CC;

class BattleMenuLayer : public LayerColor// 전투메뉴를 끠워주는 레이어
{
public:
	virtual bool init();
	CREATE_FUNC(BattleMenuLayer);



	void setBattleControler(BattleControler* a_battleControler){ this->m_battleControler = a_battleControler; }
	BattleControler* getBattleControler(){ return this->m_battleControler; }

private:
	int SlowFlag;  // 빠른행동을 하면 1 
	int Choose;  // 

	BattleControler* m_battleControler;  // 배틀 컨트롤러 

	Label* moveLable;
	Label* InvenLable;
	Label* escLable;
	Label* actionLable;
	Label* attakLable;
	Label* endLable;
};

#endif