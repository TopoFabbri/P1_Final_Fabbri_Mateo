#pragma once
#include "GameObject.h"

class Asteroid : public GameObject
{
protected:
	float speed;

public:
	Asteroid(int id);
	~Asteroid() override;

	void begin() override;
	void update() override;

	void fall();
};