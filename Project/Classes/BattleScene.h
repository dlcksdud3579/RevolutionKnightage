
#ifndef _BATTLESCENE_H_
#define _BATTLESCENE_H_

#include "cocos2d.h"
#include "BattleLayer.h"
#include "BattleMenuLayer.h"
#include "BattleControler.h"
#include "InvenLayer.h"

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

	void openInven(); // ���� ���� 


	void setInvenLayer(InvenLayer* a_invenLayer){ this->m_invenLayer = a_invenLayer; }
	InvenLayer* getInvenLayer(){ return this->m_invenLayer; }

	void setBattleLayer(BattleLayer *a_BattleLayer){ m_battleLayer = a_BattleLayer; }
	BattleLayer *getBattleLayer(){ return m_battleLayer; }


	void setBattleControler(BattleControler *a_battleControler){ m_battleControler = a_battleControler; }
	BattleControler *getBattleControler(){ return m_battleControler; }

	void setBattlePoint(Vec2 a_BattlePoint){ this->m_battlePoint = a_BattlePoint; }
	Vec2 getBattlepoint(){ return this->m_battlePoint; }

	void setBattleMenuLayer(BattleMenuLayer *a_battleMenuLayer){ this->m_battleMenuLayer = a_battleMenuLayer; }
	BattleMenuLayer* getBattleMenuLayer(){ return m_battleMenuLayer; }
	
	void movedMenu(float delta);

	void checkdie();

	void dieCharacter();


private:
	InvenLayer* m_invenLayer; // �κ��丮 â �޴�������
	BattleLayer* m_battleLayer;  // ��Ʋ �� ���̾� ( Ÿ��, ����, ĳ���͸� ���)
	BattleControler * m_battleControler;  // ��Ʋ ��Ʈ�ѷ� 
	BattleMenuLayer *m_battleMenuLayer;
	Vec2 m_battlePoint;
};



#endif