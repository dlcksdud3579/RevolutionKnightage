#ifndef _FIELDLAYER_H_ 
#define _FIELDLAYER_H_

#include "cocos2d.h"
#include "DynamicContentsContainer.h"
#include "CMapControler.h"
#include "CCharacterControler.h"

using namespace std;

class FieldLayer: public cocos2d::LayerColor // 필드와 몬스터 그리고 플레이어블 캐릭터등 을 구현 하는 레이어 
{
public:
	FieldLayer(); // 생성자 
	CREATE_FUNC(FieldLayer); // craete함수
	virtual bool init(); // 메인 함수 

	virtual void onEnter(); // 레이서 생성시 불려지는 함수  
	virtual void onExit();// 레이서 종료시 불려지는 함수 

	virtual void printTileField(); // 타일을 그려주는 함수 
	virtual void removeTileField(); // 타일을 지워주는 함수 

	void printCharacter(); // 캐리터를 그려주는 함수 
	void removeCharacter(); // 캐릭터를 지워 주는함수 

	void moveCharacter(); // 캐릭터 이동 함수 
	 void moveCharacter(Vec2 a_Point);


	void moveLayerPoint(Vec2 a_Point); // 레이어 를 이동 


	void moveRight(); //  오른쪽으로 이동 
	void moveLeft(); //  왼쪽으로 이동 
	void moveUp();  //  위로 이동
	void moveDown(); // 아래로 이동


	
	void changeMap(string MapKey);  //맵 면경 
	void checkPortal(); // 포탈인지 체크 
	
	

	void viewControl(); // 보이지 않는곳을 스프라이트 안뛰우고 보이는곳만 보이게하는 함수



	// get set 함수 
	
	virtual CMap* getMap(){ return getMapControler()->getMap(); } // 컨테이너에서 맵 정보를 불러옴 
	CCharacter* getCharacter(){ return getCharacterControler()->getCharacter(); } // 컨테이너에서 현재 맵정보를 불러옴
	
	void setViewPoint(Vec2 a_viewPoint);
	Vec2 getViewPoint(){ return m_viewPoint; }

	void setCharacterControler(CCharacterControler* a_CharacterControler){ this->m_CharacterControler = a_CharacterControler; }
	CCharacterControler* getCharacterControler(){ return this->m_CharacterControler; }

	void setMapControler(CMapControler* a_MapControler){ this->m_MapControler = a_MapControler; }
	CMapControler* getMapControler(){ return this->m_MapControler; }
	
		void setCharacterSprite(Sprite* a_characterSprite){ this->m_characterSprite = a_characterSprite; }
	Sprite* getCharacterSprite(){ return this->m_characterSprite; }
	// /get set 함수



	
private:
	Vec2 m_viewPoint;
	CCharacterControler* m_CharacterControler;
	CMapControler* m_MapControler;
	Sprite* m_characterSprite;
};


#endif //_TESTSCENE_H_