#ifndef _TURNControler__
#define _TURNControler__
#include "cocos2d.h"

USING_NS_CC;

class TurnControler
{
public:
	TurnControler(); // 생성자

	void CharacterTurnEnd(); //  캐릭터가  이동이 끝나면서 불려질 함수이다. // 몬스터에게 각각 게이지를 채워서 사용할수 있게 한다. 
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
	int turnType; //0 - 이동 1 - 메뉴 2 - 어택  3 - ??  //액션 포인트 ? 
	float UsedActionPoint; // 플레이어 가 사용한 액션 포인트 
	float MonActionPoint[10]; // 몬스터가 사용할 액션 포인트 
		//행동을 선택->행동에 맞는 액션 포인트 * 캐릭터 속도 - ap == 여분 속도 ?


};




#endif 