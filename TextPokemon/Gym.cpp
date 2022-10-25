#include "Gym.h"

Gym::Gym()
{
	this->leadName = "NONE";
	this->level = 0;
}

Gym::Gym(std::string leadName, std::vector <Pokemon> leadPokemon, int level)
{
	this->leadName = leadName;
	this->leadPokemon = leadPokemon;
	this->level = level;
}

Gym::~Gym()
{

}

void Gym::initGym(std::vector <Pokemon> allPokemon)
{
	std::ifstream gymIn;
	gymIn.open("Gym.txt");

	std::string leadName = "";
	int pokemonNum;
	std::vector <Pokemon> leadPokemon;
	int level;

	std::string line = "";
	std::stringstream str;
	if (gymIn.is_open())
	{
		while (std::getline(gymIn, line))
		{
			str.str(line);
			str >> leadName;
			for (size_t i = 0; i < 5; i++)
			{
				str >> pokemonNum;
				if (pokemonNum != -1)
					leadPokemon.push_back(allPokemon.at(pokemonNum));
			}
			str >> level;

			str.clear();
			line.clear();

			for (size_t i = 0; i < leadPokemon.size(); i++)
			{
				leadPokemon.at(i).levelUp(level);
				for (size_t ii = 1; ii < leadPokemon.at(i).getAllMoves().size() && ii < 4; ii++)
				{
					leadPokemon.at(i).addSkill(leadPokemon.at(i).getAllMoves().at(ii));
				}
			}

			Gym temp(leadName, leadPokemon, level);

			leadPokemon.clear();

			this->gymLeaders.push_back(temp);
		}
	}

	gymIn.close();
}