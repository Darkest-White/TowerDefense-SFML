#include<iostream>
#include<SFML/Graphics.hpp>
#include"Manager.h"
#include"ArrowTower.h"
using namespace std;
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(800, 800), "TowerDefense");

	Manager* MGR = Manager::GetInstance();

	MSG* msg = new MSG;
	msg->type = MsgType::Create;
	ArrowTower* a1 = new ArrowTower({ 200,300 }, 1);
	msg->create.new_object = a1;
	MGR->SendMsg(msg);

	msg = new MSG;
	msg->type = MsgType::Create;
	ArrowTower* a2 = new ArrowTower({ 600,300 }, 1);
	msg->create.new_object = a2;
	MGR->SendMsg(msg);

	msg = new MSG;
	msg->type = MsgType::Create;
	ArrowTower* a3 = new ArrowTower({ 700,700 }, 1);
	msg->create.new_object = a3;
	MGR->SendMsg(msg);

	a1->target_locked = a2;
	a2->target_locked = a3;
	a3->target_locked = a1;

	Clock clock;
	clock.restart();

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) window.close();
		}

		MGR->Update(clock.restart().asSeconds());

		window.clear(Color(255, 255, 255));
		MGR->DrawObjects(window);
		window.display();
	}

	return 0;
}