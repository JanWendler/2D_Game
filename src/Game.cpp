//
// Created by Jan on 15/01/2022.
//

#include "Game.h"
#include "GameWindow.h"
#include "components/Components.h"
#include "components/TileComponent.h"
#include <SDL.h>
#include <iostream>

Game* Game::getInstance(std::string title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	static Game instance{std::move(title), xpos, ypos, width, height, fullscreen};
	return &instance;
}

Game::Game(std::string&& title, int xpos, int ypos, int width, int height, bool fullscreen)
	: player(manager.addEntity()), wall(manager.addEntity())
{
	window = GameWindow::getInstance(std::move(title), xpos, ypos, width, height, fullscreen);
	if (window->getStatus() == GameWindow::Error)
	{
		std::cout << window->getError() << std::endl;
		errorMessage = "Game Error: Could not create GameWindow";
		status = Error;
		isRunning = false;
	}
	else
	{
		status = Ok;
		isRunning = true;
	}
}
void Game::init()
{

	player.addComponent<TransformComponent>(2);
	player.addComponent<SpriteComponent>("../../assets/Man_walking.png", true);
	player.addComponent<KeyboardController>();
	player.addComponent<ColliderComponent>("Player");
	player.addGroup(groupPlayers);

	wall.addComponent<TransformComponent>(300.0f, 300.0f, 300, 20, 1);
	wall.addComponent<SpriteComponent>("../../assets/dirt.bmp");
	wall.addComponent<ColliderComponent>("Wall");
	wall.addGroup(groupMap);

	Map::LoadMap("../../assets/Level1.map", 32, 32);
}

void Game::run()
{
	const unsigned int FPS = 60;
	const unsigned int frameDelay = 1000 / FPS;
	unsigned int frameStart;
	unsigned int frameTime;
	if (status == Error)
	{
		std::cout << "Game Error: " << getError() << std::endl;
		return;
	}
	init();
	while (isRunning)
	{
		frameStart = SDL_GetTicks();
		handleEvents();
		update();
		render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}
}
void Game::handleEvents()
{
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update()
{
	manager.refresh();
	manager.update();

	for (auto cc: colliders)
	{
		Collision::AABB(player.getComponent<ColliderComponent>(), *cc);
	}
}
void Game::render()
{
	auto& tiles(manager.getGroup(groupMap));
	auto& players(manager.getGroup(groupPlayers));
	auto& enemies(manager.getGroup(groupEnemies));

	for (auto& t: tiles)
	{
		t->render();
	}
	for (auto& p: players)
	{
		p->render();
	}
	for (auto& e: enemies)
	{
		e->render();
	}
	window->render();
	if (window->getStatus() == GameWindow::Error)
	{
		isRunning = false;
	}
}
Game::~Game()
{
	std::cout << "Game Destructor" << std::endl;
	delete window;
}
void Game::addTile(int id, int x, int y)
{
	auto& tile(manager.addEntity());
	tile.addComponent<TileComponent>(x, y, 32, 32, id);
	tile.addGroup(groupMap);
}
