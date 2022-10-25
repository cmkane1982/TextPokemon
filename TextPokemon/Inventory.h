#ifndef __INVENTORY_H__
#define __INVENTORY_H__

#include "InclLib.h"
#include "Pokemart.h"

class Inventory:
    public Pokemart
{
private:
    std::vector <Item> items;
public:
    Inventory();
    ~Inventory();
    inline std::vector <Item> getItems() { return this->items; }
    inline std::string getItemName(int index) { return this->items.at(index).getItemName(); }
    inline int getNumOwned(int index) { return this->items.at(index).getQty(); }
    void addItem(Item item);
    void addItem(Item item, int qty);
    void removeItem(int index);
    void removeItem(int index, int qty);
};
#endif