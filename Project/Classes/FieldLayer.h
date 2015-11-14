#ifndef _FIELDLAYER_H_
#define _FIELDLAYER_H_

#include "cocos2d.h"
#include "DynamicContentsContainer.h"
#include "CMapControler.h"
#include "CCharacterControler.h"

using namespace std;

class FieldLayer: public cocos2d::LayerColor
{
public:
	FieldLayer();

	virtual bool init();

	void printTileField();
	void removeTileField();

	void printCharacter();
	void removeCharacter();

	CREATE_FUNC(FieldLayer);

	void moveCharacter();

	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();

	virtual void onEnter();
	virtual void onExit();
	
	void changeMap(int index);


	// get set �Լ� 
	
	CMap* getMap(){ return getMapControler()->getMap(); } // �����̳ʿ��� ĳ���� ������ �ҷ��� 
	CCharacter* getCharacter(){ return getCharacterControler()->getCharacter(); } // �����̳ʿ��� ���� �������� �ҷ���
	
	void setViewPoint(Vec2 a_viewPoint);
	Vec2 getViewPoint(){ return m_viewPoint; }

	void setCharacterControler(CCharacterControler* a_CharacterControler){ this->m_CharacterControler = a_CharacterControler; }
	CCharacterControler* getCharacterControler(){ return this->m_CharacterControler; }

	void setMapControler(CMapControler* a_MapControler){ this->m_MapControler = a_MapControler; }
	CMapControler* getMapControler(){ return this->m_MapControler; }
	// /get set �Լ�

	
	void moveCharacter(Vec2 a_Point);
	void moveLayerPoint(Vec2 a_Point);

	void viewControl(); // ������ �ʴ°��� ��������Ʈ �ȶٿ�� ���̴°��� ���̰��ϴ� �Լ�

	
private:
	Vec2 m_viewPoint;
	CCharacterControler* m_CharacterControler;
	CMapControler* m_MapControler;
	
};


#endif //_TESTSCENE_H_