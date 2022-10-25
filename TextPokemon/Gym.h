#ifndef __GYM_H__
#define __GYM_H__

#include "InclLib.h"
#include "Pokemon.h"

class Gym
{
private:
	std::string leadName;
	std::vector <Pokemon> leadPokemon;
	int level;
public:
	Gym();
	Gym(std::string leadName, std::vector <Pokemon> leadPokemon, int level);
	~Gym();
	
	inline std::string getName() { return this->leadName; }
	inline std::vector <Pokemon>* getPokemon() { return &this->leadPokemon; }
	inline int getLevel() { return this->level; }

	void initGym(std::vector <Pokemon> allPokemon);

	std::vector <Gym> gymLeaders;
};

#endif // !__GYM_H__
