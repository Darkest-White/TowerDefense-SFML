#include "GameManager.h"
//!!!!!!!!!!!!!!!
#include"Enemy.h"
#include"Boar.h"
#include"Tower.h"
#include"ArrowTower.h"

GameManager* GameManager::instance = nullptr;

GameManager::GameManager() : objs(), msgs()
{

}

GameManager::~GameManager()
{
	for (auto x : objs)
	{
		delete x;
	}
	objs.clear();

	for (auto x : msgs)
	{
		delete x;
	}
	msgs.clear();
}

GameManager* GameManager::GetInstance()
{
	if (instance == nullptr) instance = new GameManager();
	return instance;
}

void GameManager::Update(float dt)
{
	spawnEnemy(dt);

	for (auto obj : objs)
	{
		obj->Update(dt);
	}

	MSG* m;
	while (!msgs.empty())
	{
		m = msgs.front();
		msgs.pop_front();
		switch (m->type)
		{
		case MsgType::Death:
		{
			auto res = find(objs.begin(), objs.end(), m->death.who_to_die);
			delete* res;
			objs.erase(res);
		} break;

		case MsgType::Create:
		{
			objs.push_back(m->create.new_object);
		} break;

		case MsgType::DamageToPlayer:
		{
			cout << "Player took " << m->damage_to_player.damage << " points of damage" << endl;
		} break;
		}

		if (m->type == MsgType::Move ||
			m->type == MsgType::DealDamage ||
			m->type == MsgType::Death)
		{
			for (auto obj : objs)
			{
				obj->SendMSG(m);
			}
		}
		delete m;
	}
}

void GameManager::SendMsg(MSG* m)
{
	msgs.push_back(m);
}

void GameManager::DrawObjects(RenderWindow& window)
{
	for (auto obj : objs)
	{
		obj->Draw(window);
	}
}

void GameManager::Destroy()
{
	if (instance) delete instance;
	instance = nullptr;
}

void GameManager::spawnEnemy(float dt)
{
	static float cooldown = 0;
	if (cooldown > 0) cooldown -= dt;
	if (Keyboard::isKeyPressed(Keyboard::Key::Space) && cooldown <= 0)
	{
		cooldown = 0.3;
		MSG* msg = new MSG;
		msg->type = MsgType::Create;
		Boar* b = new Boar(100, 170, 1, 10, PathManager::GetInstance()->GetPath(0));
		msg->create.new_object = b;
		SendMsg(msg);
	}
}