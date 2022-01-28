//
// Created by Jan on 28/01/2022.
//

#ifndef INC_2D_GAME_SRC_COMPONENTS_ANIMATION_H_
#define INC_2D_GAME_SRC_COMPONENTS_ANIMATION_H_

struct Animation
{
	int index;
	int frames;
	int speed;

	Animation() = default;
	Animation(int i, int f, int s):
		index(i), frames(f), speed(s)
	{}
};
#endif//INC_2D_GAME_SRC_COMPONENTS_ANIMATION_H_
