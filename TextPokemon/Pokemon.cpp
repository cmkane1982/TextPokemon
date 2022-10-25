#include "Pokemon.h"

Pokemon::Pokemon()
{
	this->name = "NONE";
	this->maxSkills = 4;
	this->numSkills = 0;
	this->level = 1;
	this->maxHp = 0;
	this->hp = 0;
	this->atk = 0;
	this->def = 0;
	this->spAtk = 0;
	this->spDef = 0;
	this->speed = 0;
	this->exp = 0;
	this->evoLvl = 0;
}

Pokemon::Pokemon(std::string name, std::vector<std::string>type, std::vector<std::string>weak, std::vector<std::string>resist,
				 std::vector<std::string>immune, int maxHp, int atk, int def, int spAtk, int spDef, int speed, int rate,
				 int evoLvl, int evoPokeIndex, int baseExp)
{
	this->name = name;
	this->type = type;
	this->weak = weak;
	this->resist = resist;
	this->immune = immune;
	this->maxHp = maxHp;
	this->hp = maxHp;
	this->atk = atk;
	this->def = def;
	this->spAtk = spAtk;
	this->spDef = spDef;
	this->speed = speed;
	this->capRate = rate;
	this->evoLvl = evoLvl;
	this->evoPokeIndex = evoPokeIndex;
	this->baseExp = baseExp;
	this->level = 1;
	this->exp = 0;
	this->maxSkills = 4;
	this->numSkills = 0;
}

Pokemon::~Pokemon()
{
	
}

void Pokemon::addSkill(Skills skill)
{
	/*if (this->skillV.size() + 1 > this->maxSkills)
	{
		int userChoice;

		std::cout << "Your Pokemon is trying to learn " << skill.getSkillName() << "\n";
		std::cout << "However, your Pokemon can't learn more than 4 moves.\n";
		std::cout << "Which move would you like to replace?\n\n";
		for (size_t i = 0; i < this->skillV.size(); i++)
		{
			std::cout << std::to_string(i + 1) << ": " << this->skillV.at(i).getSkillName() << " ";
		}
		std::cout << "\n\nPlease Choose (1-4 or 0 for None): ";
		std::cin >> userChoice;
		
		if (userChoice != 0)
		{
			this->skillV.erase(this->skillV.begin() + (userChoice - 1));
			this->skillV.push_back(skill);
		}		
	}
	else*/
		this->allMoves.push_back(skill);
}

void Pokemon::gainExp(int exp)
{
	/*
	* 
	* Formula for exp gain = 
	* 
	* 
	* 
	*
	*/

	this->exp += exp;

	while (this->exp > std::pow(this->level, 3) * 4 / 5)
		this->levelUp();
}

void Pokemon::levelUp()
{
	this->level++;
	this->maxHp += 2;
	this->hp = this->maxHp;
	this->atk++;
	this->def++;
	this->spAtk++;
	this->spDef++;
	this->speed++;
}

void Pokemon::levelUp(int level)
{
	int numLevels = level - this->level;

	this->level = level;
	this->maxHp += 2 * numLevels;
	this->hp = this->maxHp;
	this->atk += numLevels;
	this->def += numLevels;
	this->spAtk += numLevels;
	this->spDef += numLevels;
	this->speed += numLevels;
}

void Pokemon::initPokemon()
{
	initSkills();
	popTypes();
	std::ifstream pokemonIn;
	pokemonIn.open("Pokemon.txt");

	std::string line = "";
	std::stringstream str;
	
	if (pokemonIn.is_open())
	{
		while (std::getline(pokemonIn, line))
		{
			std::string name = "";
			std::vector <std::string> type;
			std::vector <std::string> weak;
			std::vector <std::string> resist;
			std::vector <std::string> immune;
			int hp = 0;
			int atk = 0;
			int def = 0;
			int spAtk = 0;
			int spDef = 0;
			int speed = 0;
			int rate = 0;
			int evoLvl = 0;
			int evoPokeIndex = 0;
			int baseExp = 0;
			std::vector <int> moves;
			std::string ttemp;
			int mTemp;

			str.str(line);
			str >> name;
			for (size_t i = 0; i < 2; i++)
			{
				str >> ttemp;
				if (ttemp != "NULL")
					type.push_back(ttemp);
			}
			str >> hp;
			str >> atk;
			str >> def;
			str >> spAtk;
			str >> spDef;
			str >> speed;
			str >> rate;
			str >> evoLvl;
			str >> evoPokeIndex;
			str >> baseExp;
			for (size_t i = 0; i < 7; i++)
			{
				str >> mTemp;
				if (mTemp >= 0)
					moves.push_back(mTemp);
			}

			str.clear();
			line.clear();
			
			
			for (size_t i = 0; i < type.size(); i++)
			{
				auto it = find_if(this->allTypes.begin(), this->allTypes.end(), [type, i](Type& obj) {return obj.getType() == type.at(i); });

				if (it != this->allTypes.end())
				{
					auto index = std::distance(this->allTypes.begin(), it);
					std::vector <std::string> tempWeak = this->allTypes.at(index).getWeakness();
					std::vector <std::string> tempResist = this->allTypes.at(index).getResist();
					std::vector <std::string> tempImmune = this->allTypes.at(index).getImmune();

					weak.insert(weak.end(), tempWeak.begin(), tempWeak.end());
					resist.insert(resist.end(), tempResist.begin(), tempResist.end());
					immune.insert(immune.end(), tempImmune.begin(), tempImmune.end());
				}
			}

			std::sort(weak.begin(), weak.end());
			std::sort(resist.begin(), resist.end());
			std::sort(immune.begin(), immune.end());

			weak.erase(unique(weak.begin(), weak.end()), weak.end());
			resist.erase(unique(resist.begin(), resist.end()), resist.end());
			immune.erase(unique(immune.begin(), immune.end()), immune.end());

			std::vector <std::string> tempV;

			std::set_intersection(weak.begin(), weak.end(), resist.begin(), resist.end(), std::back_inserter(tempV));

			for (size_t i = 0; i < tempV.size(); i++)
			{
				auto it = find_if(weak.begin(), weak.end(), [tempV, i](std::string& obj) {return obj == tempV.at(i); });
				if (it != weak.end())
					weak.erase(it);

				it = find_if(resist.begin(), resist.end(), [tempV, i](std::string& obj) {return obj == tempV.at(i); });
				if (it != resist.end())
					resist.erase(it);
			}

			tempV.clear();

			std::set_intersection(weak.begin(), weak.end(), immune.begin(), immune.end(), std::back_inserter(tempV));

			for (size_t i = 0; i < tempV.size(); i++)
			{
				auto it = find_if(weak.begin(), weak.end(), [tempV, i](std::string& obj) {return obj == tempV.at(i); });
				if (it != weak.end())
					weak.erase(it);

				it = find_if(immune.begin(), immune.end(), [tempV, i](std::string& obj) {return obj == tempV.at(i); });
				if (it != immune.end())
					immune.erase(it);
			}


			Pokemon temp(name, type, weak, resist, immune, hp, atk, def, spAtk, spDef, speed, rate, evoLvl, evoPokeIndex, baseExp);
			for (size_t i = 0; i < moves.size(); i++)
			{
				temp.addSkill(this->allSkills.at(moves.at(i)));
			}

			allPokemon.push_back(temp);
		}
	}
	pokemonIn.close();
}