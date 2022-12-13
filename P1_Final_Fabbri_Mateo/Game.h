#pragma once
#include "AwesomeLibrary.h"
#include "Base.h"
#include "Ship.h"
#include "Asteroid.h"
#include "HUD.h"

class Game : public Base
{
protected:
	static const int astQty = 10;

	Base* ship;
	Base* hud;
	Base* asteroids[astQty];

public:
	Game();
	~Game() override;

	void loop();

	void begin() override;
	void update() override;
	void draw() override;

	void input();
};