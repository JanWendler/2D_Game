//
// Created by Jan on 16/01/2022.
//

#ifndef INC_2D_GAME_SRC_PLAYER_H_
#define INC_2D_GAME_SRC_PLAYER_H_

#include <string>
class Player
{
public:
	Player();
	void update();
	[[nodiscard]] std::string getTextureName() const
	{
		return textureName;
	}
	[[nodiscard]] int getX() const
	{
		return x;
	}
	[[nodiscard]] int getY() const
	{
		return y;
	}

private:
	int x = 0;
	int y = 0;
	std::string textureName = "Man.bmp";
};

#endif//INC_2D_GAME_SRC_PLAYER_H_
