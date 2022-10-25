/*

create pokemart
create gym leaders
create battle system
create main menu
random battles


*/

#include "InclLib.h"
#include "Game.h"

void Game::beginGame()
{
	std::string name;
	int userChoice;

	this->popPokemart();
	this->initPokemon();

	std::cout << "Prof. Oak: Who are you again? My memory isn't what it once was.\n\n";
	std::cout << "Enter Name: ";
	std::cin >> name;
	this->myChar.setCharName(name);
	system("CLS");
	std::cout << "Prof. Oak: Ah, yes " << name << ". Now what was my worthless grandson's name again?\n\n";
	std::cout << "Enter Rival Name: ";
	std::cin >> name;
	this->myRival.setRivalName(name);
	system("CLS");
	std::cout << "Prof. Oak: Now the time you have awaited. Choose your Pokemon:\n";
	std::cout << "1: Bulbasaur 2: Charmander 3: Squirtle\n\n";
	std::cout << "Please Choose (1 - 3): ";
	std::cin >> userChoice;
	system("CLS");
	
	switch (userChoice)
	{
	case 1:
		this->myChar.addPokemon(this->allPokemon.at(BULBASAUR));
		this->myRival.addPokemon(this->allPokemon.at(CHARMANDER));
		break;
	case 2:
		this->myChar.addPokemon(this->allPokemon.at(CHARMANDER));
		this->myRival.addPokemon(this->allPokemon.at(SQUIRTLE));
		break;
	case 3:
		this->myChar.addPokemon(this->allPokemon.at(SQUIRTLE));
		this->myRival.addPokemon(this->allPokemon.at(BULBASAUR));
		break;
	default:
		std::cout << "Invalid Selection. Please Select Again.\n";
		break;
	}

	this->myChar.setActivePokemon(0);
	this->myRival.setActivePokemon(0);

	this->myChar.getActivePokemon()->levelUp(5);
	this->myRival.getActivePokemon()->levelUp(5);

	this->myChar.addItem(this->allItems.at(POTION), 10);
	this->myChar.addItem(this->allItems.at(POKEBALL), 10);

	std::cout << this->myRival.getRivalName() << ": Everyone knows " << this->myRival.getActivePokemon()->getName() << " is better. ";
	std::cout << "My " << this->myRival.getActivePokemon()->getName() << " is going to destroy your " << this->myChar.getActivePokemon()->getName() << "!\n";

	combat(&myChar, &myRival);
	
	std::cout << "Press Enter to continue...";
	std::cin.ignore();
	std::cin.get();
	system("CLS");
}