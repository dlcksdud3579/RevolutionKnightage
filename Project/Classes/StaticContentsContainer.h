#ifndef _STATICCONTENTSCONTAINER_H
#define _STATICCONTENTSCONTAINER_H
#include "CKind.h"
#include "CJob.h"
#include "CSpecialty.h"
#include "CItem.h"
#include "CSkill.h"
#include "CCondition.h"
#include "CMap.h"
#include "CScenario.h"
#include "CDice.h"
#include "CObject.h"
#include "CMonster.h"

static class  StaticContentsContainer  // 정적으로 생성되는 함수 xml 파일 데이터를 다루는  클래스 
{
public:
	static std::map<string, CKind*>* getMapKind(){ return m_mapKind; }
	static void setMapKind(std::map<string, CKind*>* a_mapKind){ m_mapKind = a_mapKind; }

	static std::map<string, CJob*>* getMapJob(){ return m_mapJob; }
	static void setMapJob(static std::map<string, CJob*>* a_mapJob){ m_mapJob = a_mapJob; }

	static std::map<string, CSpecialty*>* getMapSpecialty(){ return m_mapSpecialty; }
	static void setMapSpecialty(std::map<string, CSpecialty*>* a_mapSpecialty){ m_mapSpecialty = a_mapSpecialty; }

	static std::map<string, CItem*>* getMapItem(){ return m_mapItem; }
	static void setMapItem(static std::map<string, CItem*>* a_mapItem){ m_mapItem = a_mapItem; }

	static std::map<string, CSkill*>* getMapSkill(){ return m_mapSkill; }
	static void setMapSkill(std::map<string, CSkill*>* a_mapSkill){ m_mapSkill = a_mapSkill; }

	static std::map<string, CCondition*>* getMapCondition(){ return m_mapCondition; }
	static void setMapCondition(std::map<string, CCondition*>* a_mapCondition){ m_mapCondition = a_mapCondition; }

	static std::map<string, CMap*>* getMapMap(){ return m_mapMap; }
	static void setMapMap(std::map<string, CMap*>* a_mapMap){ m_mapMap = a_mapMap; }

	static std::map<string, CScenario*>* getMapScenario(){ return m_mapScenario; }
	static void setMapScenario(std::map<string, CScenario*>* a_mapScenario){ m_mapScenario = a_mapScenario; }

	static std::map<string, CDice*>* getMapDice(){ return m_mapDice; }
	static void setMapDice(std::map<string, CDice*>* a_mapDice){ m_mapDice = a_mapDice; }
	
	static std::map<string, CTile*>* getMapTile(){ return m_mapTile; }
	static void setMapTile(std::map<string, CTile*>* a_mapTile){ m_mapTile = a_mapTile; }

	static std::map<string, CObject*>* getMapObject(){ return m_mapObject; }
	static void setMapObject(std::map<string, CObject*>* a_mapObject){ m_mapObject = a_mapObject; }

	static std::map<string, CMonster*>* getMapMonster(){ return m_mapMonster; }
	static void setMapMonster(std::map<string, CMonster*>* a_mapMonster){ m_mapMonster = a_mapMonster; }

	static void readxml();

private:
	static std::map<string, CKind*>* m_mapKind; //종족
	static std::map<string, CJob*>* m_mapJob; // 직업 
	static std::map<string, CSpecialty*>* m_mapSpecialty;  //특기
	static std::map<string, CItem*>* m_mapItem; // 아이템 
	static std::map<string, CSkill*>* m_mapSkill; // 스킬 
	static std::map<string, CCondition*>* m_mapCondition; // 상태?
	static std::map<string, CMap*>* m_mapMap; // 맵
	static std::map<string, CScenario*>* m_mapScenario;  // 시나리오 
	static std::map<string, CDice*>* m_mapDice; // 주사위
	static std::map<string, CTile*>* m_mapTile; // 타일
	static std::map<string, CObject*>* m_mapObject; // 오브 젝트
	static std::map<string, CMonster*>* m_mapMonster; //몬스타 
	static std::map<string, CObject**>* m_mapMonsterArray;

	//각각 읽어오는 함수 
	static void readMapObject();
	static void readMapTile();
	static void readMapKind(); 
	static void readMapJob();
	static void readMapSpecialty();  
	static void readMapItem(); 
	static void readMapSkill(); 
	static void readMapCondition(); 
	static void readMapMap(); 
	static void readMapScenario();  
	static void readMapDice(); 
	static void readMapMonster();
	static void readMapMonsterArray();
};
#endif