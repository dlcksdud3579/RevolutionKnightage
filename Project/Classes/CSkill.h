#ifndef _CSKILL_H_
#define _CSKILL_H_
#include "cocos2d.h"

using namespace std;
USING_NS_CC;

class CSkill
{
public:
	CSkill();

	CSkill(string a_name,int a_range,int a_diceType, int a_diceNum, int m_attribute,int m_accuracyRate);


	void setName(std::string a_name){ this->m_name = a_name; }
	std::string getName(){ return this->m_name; }

	void setRange(int a_range){ this->m_range = a_range; }
	int getRange(){ return this->m_range; }

	void setSplash(Vec2 a_splash, int index){ this->m_splash[index] = a_splash; }
	Vec2 getSplash(int index){ return this->m_splash[index]; }

	void setDiceType(int a_diceType){ this->m_diceType = a_diceType; }
	int getDiceType(){ return this->m_diceType; }

	void setDiceNum(int a_diceNum){ this->m_diceNum = a_diceNum; }
	int getDiceNum(){ return this->m_diceNum; }

	void setAttribute(int a_attribute){ this->m_attribute = a_attribute; }
	int getAttribute(){ return this->m_attribute; }

	void setAccuracyRate(int a_accuracyRate){ this->m_accuracyRate = a_accuracyRate; }
	int getAccuracyRate(){ return this->m_accuracyRate; }

private:
	std::string m_name; //이름
	int m_range;		//번위
	Vec2 m_splash[10];  // 스를레쉬
	int m_diceType;     // 주사위 종류 
	int m_diceNum;      // 주사위 숫자 
	int m_attribute;    // 속성
	int m_accuracyRate; // 명줄률
	
};

#endif