#include "Bullet.h"

Bullet::Bullet(int id)
{
	this->id = id;
	boxCollider = { 1, 1 };
	color = Color::RED;
	mesh = static_cast<char>(179);
	fired = false;
	speed = .4f;
}

Bullet::~Bullet()
{
}

void Bullet::begin()
{
	isActive = true;
}

void Bullet::update()
{
	exPos = pos;
	if (fired)
		pos.y -= speed;

	if (pos.y < 2)
		fired = false;
}

bool Bullet::getFired()
{
	return fired;
}

void Bullet::fire(Vector2 pos)
{
	pos.y -= 2;
	this->pos = pos;
	fired = true;
}

void Bullet::destroy()
{
	fired = false;
}