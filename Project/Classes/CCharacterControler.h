#ifndef _CCHARATERCONTROLER_H_
#define _CCHARATERCONTROLER_H_
#include "CCharacter.h"

class CCharacterControler
{
public:
	CCharacterControler();
	CCharacterControler(CCharacter *a_Character);
	~CCharacterControler();

	bool moveUp(); // �����̵� 
	bool moveDown(); // �Ʒ��� �̵� 
	bool moveLeft(); // �������� �̵� 
	bool moveRight(); // ���������� �̵� 

	bool checkMoveable(Vec2 a_checkPoint); // �̵��� �������� üũ �Ѵ�. 

	CCharacter* getCharacter(){ return m_Character; }   // ĳ���� �� 

	


private:
	void setCharacter(CCharacter *a_Character){ this->m_Character = a_Character; }
	CCharacter *m_Character;
	
};


#endif