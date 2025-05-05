#pragma once
#include <iostream>
#include <windows.h>
#include <windowsx.h>
using namespace std;

struct Point
{
	int x;
	int y;
};

class Figure
{
public:
	Figure() : radius(0), color(RGB(240, 240, 240)) 
	{
		point.x = 0;
		point.y = 0;
	}
	Figure(int _x, int _y, int _radius, COLORREF _color) 
	{
		point.x = _x;
		point.y = _y;
		radius = _radius;
		hwnd = GetConsoleWindow();
		hdc = GetDC(hwnd); 
		GetClientRect(hwnd, &rt);
		color = _color;
	}

	virtual void show()
	{
		if (!isInsideConsole())
		{
			throw BorderException();
		}
	}

	bool isInsideConsole() 
	{
		if (point.x - radius <= rt.left)
		{
			return false;
		}

		return true;
	}

	virtual void hide() 
	{
		return;
	}

	virtual void move(int x, int y)
	{
		hide();
		point.x = x;
		point.y = y;
		show();
	}

	~Figure() { ReleaseDC(hwnd, hdc); }

	class BorderException {};
protected:
	Point point;
	int radius;
	HWND hwnd;
	HDC hdc;
	RECT rt; 
	COLORREF color;
};

