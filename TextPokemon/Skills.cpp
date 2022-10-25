#include "Skills.h"

Skills::Skills(std::string name, std::string type, int power, int acc, int maxUses)
{
    this->name = name;
    this->type = type;
    this->power = power;
    this->acc = acc;
    this->maxUses = maxUses;
    this->numUses = this->maxUses;
}

Skills::Skills()
{
	this->name = "NONE";
	this->type = "NONE";
	this->power = 0;
	this->acc = 0;
	this->maxUses = 0;
	this->numUses = this->maxUses;
}

Skills::~Skills()
{

}

void Skills::useSkill()
{
    if (this->numUses > 0)
        this->numUses--;
}

void Skills::resetSkillUses()
{
    numUses = maxUses;
}

void Skills::initSkills()
{
	std::ifstream skillIn;
	skillIn.open("Skills.txt");

	int index;
	std::string name = "";
	std::string type = "";
	int maxUses = 0;
	int power = 0;
	int acc = 0;

	std::string line = "";
	std::stringstream str;

	if (skillIn.is_open())
	{
		while (std::getline(skillIn, line))
		{
			str.str(line);
			str >> index;
			str >> name;
			str >> type;
			str >> maxUses;
			str >> power;
			str >> acc;
			str.clear();
			line.clear();

			Skills temp(name, type, power, acc, maxUses);

			/*temp.setSkillName(name);
			temp.setSkillType(type);
			temp.setSkillMaxUses(maxUses);
			temp.setSkillPower(power);
			temp.setSkillAcc(acc);*/

			this->allSkills.push_back(temp);
		}
	}

	skillIn.close();
}