#ifndef _BATTLESCENE_H_
#define _BATTLESCENE_H_
#include "cocos2d.h"
#include "BattleLayer.h"
#include "BattleControler.h"

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


	void setBattleLayer(BattleLayer *a_BattleLayer){ m_battleLayer = a_BattleLayer; }
	BattleLayer *getBattleLayer(){ return m_battleLayer; }


	void setBattleControler(BattleControler *m_battleControler){ m_battleControler = m_battleControler; }
	BattleControler *getBattleControler(){ return m_battleControler; }

	void printRapidMenu();
	void removeRapidMenu();

	void printNomalMenu();
	void removeNomalMenu();

	void printActionMenu();
	void removeActionMenu();

	void chooseRapidMenu(Object* pSender);
	void chooseNomalMenu(Object* pSender);
	void chooseActionMenu(Object* pSender);




private:



	BattleLayer* m_battleLayer;  // 배틀 맵 레이어 ( 타일, 몬스터, 캐릭터를 출력)
	BattleControler * m_battleControler;  // 배틀 컨트롤러 
};



#endif