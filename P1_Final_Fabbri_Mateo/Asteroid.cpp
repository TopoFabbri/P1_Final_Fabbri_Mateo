#include "Asteroid.h"

Asteroid::Asteroid(int id)
{
	this->id = id;
	boxCollider = { 3, 3 };
	mesh = "/-\\|+|\\-/";
	color = Color::BROWN;
}

Asteroid::~Asteroid()
{
}

void Asteroid::begin()
{
	isActive = true;

	pos.x = static_cast<float>(rand() % static_cast<int>(getScreenWidth()));
	speed = static_cast<float>(rand() % 10 + 1) / 100;
	pos.y = -1;
	erase();
}

void Asteroid::update()
{
	if (!isActive)
		begin();

	exPos = pos;
	fall();
}

void Asteroid::fall()
{
	pos.y += speed;
}