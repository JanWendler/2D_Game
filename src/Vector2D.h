//
// Created by Jan on 20/01/2022.
//

#ifndef INC_2D_GAME_SRC_VECTOR2D_H_
#define INC_2D_GAME_SRC_VECTOR2D_H_
#include <iostream>
class Vector2D
{
public:

	float x;
	float y;
	Vector2D();
	Vector2D(float x, float y);

	Vector2D& add(const Vector2D& vec);

	friend Vector2D& operator+(Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator-(Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator*(Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator/(Vector2D& v1, const Vector2D& v2);

	Vector2D& operator+=(const Vector2D& vec);
	Vector2D& operator-=(const Vector2D& vec);
	Vector2D& operator*=(const Vector2D& vec);
	Vector2D& operator/=(const Vector2D& vec);

	friend std::ostream& operator<<(std::ostream& ostream, const Vector2D& vec);

	~Vector2D() = default;
private:

};

#endif//INC_2D_GAME_SRC_VECTOR2D_H_
