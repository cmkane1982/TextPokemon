#include "Rival.h"

Rival::Rival()
{
	this->name = "NONE";
}

Rival::~Rival()
{

}

void Rival::addPokemon(const Pokemon pokemon)
{
	this->pokemon.push_back(pokemon);
}