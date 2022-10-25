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
    ~Item();
    inline void setItemName(std::string name) { this->name = name; }
    inline void setItemType(std::string type) { this->type = type; }
    inline void setItemSellPrice(int sellPrice) { this->sellPrice = sellPrice; }
    inline void setItemBuyPrice(int buyPrice) { this->buyPrice = buyPrice; }
    inline std::string getItemName() { return this->name; }
    inline std::string getItemType() { return this->type; }
    inline int getItemSellPrice() { return this->sellPrice; }
    inline int getItemBuyPrice() { return this->buyPrice; }
    inline int getQty() { return this->numOwned; }
    inline void increaseQty(int qty) { this->numOwned += qty; }
    inline void increaseQty() { this->numOwned++; }
    inline void decreaseQty(int qty) { this->numOwned -= qty; }
    inline void decreaseQty() { this->numOwned--; }
    std::vector <Item> allItems;
    void popItems();
};
#endif