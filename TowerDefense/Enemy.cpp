#include "Enemy.h"

Enemy::Enemy(Vector2f position, float size_radius, Texture* texture,
	float max_hp, float velocity, int damage_to_player, int loot, Path* path) :
	GameObject(position, size_radius, texture, ObjType::Enemy),
	max_hp(max_hp), current_hp(max_hp), velocity(velocity), damage_to_player(damage_to_player), loot(loot), path(path), path_point_index(0)
{

}

Enemy::~Enemy()
{

}

bool Enemy::Move(float dt)
{
	MSG* m = new MSG;
	m->type = MsgType::Move;
	m->move.old_position = position;
	m->sender = this;

	Vector2f target_position = path->GetPoint(path_point_index);
	Vector2f vector_to_target = target_position - position;
	float distance_to_target = GetLenght(vector_to_target);

	if (velocity * dt >= distance_to_target)
	{
		position = target_position;
		return true;
	}

	direction = Normalize(vector_to_target);

	position.x += direction.x * velocity * dt;
	position.y += direction.y * velocity * dt;

	GameManager::GetInstance()->SendMsg(m);

	return false;
}