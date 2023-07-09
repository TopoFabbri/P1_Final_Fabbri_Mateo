#include "Game.h"

Game::Game()
{
	lost = false;
	isActive = false;
	ship = new Ship({ getScreenWidth() / 2, getScreenHeight() - 2 });
	hud = new HUD(dynamic_cast<Ship*>(ship));

	for (int i = 0; i < astQty; i++)
		asteroids[i] = new Asteroid(1 + i);

	for (int i = 0; i < bulQty; i++)
		bul[i] = dynamic_cast<Ship*>(ship)->getBullet(i);
}

Game::~Game()
{
	delete ship;
	delete hud;

	for (int i = 0; i < astQty; i++)
		delete asteroids[i];

	clearScreen();
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

	for (int i = 0; i < bulQty; i++)
		bul[i]->begin();
}

void Game::update()
{
	ship->update();
	hud->update();

	for (int i = 0; i < bulQty; i++)
		bul[i]->update();

	for (int i = 0; i < astQty; i++)
	{
		asteroids[i]->update();

		if (dynamic_cast<Asteroid*>(asteroids[i])->getPos().y > dynamic_cast<Ship*>(ship)->getPos().y)
		{
			asteroids[i]->setActive(false);
		}
	}

	input();
	collisions();
}

void Game::draw()
{
	dynamic_cast<Ship*>(ship)->erase();
	ship->draw();
	hud->draw();

	for (int i = 0; i < bulQty; i++)
	{
		if (dynamic_cast<Bullet*>(bul[i])->getFired())
		{
			dynamic_cast<Bullet*>(bul[i])->erase();
			bul[i]->draw();
		}
	}

	for (int i = 0; i < astQty; i++)
	{
		dynamic_cast<Asteroid*>(asteroids[i])->erase();
		asteroids[i]->draw();
	}

	drawFrame({ 0, 1 }, { getScreenWidth() - 1, getScreenHeight() - 1 });

	if (isGameOver())
	{
		dynamic_cast<HUD*>(hud)->drawEnd(lost);

		getKey(true);

		isActive = false;
	}
}

void Game::input()
{
	int key = getKey(false);

	if (key == 'a')
		dynamic_cast<Ship*>(ship)->moveLeft();

	if (key == 'd')
		dynamic_cast<Ship*>(ship)->moveRight();

	if (key == ' ')
		dynamic_cast<Ship*>(ship)->fire();
}

void Game::collisions()
{
	if (dynamic_cast<Ship*>(ship)->collideWall({ getScreenWidth(), getScreenHeight() }))
		dynamic_cast<Ship*>(ship)->collideEffect();
	
	for (int i = 0; i < astQty; i++)
	{
		if (dynamic_cast<Asteroid*>(asteroids[i])->collideWall({ getScreenWidth(), getScreenHeight() }))
			asteroids[i]->setActive(false);
	}

	for (int i = 0; i < astQty; i++)
	{
		if (dynamic_cast<Ship*>(ship)->checkCollision(dynamic_cast<Asteroid*>(asteroids[i])->getPos(),
			dynamic_cast<Asteroid*>(asteroids[i])->getCollider(),
			dynamic_cast<Asteroid*>(asteroids[i])->getId()))
		{
			asteroids[i]->setActive(false);
			dynamic_cast<Ship*>(ship)->loseLife();
		}
	}

	for (int i = 0; i < astQty; i++)
	{
		for (int j = 0; j < bulQty; j++)
		{
			if (dynamic_cast<Bullet*>(bul[j])->checkCollision(dynamic_cast<Asteroid*>(asteroids[i])->getPos(),
				dynamic_cast<Asteroid*>(asteroids[i])->getCollider(),
				dynamic_cast<Asteroid*>(asteroids[i])->getId()) &&
				dynamic_cast<Bullet*>(bul[j])->getFired() && asteroids[i]->getActive())
			{
				dynamic_cast<Asteroid*>(asteroids[i])->destroy();
				dynamic_cast<Asteroid*>(asteroids[i])->erase();
				dynamic_cast<Bullet*>(bul[j])->destroy();
				dynamic_cast<Bullet*>(bul[j])->erase();
				dynamic_cast<Ship*>(ship)->scoreUp();
			}
		}
	}
}

bool Game::isGameOver()
{
	if (dynamic_cast<Ship*>(ship)->getLives() <= 0)
	{
		lost = true;
		return true;
	}

	if (dynamic_cast<Ship*>(ship)->getScore() >= astQty)
		return true;

	return false;
}