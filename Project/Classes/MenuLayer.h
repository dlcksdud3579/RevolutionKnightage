#ifndef _MENULAYER_H_
#define _MENULAYER_H_

#include "cocos2d.h"
#include "InvenLayer.h"
#include "TurnControler.h"

USING_NS_CC;

using namespace std;

class MenuLayer : public cocos2d::LayerColor
{
public:
	virtual bool init(); // 메인 
	CREATE_FUNC(MenuLayer); 

	virtual void onEnter(); // 시작 
	virtual void onExit(); //과 끝 

	void Open(); // 메뉴판 열기 
	void Close();//  ~~     닫기

	void clickMenu(Object* pSender); // 메뉴 클릭시 불려 질 함수 

	void openInven(); // 인벤 열기 
	void openStatus(); // 스텟차 ㅇ열기 
	void openSkill(); // 스킬 창 열기 
	void openOption(); // 옵션 창 열기 

	// set get 모음
	void setInvenLayer(InvenLayer* a_invenLayer){ this->m_invenLayer = a_invenLayer; }
	InvenLayer* getInvenLayer(){ return this->m_invenLayer; }

	bool isOpenFlag(){ return m_OpenFlag; }
	void setOpenFlag(bool a_OpenFlag) { this->m_OpenFlag = a_OpenFlag; }

	void setTurnControler(TurnControler *a_turnControler){ m_turnControler = a_turnControler; }
	TurnControler *getTurnControler(){ return m_turnControler; }
	// set get 모음

private:

	bool m_OpenFlag; // 매뉴가 열린건지 플레그 
	Sprite* MenuPanel;  // 메뉴판 이미지

	MenuItemFont* Inven; // 인벤토리 창 메뉴아이템
	MenuItemFont* status; // 스테이터스 창 메뉴 아이템 
	MenuItemFont* skill; // 스킬 창 메뉴 아이템 
	MenuItemFont* setUp; // 설정창 메뉴 아이템

	InvenLayer* m_invenLayer;  // 인벤토리 창 레이어
	TurnControler * m_turnControler;  // 턴컨트롤러 




};


#endif //_FRAMELAYER_H_