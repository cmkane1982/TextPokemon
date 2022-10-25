#include "Item.h"

Item::Item()
{
	this->name = "NONE";
	this->type = "NONE";
	this->sellPrice = 0;
	this->buyPrice = 0;
	this->numOwned = 0;
}

Item::Item(std::string name, std::string type, int sellPrice, int buyPrice)
{
	this->name = name;
	this->type = type;
	this->sellPrice = sellPrice;
	this->buyPrice = buyPrice;
	this->numOwned = 0;
}

Item::~Item()
{

}

void Item::initItems()
{
	std::ifstream itemsIn;
	itemsIn.open("Items.txt");

	std::string name = "";
	std::string type = "";
	int sellPrice = 0;
	int buyPrice = 0;
	int numOwned = 0;

	std::string line = "";
	std::stringstream str;

	if (itemsIn.is_open())
	{
		while (std::getline(itemsIn, line))
		{
			str.str(line);
			str >> name;
			str >> type;
			str >> buyPrice;
			str >> sellPrice;
			str.clear();
			line.clear();

			Item temp(name, type, sellPrice, buyPrice);

			allItems.push_back(temp);
		}
	}

	itemsIn.close();
}