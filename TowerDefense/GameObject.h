#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;

struct MSG;

class GameObject
{
private:
	static int lastID;

protected:
	int id;
	Vector2f position;
	float size_radius;
	Sprite sprite;

	static Texture* LoadTexture(const char* filename, const IntRect& source_box);

public:
	static int GetNewID();
	static int GetLastID();

	GameObject(Vector2f position, float size_radius, Texture* texture);
	GameObject(const GameObject&);
	virtual ~GameObject();

	void SetPosition(Vector2f new_pos);
	Vector2f GetPosition();

	int GetID();

	virtual void Update(float dt) = 0;
	virtual void SendMSG(MSG* m) = 0;
	void Draw(RenderWindow& win);
};