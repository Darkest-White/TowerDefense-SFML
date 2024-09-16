#include "GameObject.h"

int GameObject::lastID = 0;

Texture* GameObject::LoadTexture(const char* filename, const IntRect& source_box)
{
	Texture* texture = new Texture();
	if (texture->loadFromFile(filename, source_box))
	{
		return texture;
	}
	else
	{
		delete texture;
		return nullptr;
	}
}

int GameObject::GetNewID()
{
	return ++lastID;
}

int GameObject::GetLastID()
{
	return lastID;
}

GameObject::GameObject(Vector2f position, float size_radius, Texture* texture, ObjType type)
	: position(position), size_radius(size_radius), sprite(*texture), type(type)
{
	Vector2u texture_size = sprite.getTexture()->getSize();
	sprite.setOrigin(texture_size.x / 2, texture_size.y / 2);
}

GameObject::GameObject(const GameObject&)
{

}

GameObject::~GameObject()
{

}

void GameObject::SetPosition(Vector2f new_pos)
{
	position = new_pos;
}

Vector2f GameObject::GetPosition()
{
	return position;
}

int GameObject::GetID()
{
	return id;
}

ObjType GameObject::GetType()
{
	return type;
}

void GameObject::Draw(RenderWindow& window)
{
	sprite.setPosition(position);
	window.draw(sprite);
}