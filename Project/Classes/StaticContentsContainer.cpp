#include "StaticContentsContainer.h"
#include "pugixml.hpp"
using namespace pugi;

std::map<string, CKind*>* StaticContentsContainer::m_mapKind = new std::map<string, CKind*>(); //����
std::map<string, CJob*>* StaticContentsContainer::m_mapJob = new std::map<string, CJob*>(); // ���� 
std::map<string, CSpecialty*>* StaticContentsContainer::m_mapSpecialty = new std::map<string, CSpecialty*>();  //Ư��
std::map<string, CItem*>* StaticContentsContainer::m_mapItem = new std::map<string, CItem*>(); // ������ 
std::map<string, CSkill*>* StaticContentsContainer::m_mapSkill = new std::map<string, CSkill*>(); // ��ų 
std::map<string, CCondition*>* StaticContentsContainer::m_mapCondition = new std::map<string, CCondition*>(); // ����?
std::map<string, CMap*>* StaticContentsContainer::m_mapMap = new std::map<string, CMap*>(); // ��
std::map<string, CScenario*>* StaticContentsContainer::m_mapScenario = new std::map<string, CScenario*>();  // �ó����� 
std::map<string, CDice*>* StaticContentsContainer::m_mapDice = new std::map<string, CDice*>(); // �ֻ���
std::map<string, CTile*>* StaticContentsContainer::m_mapTile = new std::map<string, CTile*>(); // Ÿ��;
std::map<string, CObject*>* StaticContentsContainer::m_mapObject = new std::map<string, CObject*>();//������Ʈ

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

	// �ε� �ɺ���
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

	// �ε� �ɺ���
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

	// �ε� �ɺ���
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

	// �ε� �ɺ���
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

	// �ε� �ɺ���
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
	xml_document xmlDoc;
	xml_parse_result result = xmlDoc.load_file("data/skill.xml");

	if (!result)
	{
		log("Error description: %s", result.description());
		log("Error offset: %d", result.offset);
		return;
	}

	// �ε� �ɺ���
	xml_node nodeResult = xmlDoc.child("result");

	xml_node nodeItems = nodeResult.child("items");

	//Type 1
	for (xml_node nodeItem = nodeItems.child("item"); nodeItem; nodeItem = nodeItem.next_sibling("item"))
	{
		std::string symbolKey = nodeItem.child("key").text().get();

		log("%s", symbolKey.c_str());
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

	// �ε� �ɺ���
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
	// ������ �������� Ȯ�� 

	// map �� �о��� �κ� 
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

	// �ε� �ɺ���
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

	// �ε� �ɺ���
	xml_node nodeResult = xmlDoc.child("result");

	xml_node nodeItems = nodeResult.child("items");

	//Type 1
	for (xml_node nodeItem = nodeItems.child("item"); nodeItem; nodeItem = nodeItem.next_sibling("item"))
	{
		std::string symbolKey = nodeItem.child("key").text().get();

		log("%s", symbolKey.c_str());
	}
}

