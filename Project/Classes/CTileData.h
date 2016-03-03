#ifndef  _TILE_H_
#define  _TILE_H_
#include "cocos2d.h"
#include "CObject.h"

USING_NS_CC;
using namespace std;
// 타일 맵 하나
class CTile
{
public:
	CTile(); // 생성자
	CTile(string a_szName, string a_SpriteRoot, CObject* m_Object2);
	CTile(CTile* a_CopyCTile, Vec2 a_Point, CObject* a_Object0, CObject* a_Object1); // 복사 생성자

	~CTile();
	void setName(string a_szName){ this->m_szName = a_szName; }
	string getName(){ return this->m_szName; }

	void setPoint(Vec2 a_Point){ this->m_Point = a_Point; }
	Vec2 getPoint(){ return this->m_Point; }

	void setSize(){ this->m_Size = Vec2(100, 100); }
	Vec2 getSize(){ return this->m_Size; }

	void setSpriteRoot(string a_SpriteRoot){ this->m_SpriteRoot = a_SpriteRoot; }
	string getSpriteRoot(){ return this->m_SpriteRoot; }

	void setSprite(Sprite* a_Sprite){ this->m_Sprite = a_Sprite; }
	Sprite* getSprite(){ return this->m_Sprite; }

	void setObject(CObject* a_Object, int a_index){ if (a_index >= 0 && a_index<3) this->m_Object[a_index] = a_Object; }
	CObject* getObject(int a_index){ if (a_index >= 0 && a_index < 3)  return this->m_Object[a_index]; return NULL; }



private:

	string m_szName; // 타일의 이름
	Vec2 m_Size; // 타일의 크기
	Vec2 m_Point;
	string m_SpriteRoot; // 타일 스프라이트 루트
	Sprite* m_Sprite; // 스프라이트 포인트 자체 저장
	CObject* m_Object[3]; // 타일 위 오브제트들 0 - move 오브젝트 캐릭터랑 곁치지 못함 (ex NPC ), 1 - 함정, 2 - 타일 자체 성능, 

};


#endif