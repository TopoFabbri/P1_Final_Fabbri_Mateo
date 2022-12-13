#pragma once
#include "GameObject.h"

class Ship : public GameObject
{
protected:
	float speed;
	int lives;
	int score;

public:
	Ship(Vector2 pos);
	~Ship() override;

	void begin() override;
	void update() override;

	int getScore();
	int getLives();

	void moveLeft();
	void moveRight();

	void scoreUp();
};