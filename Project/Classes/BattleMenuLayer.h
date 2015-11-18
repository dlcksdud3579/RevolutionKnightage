#ifndef _BATTLEMENULAYER_H_
#define _BATTLEMENULAYER_H_

#include "cocos2d.h"
#include "BattleControler.h"
USING_NS_CC;

using namespace std;

class BattleMenuLayer : public cocos2d::LayerColor
{
public:
	virtual bool init();
	CREATE_FUNC(BattleMenuLayer);



	void printRapidMenu();//빠른 행동 메뉴 
	void removeRapidMenu();

	void printNomalMenu();//기본  행동 메뉴 
	void removeNomalMenu();

	void printActionMenu();//빠른 행동 메뉴 
	void removeActionMenu();

	void chooseRapidMenu(Object* pSender); //빠른 행동 메뉴 선택시 
	void chooseNomalMenu(Object* pSender); // 느린  //
	void chooseActionMenu(Object* pSender);// 액션 // 

	void setBattleControler(BattleControler *a_battleControler){ m_battleControler = a_battleControler; }
	BattleControler *getBattleControler(){ return m_battleControler; }

private:
	BattleControler * m_battleControler;  // 배틀 컨트롤러 
};


#endif //_FRAMELAYER_H_