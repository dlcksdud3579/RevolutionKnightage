#ifndef _TURNControler__
#define _TURNControler__
#include "cocos2d.h"

USING_NS_CC;

class TurnControler
{
public:
	TurnControler(); // ������

	void CharacterTurnEnd(); //  ĳ���Ͱ�  �̵��� �����鼭 �ҷ��� �Լ��̴�. // ���Ϳ��� ���� �������� ä���� ����Ҽ� �ְ� �Ѵ�. 
	//set get 
	void setMenuPoint(Vec2 a_menuPoint){ this->m_menuPoint = a_menuPoint; }
	Vec2 getMenuPoint(){ return this->m_menuPoint; }

	void setTurnType(int a_turnType){ this->turnType = a_turnType; }
	int getTurnType(){ return this->turnType; }

	void setUsedActionPoint(float a_UsedActionPoint){ this->UsedActionPoint = a_UsedActionPoint; }
	float getUsedActionPoint(){ return this->UsedActionPoint; }

	void setMonActionPoint(int index, float point){ this->MonActionPoint[index] = point; }
	float getMonActionPoint(int index){ return MonActionPoint[index]; }
	//set get

private:
	Vec2 m_menuPoint;
	int turnType; //0 - �̵� 1 - �޴� 2 - ����  3 - ??  //�׼� ����Ʈ ? 
	float UsedActionPoint; // �÷��̾� �� ����� �׼� ����Ʈ 
	float MonActionPoint[10]; // ���Ͱ� ����� �׼� ����Ʈ 
		//�ൿ�� ����->�ൿ�� �´� �׼� ����Ʈ * ĳ���� �ӵ� - ap == ���� �ӵ� ?


};




#endif 