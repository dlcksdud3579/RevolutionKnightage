#include "StaticContentsContainer.h"
#include "pugixml.hpp"
#include "CStatus.h"

using namespace pugi;

std::map<string, CKind*>* StaticContentsContainer::m_mapKind = new std::map<string, CKind*>(); //종족
std::map<string, CJob*>* StaticContentsContainer::m_mapJob = new std::map<string, CJob*>(); // 직업 
std::map<string, CSpecialty*>* StaticContentsContainer::m_mapSpecialty = new std::map<string, CSpecialty*>();  //특기
std::map<string, CItem*>* StaticContentsContainer::m_mapItem = new std::map<string, CItem*>(); // 아이템 
std::map<string, CSkill*>* StaticContentsContainer::m_mapSkill = new std::map<string, CSkill*>(); // 스킬 
std::map<string, CCondition*>* StaticContentsContainer::m_mapCondition = new std::map<string, CCondition*>(); // 상태?
std::map<string, CMap*>* StaticContentsContainer::m_mapMap = new std::map<string, CMap*>(); // 맵
std::map<string, CScenario*>* StaticContentsContainer::m_mapScenario = new std::map<string, CScenario*>();  // 시나리오 
std::map<string, CDice*>* StaticContentsContainer::m_mapDice = new std::map<string, CDice*>(); // 주사위
std::map<string, CTile*>* StaticContentsContainer::m_mapTile = new std::map<string, CTile*>(); // 타일;
std::map<string, CObject*>* StaticContentsContainer::m_mapObject = new std::map<string, CObject*>();//오브젝트
std::map<string, CMonster*>* StaticContentsContainer::m_mapMonster = new std::map<string, CMonster*>(); //몬스타

void StaticContentsContainer::readxml()
{
	StaticContentsContainer::readMapObject();
	StaticContentsContainer::readMapTile();
	StaticContentsContainer::readMapKind();
	StaticContentsContainer::readMapJob();
	StaticContentsContainer::readMapSpecialty();
	StaticContentsContainer::readMapItem();
	StaticContentsContainer::readMapSkill();
	StaticContentsContainer::readMapCondition();
	StaticContentsContainer::readMapMap();
	StaticContentsContainer::readMapScenario();
	StaticContentsContainer::readMapDice();
	StaticContentsContainer::readMapMonster();
}

void StaticContentsContainer::readMapKind()
{
	xml_document xmlDoc;
	xml_parse_result result = xmlDoc.load_file("data/kind.xml");

	if (!result)
	{
		log("Error description: %s", result.description());
		log("Error offset: %d", result.offset);
		return;
	}

	// 로드 심볼스
	xml_node nodeResult = xmlDoc.child("result");

	xml_node nodeItems = nodeResult.child("items");

	//Type 1
	for (xml_node nodeItem = nodeItems.child("item"); nodeItem; nodeItem = nodeItem.next_sibling("item"))
	{
		std::string symbolKey = nodeItem.child("key").text().get();

		log("%s", symbolKey.c_str());
	}
}
void StaticContentsContainer::readMapJob()
{
	xml_document xmlDoc;
	xml_parse_result result = xmlDoc.load_file("data/job.xml");

	if (!result)
	{
		log("Error description: %s", result.description());
		log("Error offset: %d", result.offset);
		return;
	}

	// 로드 심볼스
	xml_node nodeResult = xmlDoc.child("result");

	xml_node nodeItems = nodeResult.child("items");

	//Type 1
	for (xml_node nodeItem = nodeItems.child("item"); nodeItem; nodeItem = nodeItem.next_sibling("item"))
	{
		std::string symbolKey = nodeItem.child("key").text().get();

		log("%s", symbolKey.c_str());
	}
}

void StaticContentsContainer::readMapObject()
{
	xml_document xmlDoc;
	xml_parse_result result = xmlDoc.load_file("data/object.xml");

	if (!result)
	{
		log("Error description: %s", result.description());
		log("Error offset: %d", result.offset);
		return;
	}

	// 로드 심볼스
	xml_node nodeResult = xmlDoc.child("result");

	xml_node nodeObjects = nodeResult.child("objects");

	//Type 1
	for (xml_node nodeObject = nodeObjects.child("object"); nodeObject; nodeObject = nodeObject.next_sibling("object"))
	{
		pair<string, CObject*> tempPairObject(
			nodeObject.child("key").text().get(),
			new CObject(nodeObject.child("name").text().get(),
			nodeObject.child("moveable").text().as_bool(),
			nodeObject.child("type").text().as_int()));

		getMapObject()->insert(tempPairObject);
	}
}

void StaticContentsContainer::readMapSpecialty()
{
	xml_document xmlDoc;
	xml_parse_result result = xmlDoc.load_file("data/specialty.xml");

	if (!result)
	{
		log("Error description: %s", result.description());
		log("Error offset: %d", result.offset);
		return;
	}

	// 로드 심볼스
	xml_node nodeResult = xmlDoc.child("result");

	xml_node nodeItems = nodeResult.child("items");

	//Type 1
	for (xml_node nodeItem = nodeItems.child("item"); nodeItem; nodeItem = nodeItem.next_sibling("item"))
	{
		std::string symbolKey = nodeItem.child("key").text().get();

		log("%s", symbolKey.c_str());
	}
}
void StaticContentsContainer::readMapItem()
{
	xml_document xmlDoc;
	xml_parse_result result = xmlDoc.load_file("data/item.xml");

	if (!result)
	{
		log("Error description: %s", result.description());
		log("Error offset: %d", result.offset);
		return;
	}

	// 로드 심볼스
	xml_node nodeResult = xmlDoc.child("result");

	xml_node nodeItems = nodeResult.child("items");

	//Type 1
	for (xml_node nodeItem = nodeItems.child("item"); nodeItem; nodeItem = nodeItem.next_sibling("item"))
	{
		std::string symbolKey = nodeItem.child("key").text().get();

		log("%s", symbolKey.c_str());
	}
}
void StaticContentsContainer::readMapSkill()
{
	Vec2 temp;
	xml_document xmlDoc;
	xml_parse_result result = xmlDoc.load_file("data/skill.xml");
	int i=0;

	if (!result)
	{
		log("Error description: %s", result.description());
		log("Error offset: %d", result.offset);
		return;
	}

	// 로드 심볼스
	xml_node nodeResult = xmlDoc.child("result");

	xml_node nodeSkills = nodeResult.child("skills");

	//Type 1
	for (xml_node nodeskill = nodeSkills.child("skill"); nodeskill; nodeskill = nodeskill.next_sibling("skill"))
	{
		pair<string, CSkill*> tempPairSKill(
			nodeskill.child("key").text().get(),
			new CSkill(nodeskill.child("name").text().get(),
			nodeskill.child("range").text().as_int(),
			nodeskill.child("diceType").text().as_int(),
			nodeskill.child("diceNum").text().as_int(),
			nodeskill.child("attribute").text().as_int(),
			nodeskill.child("accuracyRate").text().as_int()));

		for (xml_node nodeSplashs = nodeSkills.child("splashs"); nodeSplashs; nodeSplashs = nodeSplashs.next_sibling("splashs"))
		{
			xml_node sybolSplash = nodeSplashs.child("splash");
			temp.x = stoi(sybolSplash.child("x").text().get());
			temp.y = stoi(sybolSplash.child("y").text().get());
			tempPairSKill.second->setSplash(temp, i++);
		}


		getMapSkill()->insert(tempPairSKill);
	}
}
void StaticContentsContainer::readMapCondition()
{
	xml_document xmlDoc;
	xml_parse_result result = xmlDoc.load_file("data/condition");

	if (!result)
	{
		log("Error description: %s", result.description());
		log("Error offset: %d", result.offset);
		return;
	}

	// 로드 심볼스
	xml_node nodeResult = xmlDoc.child("result");

	xml_node nodeItems = nodeResult.child("items");

	//Type 1
	for (xml_node nodeItem = nodeItems.child("item"); nodeItem; nodeItem = nodeItem.next_sibling("item"))
	{
		std::string symbolKey = nodeItem.child("key").text().get();

		log("%s", symbolKey.c_str());
	}
}
void StaticContentsContainer::readMapTile()
{
	xml_document xmlDoc;



	xml_parse_result resultDoc = xmlDoc.load_file("data/tile.xml");

	if (!resultDoc)
	{
		log("Error description: %s", resultDoc.description());
		log("Error offset: %d", resultDoc.offset);
		return;
	}

	xml_node nodeResult = xmlDoc.child("result");
	xml_node nodeTiles = nodeResult.child("tiles");
	for (xml_node nodeTile = nodeTiles.child("tile"); nodeTile; nodeTile = nodeTile.next_sibling("tile"))
	{

		pair<string, CTile*> tempPairTile(
			nodeTile.child("key").text().get(),
			new CTile(
			nodeTile.child("name").text().get(),
			nodeTile.child("SpriteRoot").text().get(),
			getMapObject()->find(nodeTile.child("Object2").text().get())->second));

		getMapTile()->insert(tempPairTile);
		
	}
}

void StaticContentsContainer::readMapMap()
{

	xml_document xmlDoc;



	xml_parse_result resultDoc = xmlDoc.load_file("data/map.xml");

	if (!resultDoc)
	{
		log("Error description: %s", resultDoc.description());
		log("Error offset: %d", resultDoc.offset);
		return;
	}
	// 파일이 열였는지 확인 

	// map 을 읽어노는 부분 
	xml_node nodeResult = xmlDoc.child("result");

	xml_node nodeMaps = nodeResult.child("maps");

	//Type 1
	for (xml_node nodeMap = nodeMaps.child("map"); nodeMap; nodeMap = nodeMap.next_sibling("map"))
	{
		CMap *tempMap = new CMap();
		int Xsize = 0, Ysize = 0;
		std::string symbolSubject = nodeMap.child("subject").text().get();
		std::string symbolName = nodeMap.child("name").text().get();

		xml_node nodeStartPoint = nodeMap.child("startPoint");
		tempMap->setStartPoint(Vec2(
			atoi(nodeStartPoint.child("x").text().get()),
			atoi(nodeStartPoint.child("y").text().get())));

		xml_node nodeRows = nodeMap.child("rows");

		for (xml_node nodeRow = nodeRows.child("row"); nodeRow; nodeRow = nodeRow.next_sibling("row"))
		{
			xml_node nodeTiles = nodeRow.child("tiles");
			Ysize++;
			Xsize = 0;
			for (xml_node nodeTile = nodeTiles.child("tile"); nodeTile; nodeTile = nodeTile.next_sibling("tile"))
			{
				Xsize++;
				tempMap->addTile(Vec2(atoi(nodeTile.child("seq").text().get()), atoi(nodeRow.child("seq").text().get())),
					new CTile(
					getMapTile()->find(nodeTile.child("kind").text().get())->second,
					Vec2(atoi(nodeTile.child("seq").text().get()), atoi(nodeRow.child("seq").text().get())),
					NULL,
					NULL
					));

			}

		}
		tempMap->setSizeTile(Vec2(Xsize, Ysize));

		pair<string, CMap*> tempPairMap(nodeMap.child("key").text().get(), tempMap);
		getMapMap()->insert(tempPairMap);
	}
}

void StaticContentsContainer::readMapScenario()
{
	xml_document xmlDoc;
	xml_parse_result result = xmlDoc.load_file("data/scenario.xml");

	if (!result)
	{
		log("Error description: %s", result.description());
		log("Error offset: %d", result.offset);
		return;
	}

	// 로드 심볼스
	xml_node nodeResult = xmlDoc.child("result");

	xml_node nodeItems = nodeResult.child("items");

	//Type 1
	for (xml_node nodeItem = nodeItems.child("item"); nodeItem; nodeItem = nodeItem.next_sibling("item"))
	{
		std::string symbolKey = nodeItem.child("key").text().get();

		log("%s", symbolKey.c_str());
	}
}
void StaticContentsContainer::readMapDice()
{
	xml_document xmlDoc;
	xml_parse_result result = xmlDoc.load_file("data/dice.xml");

	if (!result)
	{
		log("Error description: %s", result.description());
		log("Error offset: %d", result.offset);
		return;
	}

	// 로드 심볼스
	xml_node nodeResult = xmlDoc.child("result");

	xml_node nodeItems = nodeResult.child("items");

	//Type 1
	for (xml_node nodeItem = nodeItems.child("item"); nodeItem; nodeItem = nodeItem.next_sibling("item"))
	{
		std::string symbolKey = nodeItem.child("key").text().get();

		log("%s", symbolKey.c_str());
	}
}

void StaticContentsContainer::readMapMonster()
{
	xml_document xmlDoc;
	xml_parse_result result = xmlDoc.load_file("data/monster.xml");
	int cnt=0;
	if (!result)
	{
		log("Error description: %s", result.description());
		log("Error offset: %d", result.offset);
		return;
	}

	// 로드 심볼스
	xml_node nodeResult = xmlDoc.child("result");

	xml_node nodemonsters = nodeResult.child("monsters");

	//Type 1
	for (xml_node nodemonster = nodemonsters.child("monster"); nodemonster; nodemonster = nodemonster.next_sibling("monster"))
	{
		
		pair<string, CMonster*> tempPairMonster(
			nodemonster.child("key").text().get(),
			new CMonster(nodemonster.child("name").text().get(),
			nodemonster.child("spriteRoot").text().get()));
		
		xml_node nodeStatus = nodemonster.child("status");
		tempPairMonster.second->setStatus(new Status(nodeStatus.child("hp").text().as_int(), 
			nodeStatus.child("spd").text().as_int(),
			nodeStatus.child("def").text().as_int(),
			nodeStatus.child("str").text().as_int(),
			nodeStatus.child("dex").text().as_int(),
			nodeStatus.child("ins").text().as_int(),
			nodeStatus.child("kno").text().as_int()));

		 xml_node nodeSkills = nodemonster.child("skills");
		 cnt = 0;
		 for (xml_node nodeSkillKey = nodeSkills.child("skillKey"); nodeSkillKey; nodeSkillKey = nodeSkillKey.next_sibling("skillKey"))
		 {
			 tempPairMonster.second->setSkill(getMapSkill()->find(nodeSkillKey.text().get())->second, cnt++);
		 }
		 xml_node nodeitems = nodemonster.child("items");
		 for (xml_node nodesitem = nodeitems.child("ItemKey"); nodesitem; nodesitem = nodesitem.next_sibling("ItemKey"))
		 {
			 tempPairMonster.second->setItem(getMapItem()->find(nodesitem.text().get())->second, cnt++);
		 }

		 getMapMonster()->insert(tempPairMonster);

	}
}



