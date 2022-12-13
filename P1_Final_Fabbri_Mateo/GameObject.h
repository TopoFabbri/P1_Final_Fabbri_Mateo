#pragma once
#include "AwesomeLibrary.h"
#include "Base.h"

class GameObject : public Base
{
protected:
	Vector2 exPos;
	Vector2 pos;
	Vector2 boxCollider;
	std::string mesh;
	Color color;
	int id;

public:
	GameObject();
	~GameObject() override;

	void draw() override;

	void erase();
	void collideEffect();
	bool checkCollision(Vector2 pos, Vector2 boxCollider, int id);
	bool collideWall(Vector2 map);

	void reposition();
	Vector2 getPos();
	Vector2 getCollider();
	int getId();

	void setPos(Vector2 pos);
};