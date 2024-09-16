#pragma once
#include"GameObject.h"
#include"MSG.h"
#include<iostream>
#include<list>
#include <algorithm>
using namespace std;
using namespace sf;

class GameManager
{
private:
	static GameManager* instance;	

	list<GameObject*> objs;
	list<MSG*> msgs;

	GameManager();
	~GameManager();

public:
	static GameManager* GetInstance();
	static void Destroy();

	void Update(float dt);
	void SendMsg(MSG* m);
	void DrawObjects(RenderWindow& window);
}; // чекнуть GetType