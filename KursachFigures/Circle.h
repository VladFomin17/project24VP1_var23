#pragma once
#include "Figure.h"
#include <windows.h>
#include <windowsx.h>
using namespace std;

class Circle : public Figure
{
public:
	Circle(int _x, int _y, int _radius, COLORREF _brush) : Figure(_x, _y, _radius, _brush) {};

	void show() override
	{
		HPEN pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
		HBRUSH brush = CreateSolidBrush(color);
		SelectObject(hdc, pen);	
		SelectObject(hdc, brush);
		Ellipse(hdc, point.x - radius, point.y - radius, point.x + radius, point.y + radius);
		
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
		Ellipse(hdc, point.x - radius, point.y - radius, point.x + radius, point.y + radius);

		DeleteObject(pen);
		DeleteObject(brush);
	}
};

