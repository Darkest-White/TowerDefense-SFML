#include "Arrow.h"
#include "VectorMath.h"
#include "Manager.h"

Arrow::Arrow(Vector2f position, float damage, float velocity, GameObject* target) :
	Projectile(position, 8, LoadTexture("images\\projectiles\\arrow_1.png", { 0,0,0,0 }), damage, { 0,0 }, velocity),
	target(target)
{

}

Arrow::~Arrow()
{

}

void Arrow::Update(float dt)
{
	target_position = target->GetPosition();
	Move(dt);
	if (GetLenght(target_position - position) < velocity * dt)
	{
		MSG* m = new MSG;
		m->type = MsgType::Death;
		m->death.who_to_die = this;
		m->death.killer = this;
		Manager::GetInstance()->SendMsg(m);
	}
}

void Arrow::SendMSG(MSG* m)
{

}