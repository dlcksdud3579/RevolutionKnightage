#ifndef _BATTLEMENULAYER_H_
#define _BATTLEMENULAYER_H_

#include "cocos2d.h"
#include "BattleControler.h"
USING_NS_CC;

using namespace std;

class BattleMenuLayer : public cocos2d::LayerColor
{
public:
	virtual bool init();
	CREATE_FUNC(BattleMenuLayer);



	void printRapidMenu();//���� �ൿ �޴� 
	void removeRapidMenu();

	void printNomalMenu();//�⺻  �ൿ �޴� 
	void removeNomalMenu();

	void printActionMenu();//���� �ൿ �޴� 
	void removeActionMenu();

	void chooseRapidMenu(Object* pSender); //���� �ൿ �޴� ���ý� 
	void chooseNomalMenu(Object* pSender); // ����  //
	void chooseActionMenu(Object* pSender);// �׼� // 

	void setBattleControler(BattleControler *a_battleControler){ m_battleControler = a_battleControler; }
	BattleControler *getBattleControler(){ return m_battleControler; }

private:
	BattleControler * m_battleControler;  // ��Ʋ ��Ʈ�ѷ� 
};


#endif //_FRAMELAYER_H_