#pragma once
#include "GameObject.h"

class Asteroid : public GameObject
{
protected:
	float speed;
	bool reappear;

public:
	static int activeInstances;

	Asteroid(int id);
	~Asteroid() override;

	void begin() override;
	void update() override;

	void drawWin();
	void drawLose();

	void destroy();
	void fall();
};