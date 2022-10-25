//#include "Pokemon.h"
#include "main.h"
#include "game.h"

int main()
{
	srand((unsigned int)time(NULL));

	Game game;

	game.beginGame();

	return 0;
}

void cls()
{
	system("CLS");
	//system("clear");
}
void waitEnter()
{
	char enter[1];

	std::cout << "Press Enter to Continue...";
	std::cin.ignore();
	std::cin.get(enter, 1);
	std::cin.clear();
}