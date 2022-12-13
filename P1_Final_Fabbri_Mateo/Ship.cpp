#include "Ship.h"

Ship::Ship(Vector2 pos)
{
	isActive = false;
	this->pos = pos;
	mesh = "  A   (+) A/ \\A";
	boxCollider = { 5, 3 };
	color = Color::WHITE;
	id = 0;
	speed = 1;
	lives = 3;
	score = 0;
}

Ship::~Ship()
{
}

void Ship::begin()
{
	isActive = true;
}

void Ship::update()
{
	exPos = pos;
}

int Ship::getScore()
{
	return score;
}

int Ship::getLives()
{
	return lives;
}

void Ship::moveLeft()
{
	pos.x -= speed;
}

void Ship::moveRight()
{
	pos.x += speed;
}

void Ship::scoreUp()
{
	score++;
}