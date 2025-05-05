#include <windows.h>
#include <windowsx.h>
#include "Circle.h"
using namespace std;

void Circle::show()
{
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	HBRUSH brush = CreateSolidBrush(color);
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
