#ifndef _MENULAYER_H_
#define _MENULAYER_H_

#include "cocos2d.h"
#include "InvenLayer.h"
#include "SkillLayer.h"
#include "SetUpLayer.h"
#include "StatusLayer.h"
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

	void setSkillLayer(SkillLayer* a_skillLayer){ this->m_skillLayer = a_skillLayer; }
	SkillLayer* getSkillLayer(){ return this->m_skillLayer; }

	void setSetupLayer(SetUpLayer* a_setupLayer){ this->m_setupLayer = a_setupLayer; }
	SetUpLayer* getSetupLayer(){ return this->m_setupLayer; }

	void setStatusLayer(StatusLayer* a_statusLayer){ this->m_statusLayer = a_statusLayer; }
	StatusLayer* getStatusLayer(){ return this->m_statusLayer; }

	bool isOpenFlag(){ return m_OpenFlag; }
	void setOpenFlag(bool a_OpenFlag) { this->m_OpenFlag = a_OpenFlag; }

	void setTurnControler(TurnControler *a_turnControler){ m_turnControler = a_turnControler; }
	TurnControler *getTurnControler(){ return m_turnControler; }
	// set get ����

private:

	bool m_OpenFlag; // �Ŵ��� �������� �÷��� 
	Sprite* MenuPanel;  // �޴��� �̹���
	Menu* pMenu; // �޴����� ���� 

	MenuItemFont* Inven; // �κ��丮 â �޴�������
	MenuItemFont* status; // �������ͽ� â �޴� ������ 
	MenuItemFont* skill; // ��ų â �޴� ������ 
	MenuItemFont* setUp; // ����â �޴� ������

	InvenLayer* m_invenLayer;  // �κ��丮 â ���̾�
	SkillLayer* m_skillLayer;  // ��ų â ���̾�
	SetUpLayer* m_setupLayer;  // ���� â ���̾�
	StatusLayer* m_statusLayer;  // �������ͽ� â ���̾�


	TurnControler * m_turnControler;  // ����Ʈ�ѷ� 




};


#endif //_FRAMELAYER_H_