#include<iostream>
#include<SFML/Graphics.hpp>
#include "GameManager.h"
#include"ArrowTower.h"
#include"Path.h"
using namespace std;
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(1600, 900), "TowerDefense");

	GameManager* MGR = GameManager::GetInstance();

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

	Path* path = new Path(4);
	path->SetPoint(0, { 100, 800 });
	path->SetPoint(1, { 100, 100 });
	path->SetPoint(2, { 1500, 100 });
	path->SetPoint(3, { 1500, 800 });

	PathManager::GetInstance()->AddPath(path);

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