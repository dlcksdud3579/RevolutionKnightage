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



	BattleLayer* m_battleLayer;  // ��Ʋ �� ���̾� ( Ÿ��, ����, ĳ���͸� ���)
	BattleControler * m_battleControler;  // ��Ʋ ��Ʈ�ѷ� 
};



#endif