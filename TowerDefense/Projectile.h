#pragma once
#include "GameObject.h"

class Projectile : public GameObject
{
protected:
	float damage;
	Vector2 direction;
	float velocity;
	Vector2 target_position;

public:
	Projectile();
	Projectile(const Projectile&);
	virtual ~Projectile();

	virtual void Move(float dt);
};

