#include "DynamicContentsContainer.h"

bool DynamicContentsContainer::instanceFlag = false;
DynamicContentsContainer* DynamicContentsContainer::instance = NULL;

// 싱글턴 인스턴스를 반환할 멤버함수
DynamicContentsContainer* DynamicContentsContainer::getInstance(){
	if (!instance){
		instance = new DynamicContentsContainer();
		instanceFlag = true;
	}
	return instance;
}

DynamicContentsContainer::DynamicContentsContainer()
{
	for (int i = 0;  i < 10; i++)
	{
		this->setMonster(NULL, i);
		this->setObjectBattle(NULL, i);
		this->setObjectField(NULL, i);
		this->setSkill(NULL, i);
	}

	this->setDice(new CDice());
	this->setCharacter(new CCharacter());
	this->setMap(NULL);
}
