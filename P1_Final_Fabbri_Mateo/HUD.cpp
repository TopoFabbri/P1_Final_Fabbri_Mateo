#include "HUD.h"

HUD::HUD(Ship* ship)
{
	this->ship = ship;
	score = 0;
	lives = 3;
}

HUD::~HUD()
{
}

void HUD::begin()
{
	isActive = true;
}

void HUD::update()
{
	score = ship->getScore();
	lives = ship->getLives();
}

void HUD::draw()
{
	goToCoordinates({ 1, 0 });
	std::cout << "               ";
	goToCoordinates({ 1, 0 });
	std::cout << "Score: " << score;

	goToCoordinates({ getScreenWidth() - 17, 0 });
	std::cout << "                 ";
	goToCoordinates({ getScreenWidth() - 17, 0 });
	std::cout << "Asteroids left " << Asteroid::activeInstances;

	goToCoordinates({ getScreenWidth() / 2 - 1, 0 });
	std::cout << "      ";
	goToCoordinates({ getScreenWidth() / 2 - 1, 0 });
	for (int i = 0; i < lives; i++)
	{
		std::cout << static_cast<char>(3);
	}
}

void HUD::drawEnd(bool lost)
{
	goToCoordinates({ getScreenWidth() / 2 - 4, getScreenHeight() / 2 });
	if (lost)
		std::cout << "YOU LOSE!";
	else
		std::cout << "YOU WIN!";
}