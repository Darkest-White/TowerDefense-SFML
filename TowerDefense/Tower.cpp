#include"Tower.h"
#include"VectorMath.h"
#include<algorithm>

Tower::Tower(Vector2f position, float size_radius, Texture* texture,
	int level, int cost, float cooldown_time, float action_range) :
	GameObject(position, size_radius, texture, ObjType::Tower), 
	level(level), cost(cost), cooldown_time(cooldown_time), action_range(action_range), cooldown_current(0), enemies_in_range()
{

}

Tower::~Tower()
{

}

bool Tower::IsInActionRange(GameObject* object)
{
	return GetDistance(position, object->GetPosition()) <= action_range;
}

void Tower::CheckEnemiesInRange()
{
	for (auto e = enemies_in_range.begin(); e != enemies_in_range.end();)
	{
		float distance = GetDistance(position, (*e)->GetPosition());
		if (distance > action_range)
		{
			auto tmp = e;
			tmp++;
			enemies_in_range.erase(e);
			e = tmp;
		}
		else
		{
			e++;
		}
	}
}

void Tower::AddEnemyIfInRange(Enemy* enemy)
{
	auto e = find(enemies_in_range.begin(), enemies_in_range.end(), enemy);
	if (e == enemies_in_range.end())
	{
		float distance = GetDistance(position, enemy->GetPosition());
		if (distance <= action_range)
		{
			enemies_in_range.push_back(enemy);
		}
	}
}

bool Tower::CloserEnemy(Enemy* e1, Enemy* e2)
{
	float d1 = GetDistance(position, e1->GetPosition());
	float d2 = GetDistance(position, e2->GetPosition());
	return d1 < d2;
}