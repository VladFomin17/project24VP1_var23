#include <windows.h>
#include <windowsx.h>
#include "FiguresStack.h"


void FiguresStack::add(Figure* f)
{
	stackFigures.push(f);
}

void FiguresStack::show()
{
	stack <Figure*, vector<Figure*>> tempStack = stackFigures;

	while (!tempStack.empty()) {
		tempStack.top()->show();
		cout << endl;
		Sleep(500);
		tempStack.pop();
	}
	cout << endl;
}

void FiguresStack::hide()
{
	stack <Figure*, vector<Figure*>> tempStack = stackFigures;

	while (!tempStack.empty()) {
		tempStack.top()->hide();
		cout << endl;
		tempStack.pop();
	}
	cout << endl;
}

void FiguresStack::clear()
{
	while (!stackFigures.empty())
	{
		stackFigures.pop();
	}
}