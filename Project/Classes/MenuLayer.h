#ifndef _MENULAYER_H_
#define _MENULAYER_H_

#include "cocos2d.h"
#include "InvenLayer.h"
#include "TurnControler.h"

USING_NS_CC;

using namespace std;

class MenuLayer : public cocos2d::LayerColor
{
public:
	virtual bool init(); // ���� 
	CREATE_FUNC(MenuLayer); 

	virtual void onEnter(); // ���� 
	virtual void onExit(); //�� �� 

	void Open(); // �޴��� ���� 
	void Close();//  ~~     �ݱ�

	void clickMenu(Object* pSender); // �޴� Ŭ���� �ҷ� �� �Լ� 

	void openInven(); // �κ� ���� 
	void openStatus(); // ������ ������ 
	void openSkill(); // ��ų â ���� 
	void openOption(); // �ɼ� â ���� 

	// set get ����
	void setInvenLayer(InvenLayer* a_invenLayer){ this->m_invenLayer = a_invenLayer; }
	InvenLayer* getInvenLayer(){ return this->m_invenLayer; }

	bool isOpenFlag(){ return m_OpenFlag; }
	void setOpenFlag(bool a_OpenFlag) { this->m_OpenFlag = a_OpenFlag; }

	void setTurnControler(TurnControler *a_turnControler){ m_turnControler = a_turnControler; }
	TurnControler *getTurnControler(){ return m_turnControler; }
	// set get ����

private:

	bool m_OpenFlag; // �Ŵ��� �������� �÷��� 
	Sprite* MenuPanel;  // �޴��� �̹���

	MenuItemFont* Inven; // �κ��丮 â �޴�������
	MenuItemFont* status; // �������ͽ� â �޴� ������ 
	MenuItemFont* skill; // ��ų â �޴� ������ 
	MenuItemFont* setUp; // ����â �޴� ������

	InvenLayer* m_invenLayer;  // �κ��丮 â ���̾�
	TurnControler * m_turnControler;  // ����Ʈ�ѷ� 




};


#endif //_FRAMELAYER_H_