#ifndef _BATTLEMENULAYER_H_
#define _BATTLEMENULAYER_H_

#include "cocos2d.h"
#include "TurnControler.h"
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
	void setTurnControler(TurnControler *a_turnControler){ m_turnControler = a_turnControler; }
	TurnControler *getTurnControler(){ return m_turnControler; }
	// set get ���� 
private:
	
	bool menufalg = 0; // 0 - ������ , 1 - �븻, 2 - �׼�, 3 - ����

	TurnControler * m_turnControler;  // ����Ʈ�ѷ� 
};


#endif //_FRAMELAYER_H_