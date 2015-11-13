#ifndef _BATTLESCENE_H_
#define _BATTLESCENE_H_
#include "cocos2d.h"
#include "BattleLayer.h"
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



	CREATE_FUNC(BattleScene);

private:
	BattleLayer* m_fieldLayer;

};



#endif