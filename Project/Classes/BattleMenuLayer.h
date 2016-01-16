#ifndef _BATTLEMENULAYER_H_
#define _BATTLEMENULAYER_H_

#include "cocos2d.h"
#include "BattleControler.h"
USING_NS_CC;

using namespace std;

class BattleMenuLayer : public cocos2d::LayerColor
{
public:


	virtual bool init(); // 기본 틀 
	CREATE_FUNC(BattleMenuLayer); //  create함수 




	void printNomalMenu();//기본  행동 메뉴 
	void removeNomalMenu();// 기본 행동 메뉴제거 

	void printActionMenu();//액션  메뉴 
	void removeActionMenu(); // 액션 메뉴 제거 

	void printAttackMenu();  // 공격 메뉴 
	void removeAttackMenu(); // 공격 메뉴 제거 



	void chooseNomalMenu(Object* pSender); // 일반   //
	void chooseActionMenu(Object* pSender);// 액션 // 
	void chooseAttackMenu(Object* pSender); // 공격 //

	void removeMenu();

	// set get 모임 
	void setBattleControler(BattleControler *a_battleControler){ m_battleControler = a_battleControler; }
	BattleControler *getBattleControler(){ return m_battleControler; }
	// set get 모임 
private:
	
	bool menufalg = 0; // 0 - 안켜짐 , 1 - 노말, 2 - 액션, 3 - 공격

	BattleControler * m_battleControler;  // 배틀 컨트롤러 
};


#endif //_FRAMELAYER_H_