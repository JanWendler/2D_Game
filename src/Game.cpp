//
// Created by Jan on 15/01/2022.
//

#include "Game.h"
#include "GameWindow.h"
#include "components/Components.h"
#include "components/TileComponent.h"
#include <SDL.h>
#include <iostream>

SDL_Event Game::event;
std::vector<ColliderComponent*> Game::colliders;

Game* Game::getInstance(std::string&& title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	static Game instance = Game(std::move(title), xpos, ypos, width, height, fullscreen);
	return &instance;
}

Game::Game(std::string&& title, int xpos, int ypos, int width, int height, bool fullscreen)
	: player(manager.addEntity()), wall(manager.addEntity()), tile0(manager.addEntity()), tile1(manager.addEntity()), tile2(manager.addEntity())
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

	tile0.addComponent<TileComponent>(200, 200, 32, 32, 0);
	tile1.addComponent<TileComponent>(250, 250, 32, 32, 1);
	tile1.addComponent<ColliderComponent>("dirt");
	tile2.addComponent<TileComponent>(300, 300, 32, 32, 2);
	tile2.addComponent<ColliderComponent>("grass");

	player.addComponent<TransformComponent>();
	player.addComponent<SpriteComponent>("../../assets/Man.png");
	player.addComponent<KeyboardController>();
	player.addComponent<ColliderComponent>("Player");

	wall.addComponent<TransformComponent>(300.0f, 300.0f, 300, 20, 1);
	wall.addComponent<SpriteComponent>("../../assets/dirt.bmp");
	wall.addComponent<ColliderComponent>("Wall");

	map = new Map();
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

	for(auto cc: colliders)
	{
		Collision::AABB(player.getComponent<ColliderComponent>(),*cc);
	}

}

void Game::render()
{
	//map->render();
	manager.render();
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