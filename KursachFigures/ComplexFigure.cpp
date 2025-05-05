#include <windows.h>
#include <windowsx.h>
#include "ComplexFigure.h"
using namespace std;

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
