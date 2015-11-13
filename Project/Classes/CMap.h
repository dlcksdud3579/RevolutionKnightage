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

	void setSizeTile(Vec2 a_SizeTile){ m_SizeTile = a_SizeTile; }
	Vec2 getSizeTile(){ return this->m_SizeTile; }

	void setStartPoint(Vec2 a_startPoint){ m_startPoint = a_startPoint; }
	Vec2 getStartPoint(){ return this->m_startPoint; }

	void addTile(Vec2 a_index,CTile* a_Tile);
	CTile* atTile(Vec2 a_index);

private:
	CTile *m_tileTable[100][100]; 

	string m_szName; // ∏ ¿« ¿Ã∏ß
	Vec2 m_startPoint;

	Vec2 m_SizeTile;

};
#endif
