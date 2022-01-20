//
// Created by Jan on 15/01/2022.
//

#include "Game.h"
#include "components/Components.h"
#include "components/TransformComponent.h"
#include "GameWindow.h"
#include <SDL.h>
#include <iostream>

SDL_Event Game::event;

Game* Game::createInstance(std::string&& title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	static Game instance {std::move(title), xpos, ypos, width, height, fullscreen};
	return &instance;
}

Game::Game(std::string&& title, int xpos, int ypos, int width, int height, bool fullscreen):
	  player(manager.addEntity())
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
	player.addComponent<TransformComponent>();
	player.addComponent<SpriteComponent>("../../assets/Man.png");
	player.addComponent<KeyboardController>();
	map = new Map();
}

void Game::run()
{
	const unsigned int FPS = 60;
	const unsigned int frameDelay = 1000/FPS;
	unsigned int frameStart;
	unsigned int frameTime;
	if (status == Error)
	{
		std::cout << "Game Error: " << getError() << std::endl;
		return;
	}
	while(isRunning)
	{
		frameStart = SDL_GetTicks();
		handleEvents();
		update();
		render();

		frameTime = SDL_GetTicks() - frameStart;

		if(frameDelay > frameTime)
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
	if(player.getComponent<TransformComponent>().position.x >= 100)
	{
		player.getComponent<SpriteComponent>().setTexture("../../assets/Enemy.png");
	}
	else
	{
		player.getComponent<SpriteComponent>().setTexture("../../assets/Man.png");
	}
}

void Game::render()
{
	map->render();
	manager.render();
	window->render();
	if(window->getStatus() == GameWindow::Error)
	{
		isRunning = false;
	}
}
Game::~Game()
{
	std::cout << "Game Destructor" << std::endl;
	delete window;
}