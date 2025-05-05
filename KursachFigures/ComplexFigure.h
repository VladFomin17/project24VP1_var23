#pragma once
#include "Pentagon.h"
#include "Circle.h"

class ComplexFigure : public Figure
{
private:
	Circle* circle;
	Pentagon* pentagon;
public:
	ComplexFigure(Circle* _circle, Pentagon* _pentagon) : circle(_circle), pentagon(_pentagon) {}

	void show() override;

	void hide() override;

	void move(int x, int y) override;
};

