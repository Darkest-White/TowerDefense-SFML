#pragma once
#include "Tower.h"

class ArrowTower : public Tower
{
public:
	GameObject* target_locked = nullptr;

public:
	ArrowTower(Vector2f position, int level);
	~ArrowTower();

	void Update(float dt);
	void SendMSG(MSG* m);
	void Action();
};