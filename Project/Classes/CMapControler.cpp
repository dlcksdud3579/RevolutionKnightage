#include "CMapControler.h"
#include "DynamicContentsContainer.h"
#include "StaticContentsContainer.h"

CMapControler::CMapControler()
{
	setMap(DynamicContentsContainer::getInstance()->getMap());
}
CMapControler::CMapControler(CMap* a_Map)
{
	
	this->setMap(a_Map);
}
CMapControler::~CMapControler()
{

}

void CMapControler::mapChange(int a_changeMapNum)
{
	string index;
	index = to_string(a_changeMapNum);
	
	CMap* changeMap = StaticContentsContainer::getMapMap()->find(index)->second;

	DynamicContentsContainer::getInstance()->setMap(changeMap);
}