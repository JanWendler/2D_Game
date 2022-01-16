//
// Created by Jan on 15/01/2022.
//

#ifndef INC_2D_GAME_SRC_GAMEWINDOW_H_
#define INC_2D_GAME_SRC_GAMEWINDOW_H_

#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "Player.h"

class GameWindow
{
public:
	GameWindow() = default;

	/// \brief Initialises the window
	/// \param title name of the window
	/// \param xpos starting x pos
	/// \param ypos starting ypos
	/// \param width width of window
	/// \param height height of window
	/// \param fullscreen true = fullscreen \n false = borderless
	GameWindow(std::string&& title, int xpos, int ypos, int width, int height, bool fullscreen);

	~GameWindow();

	enum Status{
		Error = -0,
		Ok
	};

	/// \brief gets the status of the window
	/// \return Ok = window is initialised and working \n
	///			Error = window did not initialise properly. All attributes are nullptr.
	[[nodiscard]] Status getStatus() const {return status;}

	/// \brief gets the last error Message
	/// \return error message
	[[nodiscard]] std::string getError() const {return errorMessage;}

	void render();

	void update(int red, int green, int blue, int alpha);
	void update(std::string&& pictureName);
	void update(const Player& player);

private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Texture* texture = nullptr;

	Status status = Error;
	std::string errorMessage;

	/// \brief destroys all SDL objects
	void destroy();
};

#endif//INC_2D_GAME_SRC_GAMEWINDOW_H_
