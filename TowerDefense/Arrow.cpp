#include "Arrow.h"

Arrow::Arrow(Vector2f position, float damage, float velocity, GameObject* target) :
	Projectile(position, 8, LoadTexture("images\\projectiles\\arrow_1.png", { 0, 0, 0, 0 }), damage, { 0, 0 }, velocity),
	target(target)
{
	//sprite.setScale({ 0.5,0.5 });
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
		GameManager::GetInstance()->SendMsg(m);

		m = new MSG;
		m->type = MsgType::DealDamage;
		m->deal_damage.by_whom = this;
		m->deal_damage.damage = damage;
		m->deal_damage.to_who = target;
		GameManager::GetInstance()->SendMsg(m);
	}
}

void Arrow::SendMSG(MSG* m)
{
	if (m->type == MsgType::Death && m->death.who_to_die == target)
	{
		MSG* m = new MSG;
		m->type = MsgType::Death;
		m->death.who_to_die = this;
		m->death.killer = this;
		GameManager::GetInstance()->SendMsg(m);
	}
}