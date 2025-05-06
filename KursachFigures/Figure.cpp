#include <iostream>
#include <string>
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
	if (_x < 0 || _y < 0 || _radius < 0) { throw FigureException(FigureException::NEGATIVE_INPUT, _x, _y, _radius); }

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
	if (!isInsideConsole()) { throw FigureException(FigureException::OUT_OF_BOUNDS, this->point.x, this->point.y, this->radius); }
}

bool Figure::isInsideConsole()
{
	return (point.x - radius > rt.left) &&   
		(point.x + radius < rt.right) && 
		(point.y - radius > rt.top) &&    
		(point.y + radius < rt.bottom);
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

Figure::FigureException::FigureException(ErrorType type, int x, int y, int radius) 
{
	if (type == NEGATIVE_INPUT) {
		message = "Отрицательные данные. Центр: " + to_string(x) + ", " + to_string(y) + ". Радиус: " + to_string(radius);
	}
	else {
		message = "Выход за границы. Центр: " + to_string(x) + ", " + to_string(y) + ". Радиус: " + to_string(radius);
	}
}

const char* Figure::FigureException::what() const noexcept 
{
	return message.c_str();
}