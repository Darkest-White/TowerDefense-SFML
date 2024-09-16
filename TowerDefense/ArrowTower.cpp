#include "ArrowTower.h"
#include "Arrow.h"

ArrowTower::ArrowTower(Vector2f position, int level) :
	Tower(position, 50, LoadTexture("images\\towers\\ArrowTower_1.png", { 0, 0, 0, 0 }), level, 100 * level, 1, 300)
{
	//sprite.setScale({ 0.5,0.5 });
}

ArrowTower::~ArrowTower()
{

}

void ArrowTower::Update(float dt)
{
	if (cooldown_current > 0) cooldown_current -= dt;

	if (target_locked != nullptr)
	{
		if (!IsInActionRange(target_locked))
		{
			CheckEnemiesInRange();
			target_locked = nullptr;
		}
	}

	if (target_locked == nullptr && cooldown_current <= 0)
	{
		if (!enemies_in_range.empty())
		{
			auto closest_enemy = enemies_in_range.begin();
			for (auto e = closest_enemy; e != enemies_in_range.end(); e++)
			{
				if (CloserEnemy(*e, *closest_enemy)) closest_enemy = e;
			}
			target_locked = *closest_enemy;
		}
	}

	if (target_locked != nullptr && cooldown_current <= 0)
	{
		MSG* m = new MSG;
		m->type = MsgType::Create;
		m->create.new_object = new Arrow(position, 50, 20, target_locked);
		GameManager::GetInstance()->SendMsg(m);

		cooldown_current = cooldown_time;
	}
}

void ArrowTower::SendMSG(MSG* m)
{
	if (m->type == MsgType::Move && m->sender->GetType() == ObjType::Enemy)
	{
		AddEnemyIfInRange((Enemy*)m->sender);
	}
}

void ArrowTower::Action()
{

}