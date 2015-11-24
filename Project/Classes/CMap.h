#ifndef _CMAP_H_
#define _CMAP_H_

#include "cocos2d.h"
#include "CTile.h"

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

	void setStartPoint(Vec2 a_startPoint){ m_startPoint = a_startPoint; }
	Vec2 getStartPoint(){ return this->m_startPoint; }

	void addTile(Vec2 a_index,CTile* a_Tile);
	CTile* atTile(Vec2 a_index);

	void addPortal(string MapKey, int index,Vec2 point);
	CObject* getPortal(int index){ return this->portal[index]; }


private:
	CTile *m_tileTable[100][100]; 

	string m_szName; // ¸ÊÀÇ ÀÌ¸§

	string m_key;

	Vec2 m_startPoint;

	Vec2 m_SizeTile;

	CObject* portal[10];  // Æ÷Å»±¸Çö 
};
#endif
