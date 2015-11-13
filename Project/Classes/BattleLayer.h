#ifndef _BATTLELAYER_H_
#define _BATTLELAYER_H_

#include "FieldLayer.h"

class BattleLayer :public FieldLayer
{
public:
	BattleLayer();
	~BattleLayer();
	void moveCharacter(Touch* touch, Event* event);
private:
	
};
#endif
