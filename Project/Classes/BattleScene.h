#ifndef _BATTLESCENE_H_
#define _BATTLESCENE_H_
#include "cocos2d.h"
#include "BattleLayer.h"
#include "BattleControler.h"
#include "InvenLayer.h"

USING_NS_CC;


class BattleScene : public LayerColor
{
public:

	static cocos2d::Scene * createScene();  // 씬 크리에이트 
	

	virtual bool init();

	virtual void onEnter();
	virtual void onExit();

	virtual bool onTouchBegan(Touch* touch, Event* event);
	virtual void onTouchMoved(Touch* touch, Event* event);
	virtual void onTouchEnded(Touch* touch, Event* event);

	void CharacterTurn();
	void endCharacterTurn();
	void run(float delta);

	void rapidAction(); // 빠른 행동 
	void nomalAction(); // 노말 행동

	CREATE_FUNC(BattleScene);




	void printRapidMenu();//빠른 행동 메뉴 
	void removeRapidMenu();

	void printNomalMenu();//기본  행동 메뉴 
	void removeNomalMenu();

	void printActionMenu();//빠른 행동 메뉴 
	void removeActionMenu(); 

	void chooseRapidMenu(Object* pSender); //빠른 행동 메뉴 선택시 
	void chooseNomalMenu(Object* pSender); // 느린  //
	void chooseActionMenu(Object* pSender);// 액션 // 

	void openInven(); // 가방 열기 


	void setInvenLayer(InvenLayer* a_invenLayer){ this->m_invenLayer = a_invenLayer; }
	InvenLayer* getInvenLayer(){ return this->m_invenLayer; }

	void setBattleLayer(BattleLayer *a_BattleLayer){ m_battleLayer = a_BattleLayer; }
	BattleLayer *getBattleLayer(){ return m_battleLayer; }


	void setBattleControler(BattleControler *m_battleControler){ m_battleControler = m_battleControler; }
	BattleControler *getBattleControler(){ return m_battleControler; }



	
	void setBattlePoint(Vec2 a_BattlePoint){ this->m_battlePoint = a_BattlePoint; }
	Vec2 getBattlepoint(){ return this->m_battlePoint; }

private:
	InvenLayer* m_invenLayer; // 인벤토리 창 메뉴아이템
	BattleLayer* m_battleLayer;  // 배틀 맵 레이어 ( 타일, 몬스터, 캐릭터를 출력)
	BattleControler * m_battleControler;  // 배틀 컨트롤러 
	Vec2 m_battlePoint;
};



#endif