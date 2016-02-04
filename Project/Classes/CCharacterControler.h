#ifndef _CCHARATERCONTROLER_H_
#define _CCHARATERCONTROLER_H_
#include "CCharacter.h"

class CCharacterControler
{
public:
	CCharacterControler();
	CCharacterControler(CCharacter *a_Character);
	~CCharacterControler();

	bool moveUp(); // 위로이동 
	bool moveDown(); // 아래로 이동 
	bool moveLeft(); // 왼쪽으로 이동 
	bool moveRight(); // 오른쪽으로 이동 

	bool checkMoveable(Vec2 a_checkPoint); // 이동이 가능함을 체크 한다. 

	CCharacter* getCharacter(){ return m_Character; }   // 캐릭터 갯 

	


private:
	void setCharacter(CCharacter *a_Character){ this->m_Character = a_Character; }
	CCharacter *m_Character;
	
};


#endif