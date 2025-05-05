#include <windows.h>
#include <windowsx.h>
#include "FiguresStack.h"


void FiguresStack::add(Figure* f)
{
	stackFigures.push(f);
}

void FiguresStack::show()
{
	while (!stackFigures.empty()) {
		stackFigures.top()->show();
		cout << endl;
		stackFigures.pop();
	}
	cout << endl;
}

FiguresStack::~FiguresStack()
{
	while (!stackFigures.empty())
	{
		stackFigures.pop();
	}
}