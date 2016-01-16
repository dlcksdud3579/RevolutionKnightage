#ifndef _FIELDLAYER_H_ 
#define _FIELDLAYER_H_

#include "cocos2d.h"
#include "DynamicContentsContainer.h"
#include "CMapControler.h"
#include "CCharacterControler.h"

using namespace std;

class FieldLayer: public cocos2d::LayerColor // �ʵ�� ���� �׸��� �÷��̾�� ĳ���͵� �� ���� �ϴ� ���̾� 
{
public:
	FieldLayer(); // ������ 
	CREATE_FUNC(FieldLayer); // craete�Լ�
	virtual bool init(); // ���� �Լ� 

	virtual void onEnter(); // ���̼� ������ �ҷ����� �Լ�  
	virtual void onExit();// ���̼� ����� �ҷ����� �Լ� 

	virtual void printTileField(); // Ÿ���� �׷��ִ� �Լ� 
	virtual void removeTileField(); // Ÿ���� �����ִ� �Լ� 

	void printCharacter(); // ĳ���͸� �׷��ִ� �Լ� 
	void removeCharacter(); // ĳ���͸� ���� �ִ��Լ� 

	void moveCharacter(); // ĳ���� �̵� �Լ� 
	 void moveCharacter(Vec2 a_Point);


	void moveLayerPoint(Vec2 a_Point); // ���̾� �� �̵� 


	void moveRight(); //  ���������� �̵� 
	void moveLeft(); //  �������� �̵� 
	void moveUp();  //  ���� �̵�
	void moveDown(); // �Ʒ��� �̵�


	
	void changeMap(string MapKey);  //�� ��� 
	void checkPortal(); // ��Ż���� üũ 
	
	

	void viewControl(); // ������ �ʴ°��� ��������Ʈ �ȶٿ�� ���̴°��� ���̰��ϴ� �Լ�



	// get set �Լ� 
	
	virtual CMap* getMap(){ return getMapControler()->getMap(); } // �����̳ʿ��� �� ������ �ҷ��� 
	CCharacter* getCharacter(){ return getCharacterControler()->getCharacter(); } // �����̳ʿ��� ���� �������� �ҷ���
	
	void setViewPoint(Vec2 a_viewPoint);
	Vec2 getViewPoint(){ return m_viewPoint; }

	void setCharacterControler(CCharacterControler* a_CharacterControler){ this->m_CharacterControler = a_CharacterControler; }
	CCharacterControler* getCharacterControler(){ return this->m_CharacterControler; }

	void setMapControler(CMapControler* a_MapControler){ this->m_MapControler = a_MapControler; }
	CMapControler* getMapControler(){ return this->m_MapControler; }
	
		void setCharacterSprite(Sprite* a_characterSprite){ this->m_characterSprite = a_characterSprite; }
	Sprite* getCharacterSprite(){ return this->m_characterSprite; }
	// /get set �Լ�



	
private:
	Vec2 m_viewPoint;
	CCharacterControler* m_CharacterControler;
	CMapControler* m_MapControler;
	Sprite* m_characterSprite;
};


#endif //_TESTSCENE_H_