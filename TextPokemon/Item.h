#ifndef __ITEMS_H__
#define __ITEMS_H__

#include "InclLib.h"

class Item
{
private:
    std::string name;
    std::string type;
    int sellPrice;
    int buyPrice;
    int numOwned;
public:
    Item();
    Item(std::string name, std::string type, int sellPrice, int buyPrice);
    ~Item();
    
    inline std::string getItemName() { return this->name; }
    inline std::string getItemType() { return this->type; }
    inline int getItemSellPrice() { return this->sellPrice; }
    inline int getItemBuyPrice() { return this->buyPrice; }
    inline int getQty() { return this->numOwned; }
    
    inline void increaseQty(int qty) { this->numOwned += qty; }
    inline void increaseQty() { this->numOwned++; }
    inline void decreaseQty(int qty) { this->numOwned -= qty; }
    inline void decreaseQty() { this->numOwned--; }

    void initItems();

    std::vector <Item> allItems;
};
#endif