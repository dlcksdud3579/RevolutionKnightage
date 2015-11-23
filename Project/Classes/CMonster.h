#ifndef _CMONSTER_H_
#define _CMONSTER_H_

#include "CObject.h"
#include "CStatus.h"
#include "CSkill.h"
#include "CCharacter.h"
using namespace std;

class CMonster :public CCharacter
{
public:
	CMonster();
	CMonster(std::string a_name,std::string a_spriteRoot);
	~CMonster();
	Vec2 getMove();

	void setDir(int dir){ this->dir = dir; }
	int getDir(){ return this->dir; }

private:
	Vec2 moveAI[10];
	int moveHead;
	int dir;  // 0-stop, 1-right, 2-left, 3-up, 4-down

};

#endif
