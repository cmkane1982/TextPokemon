#include "Pokemart.h"

Pokemart::Pokemart()
{

}

Pokemart::~Pokemart()
{

}

void Pokemart::popPokemart()
{
	popItems();

	for (size_t i = 0; i < this->items.size(); i++)
	{
		this->addItem(items.at(i));
	}
}