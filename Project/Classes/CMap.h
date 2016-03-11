#ifndef _CMAP_H_
#define _CMAP_H_

#include "cocos2d.h"
#include "CTile.h"
#include "CPortal.h"

using namespace std;
class CMap
{
public:
	CMap();


	void setName(string a_szName){ this->m_szName = a_szName; }
	string getName(){ return this->m_szName; }

	void setKey(string a_key){ this->m_key = a_key; }
	string getKey(){ return this->m_key; }

	void setSizeTile(Vec2 a_SizeTile){ m_SizeTile = a_SizeTile; }
	Vec2 getSizeTile(){ return this->m_SizeTile; }

	void addTile(Vec2 a_index,CTile* a_Tile);
	CTile* atTile(Vec2 a_index);

	void addPortal(int index, Vec2 Point, string name, string LinkedMapKey, Vec2 Linkedpoint);

	CPortal* getPortal(int index){ return this->portal[index]; }


private:
	CTile *m_tileTable[100][100];  // Ÿ���� ���� ? 

	string m_szName; // ���� �̸�

	string m_key; //  ���� ã�� Ű 

	Vec2 m_SizeTile; //����  Ÿ�Ϸ� �� ũ�� 

	CPortal* portal[10];  // ��Ż���� 
};
#endif
