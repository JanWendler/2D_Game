//
// Created by Jan on 15/01/2022.
//

#include <iostream>
#include "GameWindow.h"
namespace {
	/// \brief gets full path of picture. picture must be in the pictures folder of the project
	/// \param pictureFile name of picture
	/// \return string of path to picture
	std::string getResourcePath(std::string&& pictureFile)
	{
		return R"(..\..\assets\)" + std::move(pictureFile);
	}
}

GameWindow::GameWindow(std::string&& title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	SDL_WindowFlags sdlFlags = SDL_WINDOW_BORDERLESS;
	if(fullscreen)
	{
		sdlFlags = SDL_WINDOW_FULLSCREEN;
	}
	if(SDL_Init(SDL_INIT_VIDEO) == 0)
	{
		window = SDL_CreateWindow(title.c_str(),xpos,ypos,width,height,SDL_WINDOW_SHOWN);
		if(window == nullptr)
		{
			std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
			errorMessage = "GameWindow Error: Could not create Window";
			status = Error;
			destroy();
			return;
		}
		renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if(renderer == nullptr)
		{
			std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
			errorMessage = "GameWindow Error: Could not create Renderer";
			status = Error;
			destroy();
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
}

void GameWindow::update(int red, int green, int blue, int alpha)
{
	if(SDL_RenderClear(renderer)!= 0)
	{
		std::cout << "SDL_RenderClear Error: " << SDL_GetError() << std::endl;
		return;
	}
	if(SDL_SetRenderDrawColor(renderer,red, green, blue, alpha) != 0)
	{
		std::cout << "SDL_SetRenderDrawColor Error: " << SDL_GetError() << std::endl;
		return;
	}
}

void GameWindow::update(std::string&& pictureName)
{
	if(SDL_RenderClear(renderer)!= 0)
	{
		std::cout << "SDL_RenderClear Error: " << SDL_GetError() << std::endl;
		return;
	}
	std::string imagePath = getResourcePath("picture.bmp");
	surface = SDL_LoadBMP(imagePath.c_str());
	if (surface == nullptr)
	{
		std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
		destroy();
		return;
	}
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	if (texture == nullptr)
	{
		std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
		destroy();
		return;
	}
	if(SDL_RenderCopy(renderer, texture, NULL, NULL) != 0)
	{
		std::cout << "SDL_RenderCopy Error: " << SDL_GetError() << std::endl;
		return;
	}
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