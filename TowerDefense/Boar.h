#pragma once
#include "Enemy.h"

class Boar : public Enemy
{
public:
	Boar(float max_hp, float velocity, int damage_to_player, int loot, Path* path);

	void Update(float dt);
	void SendMSG(MSG* m);
};