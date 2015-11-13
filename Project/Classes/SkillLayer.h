#ifndef _SKILLAYER_H_
#define _SKILLAYER_H_

#include "cocos2d.h"

USING_NS_CC;


using namespace std;

class SkillLayer : public cocos2d::LayerColor
{
public:
	virtual bool init();
	CREATE_FUNC(SkillLayer);

	bool isOpenFlag(){ return m_OpenFlag; }
	void setOpenFlag(bool a_OpenFlag) { this->m_OpenFlag = a_OpenFlag; }
	virtual void onEnter();
	virtual void onExit();

	void Open();
	void Close();



	SkillLayer();
	~SkillLayer();
private:
	Sprite* m_panel;
	bool m_OpenFlag;
};


#endif //_FRAMELAYER_H_