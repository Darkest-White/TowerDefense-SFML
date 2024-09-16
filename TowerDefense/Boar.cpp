#include "Boar.h"

Boar::Boar(float max_hp, float velocity, int damage_to_player, int loot, Path* path) :
	Enemy(path->GetPoint(0), 40, LoadTexture("images\\enemies\\boar_1.png", { 0, 0, 0, 0 }), max_hp, velocity, damage_to_player, loot, path)
{

}

void Boar::Update(float dt)
{
	bool point_reached = Move(dt);

	if (point_reached)
	{
		if (path->isLastPoint(path_point_index))
		{
			GameManager* mgr = GameManager::GetInstance();

			MSG* m = new MSG;
			m->type = MsgType::DamageToPlayer;
			m->damage_to_player.by_whom = this;
			m->damage_to_player.damage = this->damage_to_player;
			mgr->SendMsg(m);

			m = new MSG;
			m->type = MsgType::Death;
			m->death.killer = this;
			m->death.who_to_die = this;
			mgr->SendMsg(m);
		}
		else 
		{
			path_point_index++;
		}
	}
}

void Boar::SendMSG(MSG* m)
{
	if (m->type == MsgType::DealDamage && m->deal_damage.to_who == this)
	{
		current_hp -= m->deal_damage.damage;
		if (current_hp <= 0)
		{
			MSG* msg = new MSG;
			msg->type = MsgType::Death;
			msg->death.who_to_die = this;
			msg->death.killer = m->deal_damage.by_whom;
			GameManager::GetInstance()->SendMsg(msg);
		}
	}
}