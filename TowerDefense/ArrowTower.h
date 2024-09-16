#pragma once
#include "Tower.h"
#include "GameManager.h"
#include <algorithm>

class ArrowTower : public Tower
{
protected:
	GameObject* target_locked = nullptr;

public:
	ArrowTower(Vector2f position, int level);
	~ArrowTower();

	void Update(float dt);
	void SendMSG(MSG* m);
	void Action();
};