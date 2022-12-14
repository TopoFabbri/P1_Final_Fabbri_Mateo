#pragma once
#include "GameObject.h"
#include "Bullet.h"

class Ship : public GameObject
{
protected:
	static const int bulQty = 10;
	float speed;
	int lives;
	int score;

	Base* bul[bulQty];

public:
	Ship(Vector2 pos);
	~Ship() override;

	void begin() override;
	void update() override;

	int getScore();
	int getLives();
	Base* getBullet(int i);

	void moveLeft();
	void moveRight();
	void fire();

	void scoreUp();
	void loseLife();
};