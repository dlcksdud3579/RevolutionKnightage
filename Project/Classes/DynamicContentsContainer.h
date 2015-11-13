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

	static DynamicContentsContainer* instance; // 싱글턴 인스턴스

	static bool instanceFlag;  // 인스턴스 는 한개만
	DynamicContentsContainer();

	CMap *m_map;  //현재 맵
	CCharacter *m_character; // 캐릭터, 나


	CObject **m_objectField; //  필트 위 오브젝트 배열 
	CObject **m_objectBattle; //  필드 위 오브젝트 배열 

	CSkill **m_skill; // 사용 가능 스킬 배열 
	CMonster **m_monster;  // 필드위 몬스터  배열

};



#endif // !_PLAYDATA_H_
