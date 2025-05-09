#pragma once
#include <stack>
#include <vector>
#include <initializer_list>
#include "Figure.h"

class FiguresStack
{
private:
	stack<Figure*, vector <Figure*> > stackFigures;
public:
	FiguresStack() {}

	FiguresStack(initializer_list <Figure*> list)
	{
		for (auto figure : list)
		{
			stackFigures.push(figure);
		}
	}

	void add(Figure* f);

	void show();

	void hide();

	void clear();
};

