#include "Character.h"

Character::Character()
{
	this->name = "NONE";
	this->money = 100;
}


Character::~Character()
{

}

void Character::addItem(const Item item)
{
	this->inventory.addItem(item);
}

void Character::addItem(const Item item, const int qty)
{
	this->inventory.addItem(item, qty);
}

void Character::addPokemon(const Pokemon pokemon)
{
	this->pokemon.push_back(pokemon);
}

void Character::setActivePokemon(const int index)
{
	if (this->activePokemon.getName() != "NONE")
	{
		this->pokemon.push_back(this->activePokemon);
		this->activePokemon = this->pokemon.at(index);
		this->pokemon.erase(this->pokemon.begin() + index);
	}
	else
	{
		this->activePokemon = this->pokemon.at(index);
		this->pokemon.erase(this->pokemon.begin() + index);
	}
}