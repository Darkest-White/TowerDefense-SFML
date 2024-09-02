#pragma once
#include "Projectile.h"

class Arrow : public Projectile
{
protected:
	GameObject* target;

public:
	Arrow(Vector2f position, float damage, float velocity, GameObject* target);
	~Arrow();

	void Update(float dt);
	void SendMSG(MSG* m);
};