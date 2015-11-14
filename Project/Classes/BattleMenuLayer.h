#ifndef _BATTLEMENULAYER_H_
#define _BATTLEMENULAYER_H_
#include "cocos2d.h"

USING_NS_CC;

class BattleMenuLayer // �����޴��� �ʿ��ִ� ���̾�
{
public:
	virtual bool init();
	CREATE_FUNC(BattleMenuLayer);

	void printRapidMenu();
	void printNomalMenu();

	void chooseRapidMenu(Object* pSender);
	void chooseNomalMenu(Object* pSender);

private:

};

#endif