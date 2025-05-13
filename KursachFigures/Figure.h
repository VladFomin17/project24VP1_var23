#pragma once
#include <iostream>
#include <windows.h>
//#include <windowsx.h>
using namespace std;

struct Point
{
	int x;	
	int y;
};

class Figure
{
public:
	Figure();

	Figure(int _x, int _y, int _radius, COLORREF _colorBrush, COLORREF _colorPen);

	virtual void show();

	bool isInsideConsole();

	virtual void hide();

	virtual void move(int x, int y);

	Point getPoint() { return point; }

	int getRadius() { return radius; }

	~Figure() { ReleaseDC(hwnd, hdc); }

	class FigureException : public exception
	{
		string message;

	public:
		enum ErrorType {NEGATIVE_INPUT, OUT_OF_BOUNDS};

		FigureException(ErrorType type, int x, int y, int radius);

		FigureException(string _message) : message(_message) {}

		const char* what() const noexcept override;
	};

protected:
	Point point;
	int radius;
	HWND hwnd;
	HDC hdc;
	RECT rt; 
	COLORREF colorBrush;
	COLORREF colorPen;
};

