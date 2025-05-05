#pragma once
#include "Figure.h"
#include <windows.h>
#include <windowsx.h>
#include <cmath>
using namespace std;

class Pentagon : public Figure
{
public:
	Pentagon(int _x, int _y, int _radius, COLORREF _color) : Figure(_x, _y, _radius, _color) {}

	void show() override
	{
		HPEN pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
		HBRUSH brush = CreateSolidBrush(color);
		SelectObject(hdc, pen);
		SelectObject(hdc, brush);

		POINT points[5];
		for (int i{}; i < 5; i++)
		{
			double angle = 72.0 * i * 3.14159 / 180.0;
			points[i].x = point.x + radius * cos(angle);
			points[i].y = point.y + radius * sin(angle);
		}
		Polygon(hdc, points, 5);
		
		DeleteObject(pen);
		DeleteObject(brush);
	}

	void hide() override
	{
		COLORREF bgColor = RGB(240, 240, 240);
		HPEN pen = CreatePen(PS_SOLID, 2, bgColor);
		HBRUSH brush = CreateSolidBrush(bgColor);
		SelectObject(hdc, pen);
		SelectObject(hdc, brush);

		POINT points[5];
		for (int i{}; i < 5; i++)
		{
			double angle = 72.0 * i * 3.14159 / 180.0;
			points[i].x = point.x + radius * cos(angle);
			points[i].y = point.y + radius * sin(angle);
		}
		Polygon(hdc, points, 5);

		DeleteObject(pen);
		DeleteObject(brush);
	}
};

