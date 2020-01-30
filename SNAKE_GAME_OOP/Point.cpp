#include "Point.h"
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void Point::Set_fruit(int x, int y) //spawn fruit
{
	this->x = x;
	this->y = y;
	score += 10;
}

void Point::Set_mega_fruit(int x, int y)
{
	this->x = x;
	this->y = y;
	score += 50;
}

void Point::MoveUp()
{
	y--;
	if (y < 0) //snake will crossing and appearing from the other side
		y = MAX_Y;
}

void Point::MoveDown()
{
	y++;
	if (y > MAX_Y)  //snake will crossing and appearing from the other side
		y = 0;
}

void Point::MoveLeft()
{
	x--;
	if (x < 0)  //snake will crossing and appearing from the other side
		x = MAX_X;
}

void Point::MoveRight()
{
	x++;
	if (x > MAX_X)  //snake will crossing and appearing from the other side
		x = 0;
}

void Point::Draw()
{
	gotoxy(x, y);
	cout << "O";
}

void Point::Draw_fruit()
{
	gotoxy(x, y);
	cout << "@";
}

void Point::Draw_mega_fruit()
{
	gotoxy(x, y);
	cout << "*";
}

void Point::Erase()
{
	gotoxy(x, y);
	cout << " ";
}

void Point::CopyPos(Point* p)
{
	p->x = x;
	p->y = y;
}

bool Point::IsEqual(Point* p)
{
	if (p->x == x && p->y == y) return true;
	else return false;
}

void gotoxy(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}
