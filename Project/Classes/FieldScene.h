#ifndef _TESTSCENE_H_
#define _TESTSCENE_H_

#include "cocos2d.h"
#include "FieldLayer.h"
#include "FrameLayer.h"
#include "MenuLayer.h"
#include "InvenLayer.h"


class FieldScene : public cocos2d::LayerColor
{
public:
	static cocos2d::Scene * createScene();  // 씬 크리에이트 

	virtual bool init();
	
	void setFieldLayer(FieldLayer* a_fieldLayer){this->m_fieldLayer = a_fieldLayer;}
	FieldLayer* getFieldLayer(){ return this->m_fieldLayer; }

	void setMenuLayer(MenuLayer* a_MenuLayer){ this->m_menuLayer = a_MenuLayer; }
	MenuLayer* getMenuLayer(){ return this->m_menuLayer; }

	void setFrameLayer(FrameLayer* a_frameLayer){ this->m_frameLayer = a_frameLayer; }
	FrameLayer* getFrameLayer(){ return this->m_frameLayer; }


	virtual void onEnter();
	virtual void onExit();

	virtual bool onTouchBegan(Touch* touch, Event* event);
	virtual void onTouchMoved(Touch* touch, Event* event);
	virtual void onTouchEnded(Touch* touch, Event* event);



	CREATE_FUNC(FieldScene);

private:
	FieldLayer* m_fieldLayer;
	FrameLayer* m_frameLayer;
	MenuLayer* m_menuLayer;
	
};


#endif //_TESTSCENE_H_