//
// Created by Jan on 16/01/2022.
//

#ifndef INC_2D_GAME_SRC_GAMEOBJECT_H_
#define INC_2D_GAME_SRC_GAMEOBJECT_H_

#include <SDL.h>
#include <string>
#include "Coordinates.h"
class GameObject
{
public:
	GameObject(int x, int y);
	void updatePosition(int dx, int dy);
	const Coordinates& getCoordinates() const {return cor;}
private:
	Coordinates cor;
};

#endif//INC_2D_GAME_SRC_GAMEOBJECT_H_
