#pragma once
#include"GameObject.h"
#include"MSG.h"
#include<list>
using namespace std;

class Manager
{
private:
	static Manager* instance;	

	list<GameObject*> objs;
	list<MSG*> msgs;

	Manager();
	Manager(const Manager&);
	~Manager();

public:
	static Manager* GetInstance();
	static void Destroy();

	void Update(float dt);
	void SendMsg(MSG* m);
};

