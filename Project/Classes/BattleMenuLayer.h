#ifndef _BATTLEMENULAYER_H_
#define _BATTLEMENULAYER_H_

#include "cocos2d.h"
#include "BattleControler.h"
USING_NS_CC;

using namespace std;

class BattleMenuLayer : public cocos2d::LayerColor
{
public:


	virtual bool init(); // �⺻ Ʋ 
	CREATE_FUNC(BattleMenuLayer); //  create�Լ� 




	void printNomalMenu();//�⺻  �ൿ �޴� 
	void removeNomalMenu();// �⺻ �ൿ �޴����� 

	void printActionMenu();//�׼�  �޴� 
	void removeActionMenu(); // �׼� �޴� ���� 

	void printAttackMenu();  // ���� �޴� 
	void removeAttackMenu(); // ���� �޴� ���� 



	void chooseNomalMenu(Object* pSender); // �Ϲ�   //
	void chooseActionMenu(Object* pSender);// �׼� // 
	void chooseAttackMenu(Object* pSender); // ���� //

	void removeMenu();

	// set get ���� 
	void setBattleControler(BattleControler *a_battleControler){ m_battleControler = a_battleControler; }
	BattleControler *getBattleControler(){ return m_battleControler; }
	// set get ���� 
private:
	
	bool menufalg = 0; // 0 - ������ , 1 - �븻, 2 - �׼�, 3 - ����

	BattleControler * m_battleControler;  // ��Ʋ ��Ʈ�ѷ� 
};


#endif //_FRAMELAYER_H_