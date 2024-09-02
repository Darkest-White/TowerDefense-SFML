#pragma once
#include "GameObject.h"

class Enemy : public GameObject
{
protected:
	float max_hp, hp;
	float velocity;
	Vector2f direction;
	int damage_to_player;
	int loot;

public:
	Enemy();
	Enemy(const Enemy&);
	~Enemy();

	virtual void Move(float dt);
};