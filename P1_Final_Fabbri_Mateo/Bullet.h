#pragma once
#include "GameObject.h"

class Bullet : public GameObject
{
protected:
	float speed;
	bool fired;

public:
	Bullet(int id);
	~Bullet() override;

	void begin() override;
	void update() override;

	bool getFired();

	void fire(Vector2 pos);
	void destroy();
};