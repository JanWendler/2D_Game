//
// Created by Jan on 16/01/2022.
//

#ifndef INC_2D_GAME_SRC_GAMEOBJECTCONTROLLER_H_
#define INC_2D_GAME_SRC_GAMEOBJECTCONTROLLER_H_

#include "GameObject.h"
#include "GameObjectView.h"
class GameObjectController
{
public:
	GameObjectController(std::string name, const std::string& texturePath, SDL_Renderer* renderer);
	void update(int x, int y);
	void render();
private:
	std::string name;
	GameObject* object;
	GameObjectView* view;

};

#endif//INC_2D_GAME_SRC_GAMEOBJECTCONTROLLER_H_
