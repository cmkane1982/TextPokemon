#include "Item.h"

Item::Item()
{
	this->name = "NONE";
	this->type = "NONE";
	this->sellPrice = 0;
	this->buyPrice = 0;
	this->numOwned = 0;
}

Item::~Item()
{

}

void Item::popItems()
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
			Item temp;

			str.str(line);
			str >> name;
			str >> type;
			str >> buyPrice;
			str >> sellPrice;
			str.clear();
			line.clear();

			temp.setItemName(name);
			temp.setItemType(type);
			temp.setItemSellPrice(sellPrice);
			temp.setItemBuyPrice(buyPrice);

			allItems.push_back(temp);
		}
	}

	itemsIn.close();
}