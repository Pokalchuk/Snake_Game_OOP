#pragma once
#include "Point.h"

class Snake
{
private:
	Point* cell[100];
	int size;//current size of snake;
	char dir;//current dir of cnake;
	Point fruit;
	Point mega_fruit;
	int state; // shows state of snakes living , dead
	int started;
public:
	Snake()
	{
		size = 1;
		cell[0] = new Point(20, 20);
		for (int i = 1; i < 100; ++i)
		{
			cell[i] = NULL;
		}
		fruit.Set_fruit(rand() % MAX_X, rand() % MAX_Y);
		mega_fruit.Set_mega_fruit(rand() % MAX_X, rand() % MAX_Y);
		state = 0;
		started = 0;
	}
	~Snake()
	{
		if (cell != nullptr)
		{
			for (int i = 0; i < 100; ++i)
			{
				if (cell[i] != nullptr)
				{
					delete cell[i];
					cell[i] = nullptr;
				}
			}
		}
	}
	void AddCell(int x, int y);
	void TurnUp();
	void TurnDown();
	void TurnLeft();
	void TurnRight();
	int SelfCollision();
	void Move();
};
