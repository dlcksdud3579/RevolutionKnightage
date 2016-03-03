#include "CPortal.h"

CPortal::CPortal()
{
	setPoint(Vec2(0, 0));
}
CPortal::CPortal(Vec2 a_Point)
{
	setPoint(a_Point);
}
CPortal::CPortal(string a_name, bool a_Moveable, int a_Type, CMap* a_linkedMap, Vec2* a_linkedPoint)
{
	setName(a_name);
	setMoveable(a_Moveable);
	setType(a_Type);
	setLinkedMap(m_linkedMap);
	setLinkedPoint(a_linkedPoint);
}