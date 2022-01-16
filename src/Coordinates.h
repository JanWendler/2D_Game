//
// Created by Jan on 16/01/2022.
//

#ifndef INC_2D_GAME_SRC_COORDINATES_H_
#define INC_2D_GAME_SRC_COORDINATES_H_

class Coordinates
{
public:
	Coordinates(int x, int y);
	void setX(int x) {xpos = x;}
	int getX() const {return xpos;}
	void setY(int y) {ypos = y;}
	int getY() const {return ypos;}

private:
	int xpos = 0;
	int ypos = 0;
};

#endif//INC_2D_GAME_SRC_COORDINATES_H_
