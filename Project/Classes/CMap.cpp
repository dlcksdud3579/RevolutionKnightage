#include "CMap.h"

CMap::CMap()
{
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			this->addTile(Vec2(j, i), NULL);
		}
	}

	for (int i = 0; i < 5; i++)
	{
		portal[i] = NULL;
	}
}

void CMap::addTile(Vec2 a_index, CTile* a_Tile)
{
	int y = (int)a_index.y;
	int x = (int)a_index.x;

	this->m_tileTable[y][x] = a_Tile;
}
CTile* CMap::atTile(Vec2 a_index)
{
	int x = (int)a_index.x; 
	int y = (int)a_index.y;

	return this->m_tileTable[y][x];
}
void CMap::addPortal(string MapKey, int index, Vec2 point)
{
	portal[index] = new CObject();
	portal[index]->setName(MapKey);
	portal[index]->setPoint(point);
}