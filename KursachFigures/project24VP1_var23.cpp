#include <iostream>
#include "Figure.h"
#include "Pentagon.h"
#include "Circle.h"
#include "ComplexFigure.h"
#include "FiguresStack.h"
#include <windows.h>
#include <windowsx.h>
using namespace std;
// Фомин В.Д. 24ВП1 вариант 23, окружность и пятиугольник

int main()
{
    setlocale(LC_ALL, "RU");
    system("color F0");
    try {
        COLORREF circleColor = RGB(128, 0, 128);
        COLORREF pentagonColor = RGB(128, 0, 0);
        COLORREF penColor = RGB(0, 0, 0);

        Circle* circle = new Circle(100, 280, 75, circleColor, penColor);
        Pentagon* pentagon = new Pentagon(100, 280, 75, pentagonColor, penColor);
        ComplexFigure* complex = new ComplexFigure(circle, pentagon);

        Circle* circle1 = new Circle(300, 300, 100, circleColor, penColor);
        Pentagon* pentagon1 = new Pentagon(600, 200, 50, pentagonColor, penColor);

        FiguresStack stack{complex, circle1, pentagon1};
        stack.show();
        Sleep(3000);

        complex->move(500, 300);
        Sleep(1000);
        circle1->move(150, 250);
        Sleep(3000);

        stack.hide();

        Circle* bigCircle = new Circle(-50, 50, 100, circleColor, penColor);
        bigCircle->show();
        Sleep(3000);
    }
    catch (const Figure::FigureException& e) 
    {
        cout << e.what() << endl;
    }
}
