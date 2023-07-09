#include "Ship.h"

Ship::Ship(Vector2 pos)
{
	isActive = false;
	this->pos = pos;
	mesh = "  \30   (+) \30/ \\\30";
	boxCollider = { 5, 3 };
	color = Color::WHITE;
	id = 0;
	speed = 1;
	lives = 3;
	score = 0;

	for (int i = 0; i < bulQty; i++)
		bul[i] = new Bullet(11 + i);
}

Ship::~Ship()
{
	for (int i = 0; i < bulQty; i++)
		delete bul[i];
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

Base* Ship::getBullet(int i)
{
	return bul[i];
}

void Ship::moveLeft()
{
	pos.x -= speed;
}

void Ship::moveRight()
{
	pos.x += speed;
}

void Ship::fire()
{
	for (int i = 0; i < bulQty; i++)
	{
		if (!dynamic_cast<Bullet*>(bul[i])->getFired())
		{
			dynamic_cast<Bullet*>(bul[i])->fire(pos);
			break;
		}
	}
}

void Ship::scoreUp()
{
	score++;
}

void Ship::loseLife()
{
	lives--;
}