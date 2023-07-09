#include "Asteroid.h"

int Asteroid::activeInstances = 0;

Asteroid::Asteroid(int id)
{
	activeInstances++;
	this->id = id;
	boxCollider = { 3, 3 };
	mesh = "/-\\|+|\\-/";
	color = Color::BROWN;
	reappear = true;
	speed = 0;
}

Asteroid::~Asteroid()
{
}

void Asteroid::begin()
{
	if (reappear)
	{
		isActive = true;

		pos.x = static_cast<float>(rand() % static_cast<int>(getScreenWidth()));
		speed = static_cast<float>(rand() % 10 + 1) / 100;
		pos.y = -1;
		erase();
	}
}

void Asteroid::update()
{
	if (!isActive)
		begin();

	exPos = pos;
	fall();
}

void Asteroid::destroy()
{
	reappear = false;
	isActive = false;
	activeInstances--;
}

void Asteroid::fall()
{
	if (isActive)
		pos.y += speed;
}