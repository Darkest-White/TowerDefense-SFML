#pragma once
#include "GameObject.h"

class Enemy : public GameObject
{
protected:
	int damage_to_player;
	int loot;
	float max_hp, hp;
	Vector2 direction;
	float velocity;

public:
	Enemy();
	Enemy(const Enemy&);
	~Enemy();

	virtual void Move(float dt);
};

