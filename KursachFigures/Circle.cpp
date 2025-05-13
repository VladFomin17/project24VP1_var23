#include <windows.h>
#include "Circle.h"
using namespace std;

void Circle::show()
{
	Figure::show();
	HPEN pen = CreatePen(PS_SOLID, 2, colorPen);
	HBRUSH brush = CreateSolidBrush(colorBrush);
	SelectObject(hdc, pen);
	SelectObject(hdc, brush);
	Ellipse(hdc, point.x - radius, point.y - radius, point.x + radius, point.y + radius);

	DeleteObject(pen);
	DeleteObject(brush);
}

void Circle::hide()
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
