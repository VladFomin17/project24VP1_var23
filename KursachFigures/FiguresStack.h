#pragma once
#include <stack>
#include <vector>
#include "Figure.h"
#include <windows.h>
#include <windowsx.h>

class FiguresStack
{
private:
	stack<Figure*, vector <Figure*> > stackFigures;
public:
	FiguresStack() {}

	void add(Figure* f) 
	{ 
		stackFigures.push(f);
	}

	void show() {
		while (!stackFigures.empty()) {
			stackFigures.top()->show();
			cout << endl;
			stackFigures.pop();
		}
		cout << endl;
	}

	~FiguresStack() {
		while (!stackFigures.empty())
		{
			stackFigures.pop();
		}
	}
};

