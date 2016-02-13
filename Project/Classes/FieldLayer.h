#ifndef _FIELDLAYER_H_ 
#define _FIELDLAYER_H_

#include "cocos2d.h"
#include "DynamicContentsContainer.h"
#include "CMapControler.h"
#include "CCharacterControler.h"
#include "TurnControler.h"
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


	bool moveRight(); //  오른쪽으로 이동  // 이동이 불가시 리턴 false 
	bool moveLeft(); //  왼쪽으로 이동 // 이동이 불가시 리턴 false
	bool moveUp();  //  위로 이동// 이동이 불가시 리턴 false
	bool moveDown(); // 아래로 이동// 이동이 불가시 리턴 false


	
	void changeMap(string MapKey);  //맵 면경 
	void checkPortal(); // 포탈인지 체크 
	
	

	void viewControl(); // 보이지 않는곳을 스프라이트 안뛰우고 보이는곳만 보이게하는 함수

	void printMonster(); // 몬스터 를 그리는 함수
	void removeMonster(); // 그려진 몬스터를 지우는 함수 
	void removeMonster(int index); // 몬스터를 한마리 지움 
	void monstermove(int index); // 몬스터 이동 인덱스에 
	void makeMonster(); // 몬스터를 생성한  
	void deleteMonster(); // 몬스타를 삭제

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

	void setTurnControler(TurnControler *a_turnControler){ m_turnControler = a_turnControler; }
	TurnControler *getTurnControler(){ return m_turnControler; }
	// /get set 함수



	
private:
	Vec2 m_viewPoint; // 눈에 보이는 캐릭터의 위치 
	CCharacterControler* m_CharacterControler; // 캐릭터이동을 당담하는 컨트롤러 
	CMapControler* m_MapControler; // 맵 을 담당하는 컨트롤러 
	Sprite* m_characterSprite; // 캐릭터 스프라이트 

	TurnControler *m_turnControler; // 턴을 컨롤할  친규 

};


#endif //_TESTSCENE_H_