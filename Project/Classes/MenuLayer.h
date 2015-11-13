#ifndef _MENULAYER_H_
#define _MENULAYER_H_

#include "cocos2d.h"
#include "InvenLayer.h"

USING_NS_CC;

using namespace std;

class MenuLayer : public cocos2d::LayerColor
{
public:
	virtual bool init();
	CREATE_FUNC(MenuLayer);




	virtual void onEnter();
	virtual void onExit();

	void Open(); // �޴��� ���� 
	void Close();//  ~~     �ݱ�

	void clickMenu(Object* pSender);

	void openInven();
	void openStatus();
	void openSkill();
	void openOption();

	void setInvenLayer(InvenLayer* a_invenLayer){ this->m_invenLayer = a_invenLayer; }
	InvenLayer* getInvenLayer(){ return this->m_invenLayer; }

	bool isOpenFlag(){ return m_OpenFlag; }
	void setOpenFlag(bool a_OpenFlag) { this->m_OpenFlag = a_OpenFlag; }

private:

	bool m_OpenFlag;
	Sprite* MenuPanel;  // �޴��� �̹���

	MenuItemFont* Inven; // �κ��丮 â �޴�������
	MenuItemFont* status; // �������ͽ� â �޴� ������ 
	MenuItemFont* skill; // ��ų â �޴� ������ 
	MenuItemFont* setUp; // ����â �޴� ������

	InvenLayer* m_invenLayer;  // �κ��丮 â ���̾�


};


#endif //_FRAMELAYER_H_