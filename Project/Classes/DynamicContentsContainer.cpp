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
	this->setCharacter(new CCharacter());
	this->setMap(NULL);
	this->setMonster(new CMonster*[10]);
	this->setObjectBattle(new CObject*[10]);
	this->setObjectField(new CObject*[10]);
	this->setSkill(new CSkill*[10]);

}
