#include "CObject.h"

CObject::CObject()
{
	this->setPoint(Vec2(0, 0));
}
CObject::CObject(Vec2 a_Point)
{
	this->setPoint(a_Point);
}
CObject::CObject(string a_name, bool a_Moveable, int a_Type )
{
	m_name = a_name;
	m_Moveable = a_Moveable;
	m_Type = a_Type;
}