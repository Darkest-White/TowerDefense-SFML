#include "MSG.h"

struct Vector2
{
	float a, b;
};

class GameObject
{
protected:
	int id;
	Vector2 position;
	float size_radius;

public:
	static int GetNewID();

	GameObject();
	GameObject(const GameObject&);
	virtual ~GameObject();

	void SetPosition(Vector2 new_pos);
	Vector2 GetPosition();

	int GetID();

	virtual void Update(float dt) = 0;
	virtual void sendMSG(MSG m) = 0;
	void Draw();
};