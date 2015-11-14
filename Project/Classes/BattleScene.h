#ifndef _BATTLESCENE_H_
#define _BATTLESCENE_H_
#include "cocos2d.h"
#include "BattleLayer.h"
#include "BattleControler.h"
USING_NS_CC;

class BattleScene : public LayerColor
{
public:

	static cocos2d::Scene * createScene();  // �� ũ������Ʈ 
	virtual bool init();

	virtual void onEnter();
	virtual void onExit();

	virtual bool onTouchBegan(Touch* touch, Event* event);
	virtual void onTouchMoved(Touch* touch, Event* event);
	virtual void onTouchEnded(Touch* touch, Event* event);

	void CharacterTurn();
	void endCharacterTurn();
	void run(float delta);
	void rapidAction(); // ���� �ൿ 
	void nomalAction(); // �븻 �ൿ

	CREATE_FUNC(BattleScene);
	


private:

	BattleLayer* m_battleLayer;  // ��Ʋ �� ���̾� ( Ÿ��, ����, ĳ���͸� ���)
	BattleControler * m_battleControler;  // ��Ʋ ��Ʈ�ѷ� 
};



#endif