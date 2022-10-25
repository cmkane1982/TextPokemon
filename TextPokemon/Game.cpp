/*

create pokemart
create gym leaders
create battle system
create main menu
random battles


*/

#include "InclLib.h"
#include "Game.h"
#include "main.h"

void Game::beginGame()
{
	std::string name;
	int userChoice;
	bool victory;

	this->initPokemart();
	this->initPokemon();
	this->initGym(this->allPokemon);

	std::cout << "Hello there! Welcome to the world of Pokemon!\n";
	std::cout << "My name is Oak! People call me the Pokemon Prof!\n";
	std::cout << "This world is inhabited by creatures call Pokemon!\n";
	std::cout << "For some people, Pokemon are pets. Others use them for fights.\n";
	std::cout << "Myself... I study Pokemon as a profession.\n";
	std::cout << "First, what is your name?\n\n";
	std::cout << "Enter Name: ";
	std::cin >> name;
	this->myChar.setCharName(name);
	cls();
	std::cout << "Right! So your name is " << name << "!\n";
	std::cout << "I have a grandson. He's been your rival since you were a baby\n";
	std::cout << "...Erm, what is his name again?\n\n";
	std::cout << "Enter Rival Name: ";
	std::cin >> name;
	this->myRival.setRivalName(name);
	cls();
	std::cout << "Prof. Oak: In my old age, I have misplaced all but 3 Pokemon.\n";
	std::cout << "           " << this->myChar.getCharName() << ", you may have one. Take some Potions and PokeBalls too.\n\n";
	std::cout << "1: Bulbasaur 2: Charmander 3: Squirtle\n\n";
	std::cout << "Please Choose (1 - 3): ";
	std::cin >> userChoice;
	cls();
	
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

	//this->myChar.getActivePokemon()->levelUp(5);
	//this->myRival.getActivePokemon()->levelUp(5);

	this->myChar.addItem(this->allItems.at(POTION), 10);
	this->myChar.addItem(this->allItems.at(POKEBALL), 10);

	std::cout << this->myRival.getRivalName() << ": Everyone knows " << this->myRival.getActivePokemon()->getName() << " is better! ";
	std::cout << "My " << this->myRival.getActivePokemon()->getName() << " is going to destroy your " << this->myChar.getActivePokemon()->getName() << "!\n";

	victory = combat(&myChar, &myRival);

	cls();
	if(victory)
		std::cout << myRival.getRivalName() << ": YOU CHEATED! THAT OLD FART GAVE ME A DUD POKEMON!\n";
	else
		std::cout << myRival.getRivalName() << ": HAHAHAHA! LOSER! I TOLD YOU I'M BETTER!\n";

	waitEnter();
	cls();

	std::cout << "What Would you like to do?\n";
	std::cout << "1. Challenge Gym Leader\n";
	std::cout << "2. Hunt Wild Pokemon\n";
	std::cout << "3. Goto PokeCenter\n";
	std::cout << "4. BackPack\n";
	std::cout << "Please Choose (1 - 4): ";
	std::cin >> userChoice;

	switch (userChoice)
	{
	case 1:
		break;
	case 2:
		combat(&myChar);
		break;
	case 3:
		break;
	default:
		break;
	}
}