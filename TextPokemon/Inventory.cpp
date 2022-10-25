#include "Inventory.h"

Inventory::Inventory()
{

}

Inventory::~Inventory()
{

}

void Inventory::addItem(Item item)
{
	bool found = false;
	int index;
	
	if (this->items.size() > 0)
	{
		for (int i = 0; i < this->items.size() && !found; i++)
		{
			if (this->items.at(i).getItemName() == item.getItemName())
			{
				found = true;
				index = i;
			}
		}

		if (found)
			this->items.at(index).increaseQty();
		else
		{
			this->items.push_back(item);
			this->items.at(this->items.size() - 1).increaseQty();
		}
	}
	else
	{
		this->items.push_back(item);
		this->items.at(this->items.size() - 1).increaseQty();
	}
}

void Inventory::addItem(Item item, int qty)
{
	bool found = false;
	int index;

	if (this->items.size() > 0)
	{
		for (int i = 0; i < this->items.size() && !found; i++)
		{
			if (this->items.at(i).getItemName() == item.getItemName())
			{
				found = true;
				index = i;
			}
		}

		if (found)
			this->items.at(index).increaseQty(qty);
		else
		{
			this->items.push_back(item);
			this->items.at(this->items.size() - 1).increaseQty(qty);
		}
	}
	else
	{
		this->items.push_back(item);
		this->items.at(this->items.size() - 1).increaseQty(qty);
	}
}

void Inventory::removeItem(int index)
{
	this->items.at(index).decreaseQty();
}

void Inventory::removeItem(int index, int qty)
{
	this->items.at(index).decreaseQty(qty);
}