#pragma once
#include "GameObject.h"

class Tower : public GameObject
{
protected:
	int level;
	int cost;

	float cooldown_time;
	float cooldown_current;
	float action_range;

public:
	Tower(Vector2f position, float size_radius, Texture* texture, int level, int cost,
		float cooldown_time, float action_range);
	virtual ~Tower();
	virtual void Action() = 0;
};