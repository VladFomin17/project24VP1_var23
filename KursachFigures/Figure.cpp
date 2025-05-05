#include <iostream>
#include <windows.h>
#include <windowsx.h>
#include "Figure.h"
using namespace std;

Figure::Figure() : radius(0), color(RGB(240, 240, 240))
{
	point.x = 0;
	point.y = 0;
}

Figure::Figure(int _x, int _y, int _radius, COLORREF _color) : Figure()
{
	point.x = _x;
	point.y = _y;
	radius = _radius;
	hwnd = GetConsoleWindow();
	hdc = GetDC(hwnd);
	GetClientRect(hwnd, &rt);
	color = _color;
}

void Figure::show()
{
	if (!isInsideConsole())
	{
		throw BorderException();
	}
}

bool Figure::isInsideConsole()
{
	if (point.x - radius <= rt.left)
	{
		return false;
	}

	return true;
}

void Figure::hide()
{
	return;
}

void Figure::move(int x, int y)
{
	hide();
	point.x = x;
	point.y = y;
	show();
}