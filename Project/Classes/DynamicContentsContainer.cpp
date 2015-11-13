#include "DynamicContentsContainer.h"

bool DynamicContentsContainer::instanceFlag = false;
DynamicContentsContainer* DynamicContentsContainer::instance = NULL;

// �̱��� �ν��Ͻ��� ��ȯ�� ����Լ�
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
