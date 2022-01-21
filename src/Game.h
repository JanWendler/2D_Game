//
// Created by Jan on 15/01/2022.
//

#ifndef INC_2D_GAME_SRC_GAME_H_
#define INC_2D_GAME_SRC_GAME_H_

#include "Error.h"
#include "GameWindow.h"
#include "Map.h"
#include "EntityComponentSystem.h"
#include <string>

class ColliderComponent;

class Game
{
public:
	static Game* getInstance(std::string&& title = "", int xpos = 0, int ypos = 0, int width = 800, int height = 0, bool fullscreen = false);
	Game(Game& other) = delete;
	void operator=(const Game&) = delete;
	~Game();

	void run();
	static SDL_Event event;
	static std::vector<ColliderComponent*> colliders;

protected:
	Game(std::string&& title, int xpos, int ypos, int width, int height, bool fullscreen);

	enum Status
	{
		Error = -0,
		Ok
	};

	/// \brief gets the status of the object
	/// \return Ok = everything is fine \n
	///			Error = Something went wrong. Call getError for more details.
	[[nodiscard]] Status getStatus() const
	{
		return status;
	}

	/// \brief gets the last error Message
	/// \return error message
	[[nodiscard]] std::string getError() const
	{
		return errorMessage;
	}

	[[nodiscard]] bool running() const
	{
		return isRunning;
	}
	void handleEvents();
	void update();
	void render();

private:
	Status status = Error;
	std::string errorMessage;
	bool isRunning = false;
	GameWindow* window;
	Map* map;
	Manager manager;
	Entity& player;
	Entity& wall;
	Entity& tile0;
	Entity& tile1;
	Entity& tile2;
};

#endif//INC_2D_GAME_SRC_GAME_H_
