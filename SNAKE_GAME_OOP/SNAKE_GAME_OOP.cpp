#include "Menu.h"
#include "Point.h"
#include "Snake.h"


int main()
{
	system("color B0");
	srand(time(NULL));
	Menu menu;
	Snake snake;
	Point point;
	char direct_choice = 'o';

	menu.Print_menu();
	menu.WelcomeScreen();

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
		default:
			break;
		}
		snake.Move();
	} while (direct_choice != 'e');

	menu.Screen_after_game();
	system("pause");
	return 0;
}
