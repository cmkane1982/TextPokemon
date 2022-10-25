#ifndef __RIVAL_H__
#define __RIVAL_H__

#include "InclLib.h"
#include "Pokemon.h"

class Rival
{
private:
	std::string name;
	Pokemon* activePokemon;
	std::vector <Pokemon> pokemon;
public:
	Rival();
	~Rival();
	void addPokemon(const Pokemon pokemon);
	inline void addPokemonMove(const Skills skill) { this->activePokemon->addSkill(skill); }
	inline void setActivePokemon(const int index) { this->activePokemon = &this->pokemon.at(index); }
	inline void setRivalName(std::string name) { this->name = name; }
	inline std::string getRivalName() { return this->name; }
	inline std::vector <Pokemon> getPokemon() { return this->pokemon; }
	inline Pokemon* getActivePokemon() { return this->activePokemon; }
};
#endif