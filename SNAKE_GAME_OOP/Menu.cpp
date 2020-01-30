#include "Menu.h"
#include "Point.h"

void Menu::Print_menu()
{
	setlocale(LC_ALL, "RUS");
	cout << "\n\n\n\n\n\n";
	cout << "\t\t\t\t\tI am glad to see you, enter your name : " << endl;
	cout << "\t\t\t\t\t\t\t"; cin >> name_of_player;
	cin.get();

	cout << "\n\n\n\n\n\t\t\t\tHello again, i'm the creator of game - Artem Pokalchuk" << endl;
	cout << "\t\t\t\tI am 19 years old and I live in Ukraine in the city Rivne" << endl;
	cout << "\t\t\t\tI'm studying in National University of Water and Environmental Engineeringy \n\t\t\t\tat the facultyof=appliedmathematics also i'm studying in computer academy STEP" << endl;
	cout << "\t\t\t\tIn the future i will become programmer" << endl;
	cin.get();
	system("cls");

}

void Menu::WelcomeScreen()
{
	cout << endl << endl;
	cout << "\t\t  	         _______    _          _          __          _    _     ________		   " << endl;
	cout << "\t\t 		| ____  |  | |\\\\      | |        /  \\        | |  / /   |  ______|   " << endl;
	cout << "\t\t 		| |   |_|  | | \\\\     | |       / /\\ \\       | | / /    | |		   " << endl;
	cout << "\t\t 		| |_____   | |  \\\\    | |      / /  \\ \\      | |/ /     | |______   " << endl;
	cout << "\t\t 		|_____  |  | |   \\\\   | |     / /____\\ \\     | |\\ \\     |  ______|	   " << endl;
	cout << "\t\t 		 _    |	|  | |    \\\\  | |    / ________ \\    | | \\ \\    | |		   " << endl;
	cout << "\t\t 		| |___|	|  | |     \\\\ | |   / /        \\ \\   | |  \\ \\   | |______   " << endl;
	cout << "\t\t 		|_______|  |_|      \\\\|_|  /_/          \\_\\  |_|   \\_\\  |________|		   " << endl;
	cin.get();
}

void Menu::Screen_after_game()
{
	system("cls");
	cout << "\t\t  	         _______   __    __    _______     ________    ________		   " << endl;
	cout << "\t\t 		| ____  |  | |  / /    | _____|   | |     |   |  ______|  " << endl;
	cout << "\t\t 		| |   |_|  | | / /     ||    ||   | |     |   | |		   " << endl;
	cout << "\t\t 		| |_____   | |/ /      ||    ||   | |_____|   | |______   " << endl;
	cout << "\t\t 		|_____  |  | |\\ \\      ||    ||   | | \\       |  ______|	   " << endl;
	cout << "\t\t 		 _    |	|  | | \\ \\     ||    ||   | |\\ \\      | |		   " << endl;
	cout << "\t\t 		| |___|	|  | |  \\ \\    ||____||   | | \\ \\     | |______   " << endl;
	cout << "\t\t 		|_______|  |_|   \\_\\   |______|   |_|  \\_\\    |________|		   " << endl;

	cout << "\n\n\n";
	cout << "\t\t\t\t\t 		  " <<  score << endl;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}
