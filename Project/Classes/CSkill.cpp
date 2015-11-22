#include "CSkill.h"

CSkill::CSkill()
{

}
CSkill::CSkill(string a_name, int a_range, int a_diceType, int a_diceNum, int m_attribute, int m_accuracyRate)
{
	this->setName(a_name);
	this->setRange(a_range);
	this->setDiceType(a_diceType);
	this->setDiceNum(a_diceNum);
	this->setAttribute(m_attribute);
	this->setAccuracyRate(m_accuracyRate);

	for (int i = 0; i < 10; i++)
		this->setSplash(Vec2(0,0),i);
}