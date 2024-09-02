#pragma once
#include"GameObject.h"
#include"MSG.h"
#include<iostream>
#include<list>
#include <algorithm>
using namespace std;
using namespace sf;

class Manager
{
private:
	static Manager* instance;	

	list<GameObject*> objs;
	list<MSG*> msgs;

	Manager();
	~Manager();

public:
	static Manager* GetInstance();
	static void Destroy();

	void Update(float dt);
	void SendMsg(MSG* m);
	void DrawObjects(RenderWindow& window);
};