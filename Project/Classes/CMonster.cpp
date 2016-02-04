#include "CMonster.h"

CMonster::CMonster()
{

}
CMonster::CMonster(string a_name, string a_spriteRoot)
{
	setName(a_name);
	setSpriteRoot(a_spriteRoot);
	this->setSprite(Sprite::create(getSpriteRoot()));
	this->getSprite()->retain();

	moveAI[0] = Vec2(1, 0);
	moveAI[1] = Vec2(0, 1);
	moveAI[2] = Vec2(1, 0);
	moveAI[3] = Vec2(0, -1);
	moveAI[4] = Vec2(1, 0);
	moveAI[5] = Vec2(1, 0);
	moveAI[6] = Vec2(0, -1);
	moveAI[7] = Vec2(1, 0);
	moveAI[8] = Vec2(0, 1);
	moveAI[9] = Vec2(1, 0);
	
	moveHead = 0;
	dir = 0;
}
CMonster::~CMonster()
{

}
Vec2 CMonster::getMove()
{
	Vec2 rv;

	if (moveHead >= 10 || moveHead<0)
	{
		moveHead = 0;
	}

	switch (dir)
	{
	case 0:
		rv = Vec2(0, 0);
		break;
	case 1:
		rv = moveAI[moveHead];
		break;
	case 2:
		rv.x = -moveAI[moveHead].x;
		rv.y = -moveAI[moveHead].y;
		break;
	case 3:
		rv.x = moveAI[moveHead].y;
		rv.y = moveAI[moveHead].x;
		break;
	case 4:
		rv.x = -moveAI[moveHead].y;
		rv.y = -moveAI[moveHead].x;
		break;
	default:
		rv = Vec2(0, 0);
		break;
	}

	moveHead++;
	return rv;
}
