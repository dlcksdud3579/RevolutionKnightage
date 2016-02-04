#include "TurnControler.h"
#include "DynamicContentsContainer.h"

TurnControler::TurnControler() // »ý¼ºÀÚ
{

}

void TurnControler::CharacterTurnEnd()
{




	for (int i = 0; i < 10; i++)
	{
		if (DynamicContentsContainer::getInstance()->getMonster(i) != NULL)
		setMonActionPoint(i,this->getUsedActionPoint());
	}
}

