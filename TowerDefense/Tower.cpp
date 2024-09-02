#include"Tower.h"

Tower::Tower(Vector2f position, float size_radius, Texture* texture, int level, int cost,
	float cooldown_time, float action_range) :
	GameObject(position, size_radius, texture), level(level), cost(cost),
	cooldown_time(cooldown_time), action_range(action_range), cooldown_current(0)
{

}

Tower::~Tower()
{

}