#pragma once
#include "Figure.h"

class Pentagon : public Figure
{
public:
	Pentagon(int _x, int _y, int _radius, COLORREF _brush, COLORREF _pen) : Figure(_x, _y, _radius, _brush, _pen) {}

	void show() override;

	void hide() override;

	void createPoints(POINT points[]);
};

