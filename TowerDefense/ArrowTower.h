#pragma once
#include "Tower.h"

class ArrowTower : public Tower
{
public:
	ArrowTower();
	ArrowTower(const ArrowTower&);
	~ArrowTower();

	void Update(float dt);
	void sendMSG(MSG m);
	void Action();
};

