#include "GameObject.h"

class Tower : public GameObject
{
protected:
	int level;
	int cost;

	float cooldown_time;
	float cooldown_current;
	float action_range;

public:
	Tower();
	Tower(const Tower&);
	virtual ~Tower();
	virtual void Action() = 0;
};