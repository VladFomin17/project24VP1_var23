#pragma once
#include "Pentagon.h"
#include "Circle.h"
#include <windows.h>
#include <windowsx.h>
using namespace std;

class ComplexFigure : public Figure
{
private:
	Circle* circle;
	Pentagon* pentagon;
public:
	ComplexFigure(Circle* _circle, Pentagon* _pentagon) : circle(_circle), pentagon(_pentagon) {}

	void show() override
	{
		circle->show();
		pentagon->show();
	}

	void hide() override
	{
		circle->hide();
		pentagon->hide();
	}

	void move(int x, int y) override
	{
		circle->move(x, y);
		pentagon->move(x, y);
	}
};

