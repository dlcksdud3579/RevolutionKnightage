#ifndef _CMAPCONTROLER_H_
#define _CMAPCONTROLER_H_
#include "CMap.h"

class CMapControler
{
public:
	CMapControler(); // �� ĿƮ�ѷ� ������
	CMapControler(CMap* a_Map); // �� ĿƮ�ѷ� ������
	~CMapControler(); // �� ĿƮ�ѷ� �Ҹ���
	
	void mapChange(int a_changeMapNum); // ��  ���� ���� 

	// �ϴ� set get ���� 
	void setMap(CMap* a_Map){ this->m_Map = a_Map; }
	CMap* getMap(){ return this->m_Map; }
	// ~�ϴ� set get ����  �� 
private:

	CMap *m_Map;  // ��Ʈ�� �Ҹ� 
};


#endif