#ifndef _CMAPCONTROLER_H_
#define _CMAPCONTROLER_H_
#include "CMap.h"

class CMapControler
{
public:
	CMapControler(); // 맵 커트롤러 생성자
	CMapControler(CMap* a_Map); // 맵 커트롤러 생성자
	~CMapControler(); // 맵 커트롤러 소멸자
	
	void mapChange(int a_changeMapNum); // 맵  현재 변경 

	// 일단 set get 모음 
	void setMap(CMap* a_Map){ this->m_Map = a_Map; }
	CMap* getMap(){ return this->m_Map; }
	// ~일단 set get 모음  끝 
private:

	CMap *m_Map;  // 컨트롤 할맵 
};


#endif