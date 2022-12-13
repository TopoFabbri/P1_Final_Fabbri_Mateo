#include "Game.h"

Game::Game()
{
	isActive = false;
	ship = new Ship({ getScreenWidth() / 2, getScreenHeight() - 2 });
	hud = new HUD(dynamic_cast<Ship*>(ship));

	for (int i = 0; i < astQty; i++)
	{
		asteroids[i] = new Asteroid(1 + i);
	}
}

Game::~Game()
{
	delete ship;
	delete hud;

	for (int i = 0; i < astQty; i++)
	{
		delete asteroids[i];
	}
}

void Game::loop()
{
	do
	{
		if (!isActive)
			begin();

		update();

		draw();
	} while (isActive);
}

void Game::begin()
{
	isActive = true;
	ship->begin();
	hud->begin();
}

void Game::update()
{
	ship->update();
	hud->update();

	for (int i = 0; i < astQty; i++)
	{
		asteroids[i]->update();

		if (dynamic_cast<Asteroid*>(asteroids[i])->getPos().y > dynamic_cast<Ship*>(ship)->getPos().y)
		{
			dynamic_cast<Ship*>(ship)->scoreUp();
			asteroids[i]->setActive(false);
		}
	}

	input();
}

void Game::draw()
{
	dynamic_cast<Ship*>(ship)->erase();
	ship->draw();
	hud->draw();

	for (int i = 0; i < astQty; i++)
	{
		dynamic_cast<Asteroid*>(asteroids[i])->erase();
		asteroids[i]->draw();
	}
	drawFrame({ 0, 1 }, { getScreenWidth() - 1, getScreenHeight() - 1 });
}

void Game::input()
{
	int key = getKey(false);

	if (key == 'a')
		dynamic_cast<Ship*>(ship)->moveLeft();

	if (key == 'd')
		dynamic_cast<Ship*>(ship)->moveRight();
}