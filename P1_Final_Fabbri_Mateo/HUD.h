#pragma once
#include "Base.h"
#include "Ship.h"
#include "Asteroid.h"

class HUD : public Base
{
protected:
	int score;
	int lives;
	Ship* ship;

public:
	HUD(Ship* ship);
	~HUD() override;

	void begin() override;
	void update() override;
	void draw() override;
};
