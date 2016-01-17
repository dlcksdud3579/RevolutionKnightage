
#ifndef _NFIELDSCENE_H_
#define _NFIELDSCENE_H_

#include "cocos2d.h"
#include "FieldLayer.h"
#include "FrameLayer.h"
#include "MenuLayer.h"
#include "BattleMenuLayer.h"
#include "TurnControler.h"


USING_NS_CC;

class NFieldScene : public LayerColor
{
public:

	static cocos2d::Scene * createScene();  // 씬 크리에이트  
	CREATE_FUNC(NFieldScene); // 크레이트 함수에서 사용 


	virtual bool init(); //  씬의 메인 함수 

	virtual void onEnter(); // 씬이 시작 할때 불려 지는 함수 
	virtual void onExit();  // 씬이 마칠 때 불려지는 함수 

	virtual bool onTouchBegan(Touch* touch, Event* event); //터치 시작 할때 함수 
	virtual void onTouchMoved(Touch* touch, Event* event); // 터치 무브 할때 함수 
	virtual void onTouchEnded(Touch* touch, Event* event); // 터치 끝날때 불려 지는 함수 

	
	 // set get 함수 모음 
	void setFieldLayer(FieldLayer* a_fieldLayer){ this->m_fieldLayer = a_fieldLayer; }
	FieldLayer* getFieldLayer(){ return this->m_fieldLayer; }

	void setMenuLayer(MenuLayer* a_MenuLayer){ this->m_menuLayer = a_MenuLayer; }
	MenuLayer* getMenuLayer(){ return this->m_menuLayer; }

	void setFrameLayer(FrameLayer* a_frameLayer){ this->m_frameLayer = a_frameLayer; }
	FrameLayer* getFrameLayer(){ return this->m_frameLayer; }

	void setBattleMenuLayer(BattleMenuLayer *a_battleMenuLayer){ this->m_battleMenuLayer = a_battleMenuLayer; }
	BattleMenuLayer* getBattleMenuLayer(){ return m_battleMenuLayer; }

	void setTurnControler(TurnControler *a_turnControler){ this->m_turnControler = a_turnControler; }
	TurnControler* getTurnControler(){ return this->m_turnControler; }

	// ~~ set get 함수 모음여기까지  

private:

	FieldLayer* m_fieldLayer;  // 필드를 띄워줄 함수  가장 아래 
	FrameLayer* m_frameLayer; // 화면을 약간 가려줄 프레임을 가진 레이어 가장 위에 뛰울 것 
	MenuLayer* m_menuLayer; // 메뉴 를 뛰워줄 함수 프레임 함수 보다 위로 
    BattleMenuLayer *m_battleMenuLayer; // 캐릭터 행동 메뉴를 뛰워줄 함수 일단 잴 위?
	TurnControler* m_turnControler; //턴을 관리 해줄 우리의 턴 컨트롤러 


};
#endif