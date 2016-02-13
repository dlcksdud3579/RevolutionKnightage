#ifndef _FIELDLAYER_H_ 
#define _FIELDLAYER_H_

#include "cocos2d.h"
#include "DynamicContentsContainer.h"
#include "CMapControler.h"
#include "CCharacterControler.h"
#include "TurnControler.h"
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


	bool moveRight(); //  ���������� �̵�  // �̵��� �Ұ��� ���� false 
	bool moveLeft(); //  �������� �̵� // �̵��� �Ұ��� ���� false
	bool moveUp();  //  ���� �̵�// �̵��� �Ұ��� ���� false
	bool moveDown(); // �Ʒ��� �̵�// �̵��� �Ұ��� ���� false


	
	void changeMap(string MapKey);  //�� ��� 
	void checkPortal(); // ��Ż���� üũ 
	
	

	void viewControl(); // ������ �ʴ°��� ��������Ʈ �ȶٿ�� ���̴°��� ���̰��ϴ� �Լ�

	void printMonster(); // ���� �� �׸��� �Լ�
	void removeMonster(); // �׷��� ���͸� ����� �Լ� 
	void removeMonster(int index); // ���͸� �Ѹ��� ���� 
	void monstermove(int index); // ���� �̵� �ε����� 
	void makeMonster(); // ���͸� ������  
	void deleteMonster(); // ��Ÿ�� ����

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

	void setTurnControler(TurnControler *a_turnControler){ m_turnControler = a_turnControler; }
	TurnControler *getTurnControler(){ return m_turnControler; }
	// /get set �Լ�



	
private:
	Vec2 m_viewPoint; // ���� ���̴� ĳ������ ��ġ 
	CCharacterControler* m_CharacterControler; // ĳ�����̵��� ����ϴ� ��Ʈ�ѷ� 
	CMapControler* m_MapControler; // �� �� ����ϴ� ��Ʈ�ѷ� 
	Sprite* m_characterSprite; // ĳ���� ��������Ʈ 

	TurnControler *m_turnControler; // ���� ������  ģ�� 

};


#endif //_TESTSCENE_H_