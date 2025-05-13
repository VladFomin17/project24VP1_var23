#include <iostream>
#include "Figure.h"
#include "Pentagon.h"
#include "Circle.h"
#include "ComplexFigure.h"
#include "FiguresStack.h"
#include <windows.h>
using namespace std;
// Фомин В.Д. 24ВП1 вариант 23, окружность и пятиугольник

int main()
{
    setlocale(LC_ALL, "RU");
    system("color F0");
    try {
        SetConsoleTitle((LPCWSTR)L"24VP1_23");

        COLORREF circleColor = RGB(128, 0, 128);
        COLORREF pentagonColor = RGB(128, 0, 0);
        COLORREF penColor = RGB(0, 0, 0);

        Circle* circle = new Circle(100, 280, 75, circleColor, penColor);
        Pentagon* pentagon = new Pentagon(100, 280, 75, pentagonColor, penColor);
        ComplexFigure* complex = new ComplexFigure(circle, pentagon);

        Circle* circle1 = new Circle(300, 300, 100, circleColor, penColor);
        Circle* circle2 = new Circle(600, 200, 50, pentagonColor, RGB(0, 255, 0));

        FiguresStack stack{complex, circle1, circle2};
        stack.show();
        Sleep(3000);

        /*try { Circle* circleEx = new Circle(-50, 50, 100, circleColor, penColor); }
        catch (const Figure::FigureException& e) { cout << e.what() << endl; }

        try 
        {
            Circle* circleEx = new Circle(50, 50, 100, circleColor, penColor); 
            circleEx->show();
        }
        catch (const Figure::FigureException& e) { cout << e.what() << endl; }

        try {
            Circle* circle = new Circle(300, 280, 75, circleColor, penColor);
            Pentagon* pentagon = new Pentagon(100, 280, 75, pentagonColor, penColor);
            ComplexFigure* complex = new ComplexFigure(circle, pentagon);
        }
        catch (const Figure::FigureException& e) { cout << e.what() << endl; }
        Sleep(5000);*/

        complex->move(500, 300);
        Sleep(1000);
        circle1->move(150, 250);
        Sleep(3000);

        /*try { circle1->move(50, 250); }
        catch (const Figure::FigureException& e) { cout << e.what() << endl; }
        try { circle1->move(250, -250); }
        catch (const Figure::FigureException& e) { cout << e.what() << endl; }*/

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
