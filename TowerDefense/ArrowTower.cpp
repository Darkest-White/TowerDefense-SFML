#include "ArrowTower.h"
#include "Arrow.h"
#include "Manager.h"

ArrowTower::ArrowTower(Vector2f position, int level) :
	Tower(position, 50, LoadTexture("images\\towers\\ArrowTower_1.png", { 0,0,0,0 }), level, 100 * level, 1, 200)
{

}

ArrowTower::~ArrowTower()
{

}

void ArrowTower::Update(float dt)
{
	if (cooldown_current > 0)
	{
		cooldown_current = (cooldown_current < dt) ? 0 : cooldown_current - dt;
	}

	if (target_locked != nullptr && cooldown_current == 0)
	{
		MSG* m = new MSG;
		m->type = MsgType::Create;
		m->create.new_object = new Arrow(position, 10, 200, target_locked);
		Manager::GetInstance()->SendMsg(m);

		cooldown_current = cooldown_time;
	}
}

void ArrowTower::SendMSG(MSG* m)
{

}

void ArrowTower::Action()
{

}