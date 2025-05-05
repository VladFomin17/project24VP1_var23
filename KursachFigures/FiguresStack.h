#pragma once
#include <stack>
#include <vector>
#include "Figure.h"

class FiguresStack
{
private:
	stack<Figure*, vector <Figure*> > stackFigures;
public:
	FiguresStack() {}

	void add(Figure* f);

	void show();

	~FiguresStack();
};

