#pragma once
#include <iostream>
using namespace std;

class Menu
{
private:
	string name_of_player;
	char menu_info;
public:
	void Print_menu();
	void WelcomeScreen();
	void Screen_after_game();
};

