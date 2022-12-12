#pragma once
#include"../../Object/Object.h"

struct Rect : Object
{
	DECLARE_CLASS_INFO(Object)
#pragma region f/p
private:
	int x = 0;
	int y = 0;
	int width = 0;
	int height = 0;
#pragma endregion f/p
#pragma region constructor
public:
	Rect() = default;
	Rect(int _x, int _y, int _width, int _height);
	Rect(const Rect& _copy);
#pragma endregion constructor
#pragma region methods
public:
	int X() const;
	int Y() const;
	int Width() const;
	int Height() const;
#pragma endregion methods
};