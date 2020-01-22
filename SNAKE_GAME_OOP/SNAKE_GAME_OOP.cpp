#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <ctime>
using namespace std;
#define MAX_SNAKE_SIZE 100
#define MAX_X 119
#define MAX_Y 29
//Tasks
//Добавить конструктор переносу, копіювання

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoxy(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

class Point
{
private:
	int x;
	int y;
public:
	Point() : x(10), y(10) {}

	Point(int x, int y) : x(x), y(y) {}

	void SetPoint(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	int GetX() { return x; }

	int GetY() { return y; }

	void MoveUp()
	{
		y--;
		if (y < 0) //snake will crossing and appearing from the other side
			y = MAX_Y;
	}

	void MoveDown()
	{
		y++;
		if (y > MAX_Y)  //snake will crossing and appearing from the other side
			y = 0;
	}

	void MoveLeft()
	{
		x--;
		if (x < 0)  //snake will crossing and appearing from the other side
			x = MAX_X;
	}

	void MoveRight()
	{
		x++;
		if (x > MAX_X)  //snake will crossing and appearing from the other side
			x = 0;
	}

	void Draw()
	{
		gotoxy(x, y);
		cout << "O";
	}

	void Draw_fruit()
	{
		gotoxy(x, y);
		cout << "@";
	}

	void Erase()
	{
		gotoxy(x, y);
		cout << " ";
	}

	void CopyPos(Point* p)
	{
		p->x = x;
		p->y = y;
	}

	bool IsEqual(Point* p)
	{
		if (p->x == x && p->y == y) return true;
		else return false;
	}
};

class Snake
{
private:
	Point* cell[100];
	int size;//current size of snake;
	char dir;//current dir of cnake;
	Point fruit;
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
		fruit.SetPoint(rand() % MAX_X, rand() % MAX_Y);
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

	void AddCell(int x, int y)
	{
		cell[size++] = new Point(x, y);
	}

	void TurnUp()
	{
		if (dir != 's')
			dir = 'w';
	}

	void TurnDown()
	{
		if (dir != 'w')
			dir = 's';
	}

	void TurnLeft()
	{
		if (dir != 'd')
			dir = 'a';
	}

	void TurnRight()
	{
		if (dir != 'a')
			dir = 'd';
	}

	void WelcomeScreen()
	{
		cout << endl << endl;
		cout << "  	         _______    _          _          __          _    _     ________		   " << endl;
		cout << "		| ____  |  | |\\\\      | |        /  \\        | |  / /   |  ______|   " << endl;
		cout << "		| |   |_|  | | \\\\     | |       / /\\ \\       | | / /    | |		   " << endl;
		cout << "		| |_____   | |  \\\\    | |      / /  \\ \\      | |/ /     | |______   " << endl;
		cout << "		|_____  |  | |   \\\\   | |     / /____\\ \\     | |\\ \\     |  ______|	   " << endl;
		cout << "		 _    |	|  | |    \\\\  | |    / ________ \\    | | \\ \\    | |		   " << endl;
		cout << "		| |___|	|  | |     \\\\ | |   / /        \\ \\   | |  \\ \\   | |______   " << endl;
		cout << "		|_______|  |_|      \\\\|_|  /_/          \\_\\  |_|   \\_\\  |________|		   " << endl;
	}

	int SelfCollision()
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

	void Move()
	{
		system("cls");

		if (state == 0)
		{
			if (!started)
			{
				WelcomeScreen();
				cout << "Press any key to start" << endl;
				_getch();
				started = 1;
				state = 1;
				size = 1;
			}
			else
			{
				cout << "Game Over" << endl;
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

		//turning snake's head
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
			fruit.SetPoint(rand() % MAX_X, rand() % MAX_Y);
		}

		//drawing snake
		for (int i = 0; i < size; ++i)
		{
			cell[i]->Draw();
		}
		fruit.Draw_fruit();
		Sleep(20);
	}


};

int main()
{
	srand(time(NULL));
	Snake snake;
	char direct_choice = 'o';
	do
	{
		if (_kbhit())
		{
			direct_choice = _getch();
		}
		switch (direct_choice)
		{
		case 'w': case 'W':
		{
			snake.TurnUp();
			break;
		}
		case 's': case 'S':
		{
			snake.TurnDown();
			break;
		}
		case 'a': case 'A':
		{
			snake.TurnLeft();
			break;
		}
		case 'd': case 'D':
		{
			snake.TurnRight();
			break;
		}
		break;
		}
		snake.Move();

	} while (direct_choice != 'e');

	system("pause");
	return 0;
}