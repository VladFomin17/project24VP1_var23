#include <iostream>
#include <string>
#include <windows.h>
#include "Figure.h"
using namespace std;

Figure::Figure() : radius(0), colorBrush(RGB(240, 240, 240)), colorPen(RGB(240, 240, 240))
{
	point.x = 0;
	point.y = 0;
	hwnd = GetConsoleWindow();
	hdc = GetDC(hwnd);
	GetClientRect(hwnd, &rt);
}

Figure::Figure(int _x, int _y, int _radius, COLORREF _colorBrush, COLORREF _colorPen) : Figure()
{
	if (_x < 0 || _y < 0 || _radius <= 0) { throw FigureException(FigureException::NEGATIVE_INPUT, _x, _y, _radius); }

	point.x = _x;
	point.y = _y;
	radius = _radius;
	hwnd = GetConsoleWindow();
	hdc = GetDC(hwnd);
	GetClientRect(hwnd, &rt);
	colorBrush = _colorBrush;
	colorPen = _colorPen;
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
	if (x < 0 || y < 0) { throw FigureException(FigureException::NEGATIVE_INPUT, x, y, radius); }
	show();
}

Figure::FigureException::FigureException(ErrorType type, int x, int y, int radius) 
{
	if (type == NEGATIVE_INPUT) {
		message = "������������ ������. �����: " + to_string(x) + ", " + to_string(y) + ". ������: " + to_string(radius);
	}
	else {
		message = "����� �� �������. �����: " + to_string(x) + ", " + to_string(y) + ". ������: " + to_string(radius);
	}
}

const char* Figure::FigureException::what() const noexcept 
{
	return message.c_str();
}