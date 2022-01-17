//
// Created by Jan on 15/01/2022.
//

#ifndef INC_2D_GAME_SRC_GAME_H_
#define INC_2D_GAME_SRC_GAME_H_

#include "Error.h"
#include "GameWindow.h"
#include "GameObjectController.h"
#include "Map.h"
#include <string>

class Game
{
public:
	static Game* getInstance(std::string&& title, int xpos, int ypos, int width, int height, bool fullscreen);
	Game(Game& other) = delete;
	void operator=(const Game&) = delete;
	~Game();

	void run();

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
	GameObjectController* player;
	Map* map;
};

#endif//INC_2D_GAME_SRC_GAME_H_
