//
// Created by Jan on 15/01/2022.
//

#include "Game.h"
#include <SDL.h>
#include <iostream>

Game::Game(std::string&& title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	window = new GameWindow(std::move(title), xpos, ypos, width, height, fullscreen);
	player = new Player();
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

Game* Game::getInstance(std::string&& title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	static Game instance = Game(std::move(title), xpos, ypos, width, height, fullscreen);
	return &instance;
}

void Game::handleEvents()
{
	SDL_Event event;
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

void Game::run()
{
	if (status == Error)
	{
		std::cout << "Game Error: " << getError() << std::endl;
		return;
	}
	while(isRunning)
	{
		update();
		render();
	}

}
Game::~Game()
{
	std::cout << "Game Destructor" << std::endl;
	delete window;
}
void Game::update()
{
	handleEvents();
	player->update();
	window->update(*player);
	//window->update("Man.jpg");
	if(window->getStatus() == GameWindow::Error)
	{
		isRunning = false;
	}
}
void Game::render()
{
	window->render();
	if(window->getStatus() == GameWindow::Error)
	{
		isRunning = false;
	}
}
