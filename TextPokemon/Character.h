#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "InclLib.h"
#include "Inventory.h"
#include "Pokemon.h"

class Character
{
private:
	std::string name;
	int money;
	Inventory inventory;
	Pokemon activePokemon;
	std::vector <Pokemon> pokemon;
public:
	Character();
	~Character();
	void addItem(const Item item);
	void addItem(const Item item, const int qty);
	void addPokemon(const Pokemon pokemon);
	inline void setCharName(std::string name) { this->name = name; }
	inline void addPokemonMove(const Skills skill) { this->activePokemon.addSkill(skill); }
	void setActivePokemon(const int index);
	inline std::string getCharName() { return this->name; }
	inline int getMoney() { return this->money; }
	inline std::vector <Pokemon> getPokemon() { return this->pokemon; }
	//inline Pokemon getActivePokemon() { return this->activePokemon; }
	inline Pokemon* getActivePokemon() { return &this->activePokemon; }
	inline Inventory getInventory() { return this->inventory; }
	inline void gainExp(int exp) { this->activePokemon.gainExp(exp); }
	inline void gainMoney(int money) { this->money += money; }
	inline void spendMoney(int money) { this->money -= money; }
	inline void takeDamage(int damage) { this->activePokemon.takeDamage(damage); }
};
#endif // !__CHARACTER_H__