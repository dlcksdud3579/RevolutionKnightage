#include "CDice.h"
#include "stdlib.h"
#include "time.h"

CDice::CDice()
{
	setNumber(10);
	setType(10);
}
CDice::CDice(int a_number, int a_type)
{
	setNumber(a_number);
	setType(a_type);
}
int CDice::rollDice()
{
	int value;
	srand(time(NULL));
	value = rand() % (getType() + 1);
	this->setNumber(getNumber() - 1);
	return value;
}


int  CDice::rollDice(int type)
{
	int value;
	srand(time(NULL));
	value = rand() % (type + 1);
	this->setNumber(getNumber() - 1);
	return value;
}