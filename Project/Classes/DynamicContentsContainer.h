#ifndef _DYNAMICCONTENTSCONTAINER_H_
#define _DYNAMICCONTENTSCONTAINER_H_

#include "CMap.h"
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
	
	CObject** getObjectField(){ return this->m_objectField; }
	void setObjectField(CObject** a_objectField){ this->m_objectField = a_objectField; }

	CObject** getObjectBattle(){ return this->m_objectBattle; }
	void setObjectBattle(CObject** a_objectBattle){ this->m_objectBattle = a_objectBattle; }
	
	CSkill** getSkill(){ return this->m_skill; }
	void setSkill(CSkill** a_skill){ this->m_skill = a_skill; }

	CMonster** getMonster(){ return this->m_monster; }
	void setMonster(CMonster** monster){ this->m_monster = monster; }


private:

	static DynamicContentsContainer* instance; // �̱��� �ν��Ͻ�

	static bool instanceFlag;  // �ν��Ͻ� �� �Ѱ���
	DynamicContentsContainer();

	CMap *m_map;  //���� ��
	CCharacter *m_character; // ĳ����, ��


	CObject **m_objectField; //  ��Ʈ �� ������Ʈ �迭 
	CObject **m_objectBattle; //  �ʵ� �� ������Ʈ �迭 

	CSkill **m_skill; // ��� ���� ��ų �迭 
	CMonster **m_monster;  // �ʵ��� ����  �迭

};



#endif // !_PLAYDATA_H_
