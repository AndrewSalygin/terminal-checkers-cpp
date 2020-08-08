#ifndef DATA_H
#define DATA_H
#include <array>

// Тип пешек
enum Figure_Type
{
	E,
	Checker,
	King
};

// Цвет пешек
enum Figure_Color
{
	None,
	White,
	Black
};


struct Figure
{
	Figure_Type figure_type;
	Figure_Color figure_color;
};

struct Coordinate
{
	int y;
	int x;
};

typedef std::array<std::array<Figure, 8>, 8> desk;

#endif