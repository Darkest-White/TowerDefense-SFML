#pragma once
#include "GameObject.h"
#include "VectorMath.h"
#include "GameManager.h"

class Enemy : public GameObject
{
protected:
	float max_hp, current_hp;
	float velocity;
	Vector2f direction;
	int damage_to_player;
	int loot;

	Path* path;
	int path_point_index;

public:
	Enemy(Vector2f position, float size_radius, Texture* texture, 
		float max_hp, float velocity, int damage_to_player, int loot, Path* path);
	virtual ~Enemy();

	virtual bool Move(float dt);
};