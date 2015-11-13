#ifndef _MENULAYER_H_
#define _MENULAYER_H_

#include "cocos2d.h"
#include "InvenLayer.h"

USING_NS_CC;

using namespace std;

class MenuLayer : public cocos2d::LayerColor
{
public:
	virtual bool init();
	CREATE_FUNC(MenuLayer);




	virtual void onEnter();
	virtual void onExit();

	void Open(); // 메뉴판 열기 
	void Close();//  ~~     닫기

	void clickMenu(Object* pSender);

	void openInven();
	void openStatus();
	void openSkill();
	void openOption();

	void setInvenLayer(InvenLayer* a_invenLayer){ this->m_invenLayer = a_invenLayer; }
	InvenLayer* getInvenLayer(){ return this->m_invenLayer; }

	bool isOpenFlag(){ return m_OpenFlag; }
	void setOpenFlag(bool a_OpenFlag) { this->m_OpenFlag = a_OpenFlag; }

private:

	bool m_OpenFlag;
	Sprite* MenuPanel;  // 메뉴판 이미지

	MenuItemFont* Inven; // 인벤토리 창 메뉴아이템
	MenuItemFont* status; // 스테이터스 창 메뉴 아이템 
	MenuItemFont* skill; // 스킬 창 메뉴 아이템 
	MenuItemFont* setUp; // 설정창 메뉴 아이템

	InvenLayer* m_invenLayer;  // 인벤토리 창 레이어


};


#endif //_FRAMELAYER_H_