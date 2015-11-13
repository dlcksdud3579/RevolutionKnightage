#ifndef _CMAPCONTROLER_H_
#define _CMAPCONTROLER_H_
#include "CMap.h"

class CMapControler
{
public:
	CMapControler();
	CMapControler(CMap* a_Map);
	~CMapControler();
	
	void setMap(CMap* a_Map){ this->m_Map = a_Map; }
	CMap* getMap(){ return this->m_Map; }

	void mapChange(int a_changeMapNum);

private:

	CMap *m_Map;
};


#endif