#ifndef _BATTLEMENULAYER_H_
#define _BATTLEMENULAYER_H_
#include "cocos2d.h"
#include "BattleControler.h"
USING_NS_CC;

class BattleMenuLayer : public LayerColor// �����޴��� �ʿ��ִ� ���̾�
{
public:
	virtual bool init();
	CREATE_FUNC(BattleMenuLayer);



	void setBattleControler(BattleControler* a_battleControler){ this->m_battleControler = a_battleControler; }
	BattleControler* getBattleControler(){ return this->m_battleControler; }

private:
	int SlowFlag;  // �����ൿ�� �ϸ� 1 
	int Choose;  // 

	BattleControler* m_battleControler;  // ��Ʋ ��Ʈ�ѷ� 

	Label* moveLable;
	Label* InvenLable;
	Label* escLable;
	Label* actionLable;
	Label* attakLable;
	Label* endLable;
};

#endif