#pragma once
#include "GameManager.h"
#include "GameObject.h"
#include "VectorMath.h"

class Projectile : public GameObject
{
protected:
	float damage;
	Vector2f direction;
	float velocity;
	Vector2f target_position;

public:
	Projectile(Vector2f position, float size_radius, Texture* texture, 
		float damage, Vector2f direction, float velocity);
	virtual ~Projectile();

	virtual void Move(float dt);
};