#include <windows.h>
#include <windowsx.h>
#include <cmath>
#include "Pentagon.h"
using namespace std;

void Pentagon::show()
{
	Figure::show();
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	HBRUSH brush = CreateSolidBrush(color);
	SelectObject(hdc, pen);
	SelectObject(hdc, brush);

	POINT points[5];
	createPoints(points);
	Polygon(hdc, points, 5);

	DeleteObject(pen);
	DeleteObject(brush);
}

void Pentagon::hide()
{
	COLORREF bgColor = RGB(240, 240, 240);
	HPEN pen = CreatePen(PS_SOLID, 2, bgColor);
	HBRUSH brush = CreateSolidBrush(bgColor);
	SelectObject(hdc, pen);
	SelectObject(hdc, brush);

	POINT points[5];
	createPoints(points);
	Polygon(hdc, points, 5);

	DeleteObject(pen);
	DeleteObject(brush);
}

void Pentagon::createPoints(POINT points[])
{
	for (int i{}; i < 5; i++)
	{
		double angle = 72.0 * i * 3.14159 / 180.0;
		points[i].x = point.x + radius * cos(angle);
		points[i].y = point.y + radius * sin(angle);
	}
}
