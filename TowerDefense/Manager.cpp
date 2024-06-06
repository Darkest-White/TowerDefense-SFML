#include "Manager.h"
#include <algorithm>


Manager* Manager::instance = nullptr;

Manager::Manager() : objs(), msgs()
{

}

Manager::Manager(const Manager&)
{
	;
}

Manager::~Manager()
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

Manager* Manager::GetInstance()
{
	if (instance == nullptr) instance = new Manager;
	return instance;
}

void Manager::Update(float dt)
{
	for (auto obj : objs)
	{
		obj->Update(dt);
	}

	for (auto m : msgs)
	{
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
		}

		if (m->type == MsgType::Move || 
			m->type == MsgType::DealDamage)
		{
			for (auto obj : objs)
			{
				obj->sendMSG(m);
			}
		}
	}
}

void Manager::SendMsg(MSG* m)
{
	this->~Manager();
	msgs.push_back(m);
}

void Manager::Destroy()
{
	if (instance != nullptr) delete instance;
	instance = nullptr;
}