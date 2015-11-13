#ifndef _DYNAMICCONTENTSCONTAINER_H_
#define _DYNAMICCONTENTSCONTAINER_H_

#include "CMap.h"
#include "CDice.h"
#include "CCharacter.h"
#include "CObject.h"
#include "CSkill.h"
#include "CMonster.h"


class DynamicContentsContainer
{
public:
	
	static DynamicContentsContainer* getInstance();
	~DynamicContentsContainer()
	{
		instanceFlag = false;
	};

	
	CMap* getMap(){return this->m_map; }
	void setMap(CMap* a_map){ this->m_map = a_map; }
	
	CCharacter* getCharacter(){ return this->m_character; }
	void setCharacter(CCharacter* a_character){ this->m_character = a_character; }
	
	CObject* getObjectField(int index){ return this->m_objectField[index]; }
	void setObjectField(CObject* a_objectField, int index){ this->m_objectField[index] = a_objectField; }

	CObject* getObjectBattle(int index){ return this->m_objectBattle[index]; }
	void setObjectBattle(CObject* a_objectBattle, int index){ this->m_objectBattle[index] = a_objectBattle; }
	
	CSkill* getSkill(int index){ return this->m_skill[index]; }
	void setSkill(CSkill* a_skill, int index){this->m_skill[index] = a_skill;}

	CMonster* getMonster(int index){ return this->m_monster[index]; }
	void setMonster(CMonster* monster,int index){ this->m_monster[index] = monster; }

	CDice* getDice(){ return this->m_dice; }
	void setDice(CDice* a_dice){ this->m_dice = a_dice; }

private:

	static DynamicContentsContainer* instance; // �̱��� �ν��Ͻ�

	static bool instanceFlag;  // �ν��Ͻ� �� �Ѱ���
	DynamicContentsContainer();

	CMap *m_map;  //���� ��
	CCharacter *m_character; // ĳ����, ��

	CDice* m_dice;

	CObject *m_objectField[10]; //  ��Ʈ �� ������Ʈ �迭 
	CObject *m_objectBattle[10]; //  �ʵ� �� ������Ʈ �迭 

	CSkill *m_skill[10]; // ��� ���� ��ų �迭 
	CMonster *m_monster[10];  // �ʵ��� ����  �迭

};



#endif // !_PLAYDATA_H_
