#ifndef  _TILE_H_
#define  _TILE_H_
#include "cocos2d.h"
#include "CObject.h"

USING_NS_CC;
using namespace std;
// Ÿ�� �� �ϳ�
class CTile
{
public:
	CTile(); // ������
	CTile(string a_szName, string a_SpriteRoot, CObject* m_Object2);
	CTile(CTile* a_CopyCTile, Vec2 a_Point, CObject* a_Object0, CObject* a_Object1); // ���� ������

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

	string m_szName; // Ÿ���� �̸�
	Vec2 m_Size; // Ÿ���� ũ��
	Vec2 m_Point;
	string m_SpriteRoot; // Ÿ�� ��������Ʈ ��Ʈ
	Sprite* m_Sprite; // ��������Ʈ ����Ʈ ��ü ����
	CObject* m_Object[3]; // Ÿ�� �� ������Ʈ�� 0 - move ������Ʈ ĳ���Ͷ� ��ġ�� ���� (ex NPC ), 1 - ����, 2 - Ÿ�� ��ü ����, 

};


#endif