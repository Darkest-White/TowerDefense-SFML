#include "Projectile.h"

Projectile::Projectile(Vector2f position, float size_radius, Texture* texture,
	float damage, Vector2f direction, float velocity) :
	GameObject(position, size_radius, texture, ObjType::Projectile),
	damage(damage), direction(direction), velocity(velocity)
{

}

Projectile::~Projectile()
{

}

void Projectile::Move(float dt)
{
	direction = ChangeLenght(target_position - position, velocity);

	position.x += direction.x * velocity * dt;
	position.y += direction.y * velocity * dt;
}