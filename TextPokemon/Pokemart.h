#ifndef __POKEMART_H__
#define __POKEMART_H__

#include "InclLib.h"
#include "Item.h"

class Pokemart:
	public Item
{
private:
	std::vector <Item> items;
public:
	Pokemart();
	~Pokemart();
	inline void addItem(Item item) { this->items.push_back(item); }
	inline std::vector <Item> getItems() { return this->items; }
	void initPokemart();
};
#endif // !__POKEMART_H__