#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <ctime>
using namespace std;
#define MAX_SNAKE_SIZE 100
#define MAX_X 119
#define MAX_Y 29
static int score;



void gotoxy(int x, int y);

class Point
{
private:
	int x;
	int y;
public:
	Point() : x(10), y(10) {}

	Point(int x, int y) : x(x), y(y) {}
	void Set_fruit(int x, int y);//spawn fruit
	void Set_mega_fruit(int x, int y);
	int GetX() { return x; }
	int GetY() { return y; }
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	void Draw();
	void Draw_fruit();
	void Draw_mega_fruit();
	void Erase();
	void CopyPos(Point* p);
	bool IsEqual(Point* p);
};

