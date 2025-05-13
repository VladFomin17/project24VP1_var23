#include <windows.h>
#include <string>
#include "ComplexFigure.h"
using namespace std;

ComplexFigure::ComplexFigure(Circle* _circle, Pentagon* _pentagon) : circle(_circle), pentagon(_pentagon) 
{
	if (_circle->getPoint().x != _pentagon->getPoint().x ||
		_circle->getPoint().y != _pentagon->getPoint().y ||
		_circle->getRadius() != _pentagon->getRadius())
	{
		string message = "Поля фигур не совпадают. Окружность с центром (" + to_string(_circle->getPoint().x) + 
			"; " + to_string(_circle->getPoint().y) + ") и радиусом " + to_string(_circle->getRadius()) + 
			". Пятиугольник с центром (" + to_string(_pentagon->getPoint().x) + "; " + to_string(_pentagon->getPoint().y) +
			") и радиусом " + to_string(_pentagon->getRadius());
		throw FigureException(message);
	}
}

void ComplexFigure::show()
{
	circle->show();
	pentagon->show();
}

void ComplexFigure::hide()
{
	circle->hide();
	pentagon->hide();
}

void ComplexFigure::move(int x, int y)
{
	circle->move(x, y);
	pentagon->move(x, y);
}
