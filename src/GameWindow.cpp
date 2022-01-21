//
// Created by Jan on 15/01/2022.
//

#include "GameWindow.h"
#include "TextureManager.h"
#include <iostream>

namespace
{
	/// \brief gets full path of picture. picture must be in the pictures folder of the project
	/// \param pictureFile name of picture
	/// \return string of path to picture
	std::string getResourcePath(std::string&& pictureFile)
	{
		return R"(..\..\assets\)" + std::move(pictureFile);
	}

}// namespace
GameWindow* GameWindow::getInstance(std::string&& title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	static GameWindow instance = GameWindow(std::move(title), xpos, ypos, width, height, fullscreen);
	return &instance;
}

GameWindow::GameWindow(std::string&& title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	SDL_WindowFlags sdlFlags = SDL_WINDOW_BORDERLESS;
	if (fullscreen)
	{
		sdlFlags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title.c_str(), xpos, ypos, width, height, SDL_WINDOW_SHOWN);
		if (window == nullptr)
		{
			std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
			errorMessage = "GameWindow Error: Could not create Window";
			status = Error;
			return;
		}
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (renderer == nullptr)
		{
			std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
			errorMessage = "GameWindow Error: Could not create Renderer";
			status = Error;
			return;
		}
		std::cout << "SDL initialised" << std::endl;
		status = Ok;
	}
	else
		status = Error;
}

void GameWindow::render()
{
	SDL_RenderPresent(renderer);
	SDL_RenderClear(renderer);
}

SDL_Renderer* GameWindow::getRenderer()
{
	return renderer;
}

GameWindow::~GameWindow()
{
	std::cout << "GameWindow Destructor" << std::endl;
	destroy();
}

void GameWindow::destroy()
{
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
