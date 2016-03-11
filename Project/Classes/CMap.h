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
	CTile *m_tileTable[100][100];  // 타일의 구조 ? 

	string m_szName; // 맵의 이름

	string m_key; //  맵을 찾을 키 

	Vec2 m_SizeTile; //맵을  타일로 본 크기 

	CPortal* portal[10];  // 포탈구현 
};
#endif
