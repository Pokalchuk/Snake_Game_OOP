#include "Snake.h"

void Snake::AddCell(int x, int y)
{
	cell[size++] = new Point(x, y);
}

void Snake::TurnUp()
{
	if (dir != 's')
		dir = 'w';
}

void  Snake::TurnDown()
{
	if (dir != 'w')
		dir = 's';
}

void  Snake::TurnLeft()
{
	if (dir != 'd')
		dir = 'a';
}

void  Snake::TurnRight()
{
	if (dir != 'a')
		dir = 'd';
}

int  Snake::SelfCollision()
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (cell[i]->IsEqual(cell[j]) && i != j)
				return 1;
		}
	}
	return 0;
}

void  Snake::Move()
{
	system("cls");

	if (state == 0)
	{
		if (!started)
		{
			cout << "Press any key to start" << endl;
			_getch();
			started = 1;
			state = 1;
			size = 1;
		}
		else
		{
			cout << "Game Over" << endl;
			cout << "Score : " << score << endl;
			cout << "Press any key to start" << endl;
			_getch();
			state = 1;
			size = 1;
		}

	}

	//snake body will foolow head
	for (int i = size - 1; i > 0; --i)
	{
		cell[i - 1]->CopyPos(cell[i]);
	}

	//turning snake's headw
	switch (dir)
	{
	case 'w':
	{
		cell[0]->MoveUp();
		break;
	}
	case 's':
	{
		cell[0]->MoveDown();
		break;
	}
	case 'a':
	{
		cell[0]->MoveLeft();
		break;
	}
	case 'd':
	{
		cell[0]->MoveRight();
		break;
	}
	break;
	}

	if (SelfCollision())
	{
		state = 0;
	}

	if (fruit.GetX() == (cell[0]->GetX()) && fruit.GetY() == (cell[0]->GetY()))
	{
		AddCell(0, 0);
		fruit.Set_fruit(rand() % MAX_X, rand() % MAX_Y);
	}

	if (mega_fruit.GetX() == (cell[0]->GetX()) && mega_fruit.GetY() == (cell[0]->GetY()))
	{
		AddCell(0, 0);
		mega_fruit.Set_mega_fruit(rand() % MAX_X, rand() % MAX_Y);
	}

	//drawing snake
	for (int i = 0; i < size; ++i)
	{
		cell[i]->Draw();
	}

	fruit.Draw_fruit();

	int randomize{};
	randomize = rand() % 30;


	int start = clock();

	if (start = 3000)
	{
		mega_fruit.Draw_mega_fruit();
		start = 0;
	}
	Sleep(20);
}
