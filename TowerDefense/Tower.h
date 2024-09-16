#pragma once
#include "GameObject.h"
#include "Enemy.h"
#include<list>

class Tower : public GameObject
{
protected:
	int level;
	int cost;

	float cooldown_time, cooldown_current;
	float action_range;

	list<Enemy*> enemies_in_range;

public:
	Tower(Vector2f position, float size_radius, Texture* texture, 
		int level, int cost, float cooldown_time, float action_range);
	virtual ~Tower();
	virtual void Action() = 0;
	virtual void CheckEnemiesInRange();
	virtual void AddEnemyIfInRange(Enemy* enemy);
	bool IsInActionRange(GameObject* object);
	bool CloserEnemy(Enemy* e1, Enemy* e2);
};