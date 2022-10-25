#include "Pokemart.h"

Pokemart::Pokemart()
{

}

Pokemart::~Pokemart()
{

}

void Pokemart::initPokemart()
{
	initItems();

	for (size_t i = 0; i < this->items.size(); i++)
	{
		this->addItem(items.at(i));
	}
}