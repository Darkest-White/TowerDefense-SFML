#pragma once
#include "Projectile.h"
#include "Enemy.h"

class Arrow : public Projectile
{
protected:
	Enemy* target_enemy;

public:
	Arrow();
	Arrow(const Arrow&);
	~Arrow();

	void Update(float dt);
	void sendMSG(MSG* m);
};

