#include "CStatus.h"
Status::Status()
{

}
Status::~Status()
{

}
Status::Status(int hp, int spd, int def, int str, int dex, int ins, int kno)
{
	setHp(hp);
	setSpeed(spd);
	setDef(def);
	setStr(str);
	setDex(dex);
	setIns(ins);
	setKno(kno);
}