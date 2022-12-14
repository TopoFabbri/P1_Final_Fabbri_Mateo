#include "GameObject.h"

GameObject::GameObject()
{
	pos = { 5, 5 };
	boxCollider = { 3, 3 };
	color = Color::WHITE;
}

GameObject::~GameObject()
{
}

void GameObject::draw()
{
	if (isActive)
	{
		erase();
		Vector2 cursor = { pos.x - boxCollider.x / 2, pos.y - boxCollider.y / 2 };

		setForegroundColor(color);

		for (int i = 0; i < boxCollider.y; i++)
		{
			goToCoordinates(cursor);

			for (int j = 0; j < boxCollider.x; j++)
			{
				if (cursor.y > 2)
					std::cout << mesh[static_cast<int>(boxCollider.x * i + j)];
			}

			cursor.y++;
		}

		setForegroundColor(Color::WHITE);
	}
}

void GameObject::erase()
{
	Vector2 cursor = { exPos.x - boxCollider.x / 2, exPos.y - boxCollider.y / 2 };

	for (int i = 0; i < boxCollider.y; i++)
	{
		goToCoordinates(cursor);

		for (int j = 0; j < boxCollider.x; j++)
		{
			if (cursor.y > 2)
				std::cout << " ";
		}

		cursor.y++;
	}
}

void GameObject::collideEffect()
{
	pos = exPos;
}

bool GameObject::checkCollision(Vector2 pos, Vector2 boxCollider, int id)
{
	if (this->id == id)
		return false;

	Vector2 a1 = { this->pos.x - this->boxCollider.x / 2,
					this->pos.y - this->boxCollider.y / 2 };

	Vector2 a2 = { this->pos.x + this->boxCollider.x / 2,
					this->pos.y + this->boxCollider.y / 2 };

	Vector2 b1 = { pos.x - boxCollider.x / 2,
					pos.y - boxCollider.y / 2 };

	Vector2 b2 = { pos.x + boxCollider.x / 2,
					pos.y + boxCollider.y / 2 };

	if (a2.x < b1.x || a1.x > b2.x || a2.y <= b1.y || a1.y >= b2.y)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool GameObject::collideWall(Vector2 map)
{
	Vector2 upLeft = { this->pos.x - this->boxCollider.x / 2,
				this->pos.y - this->boxCollider.y / 2 };

	Vector2 lowRight = { this->pos.x + this->boxCollider.x / 2,
					this->pos.y + this->boxCollider.y / 2 };

	if (upLeft.x <= 1)
		return true;

	if (lowRight.x > map.x)
		return true;

	return false;
}

void GameObject::reposition()
{
	pos = { static_cast<float>(rand() % (static_cast<int>(getScreenWidth()) - 2) + 1),
static_cast<float>(rand() % (static_cast<int>(getScreenHeight()) - 2) + 1) };
}

Vector2 GameObject::getPos()
{
	return pos;
}

Vector2 GameObject::getCollider()
{
	return boxCollider;
}

int GameObject::getId()
{
	return id;
}

void GameObject::setPos(Vector2 pos)
{
	this->pos = pos;
}