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

private:

};

#endif
