
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

	static cocos2d::Scene * createScene();  // �� ũ������Ʈ  
	CREATE_FUNC(NFieldScene); // ũ����Ʈ �Լ����� ��� 


	virtual bool init(); //  ���� ���� �Լ� 

	virtual void onEnter(); // ���� ���� �Ҷ� �ҷ� ���� �Լ� 
	virtual void onExit();  // ���� ��ĥ �� �ҷ����� �Լ� 

	virtual bool onTouchBegan(Touch* touch, Event* event); //��ġ ���� �Ҷ� �Լ� 
	virtual void onTouchMoved(Touch* touch, Event* event); // ��ġ ���� �Ҷ� �Լ� 
	virtual void onTouchEnded(Touch* touch, Event* event); // ��ġ ������ �ҷ� ���� �Լ� 

	
	 // set get �Լ� ���� 
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

	// ~~ set get �Լ� �����������  

private:

	FieldLayer* m_fieldLayer;  // �ʵ带 ����� �Լ�  ���� �Ʒ� 
	FrameLayer* m_frameLayer; // ȭ���� �ణ ������ �������� ���� ���̾� ���� ���� �ٿ� �� 
	MenuLayer* m_menuLayer; // �޴� �� �ٿ��� �Լ� ������ �Լ� ���� ���� 
    BattleMenuLayer *m_battleMenuLayer; // ĳ���� �ൿ �޴��� �ٿ��� �Լ� �ϴ� �� ��?
	TurnControler* m_turnControler; //���� ���� ���� �츮�� �� ��Ʈ�ѷ� 


};
#endif