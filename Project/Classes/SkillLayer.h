#ifndef _INVENLAYER_H_
#define _INVENLAYER_H_

#include "cocos2d.h"

USING_NS_CC;


using namespace std;

class InvenLayer : public cocos2d::LayerColor
{
public:
	virtual bool init();
	CREATE_FUNC(InvenLayer);

	bool isOpenFlag(){ return m_OpenFlag; }
	void setOpenFlag(bool a_OpenFlag) { this->m_OpenFlag = a_OpenFlag; }
	virtual void onEnter();
	virtual void onExit();

	void Open();
	void Close();



	InvenLayer();
	~InvenLayer();
private:
	Sprite* m_panel;
	bool m_OpenFlag;
};


#endif //_FRAMELAYER_H_