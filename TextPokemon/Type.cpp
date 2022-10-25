#include "Type.h"

Type::Type()
{
	this->type = "NONE";
}

Type::Type(std::string type, std::vector <std::string> weakness, std::vector <std::string> resist, std::vector <std::string> immune)
{
	this->type = type;
	this->weakness = weakness;
	this->resist = resist;
	this->immune = immune;
}

Type::~Type()
{

}

void Type::initTypes()
{
	std::ifstream typeIn;
	typeIn.open("Types.txt");

	std::string name = "";
	std::string type = "";
	std::string tyTemp = "";
	std::vector <std::string> weaknessV;
	std::vector <std::string> resistV;
	std::vector <std::string> immuneV;

	std::string line = "";
	std::stringstream str;

	if (typeIn.is_open())
	{
		while (std::getline(typeIn, line))
		{
			str.str(line);
			str >> name;
			str >> type;
			for (size_t i = 0; i < 5; i++)
			{
				str >> tyTemp;
				if (tyTemp != "NULL")
					weaknessV.push_back(tyTemp);
			}
			for (size_t i = 0; i < 11; i++)
			{
				str >> tyTemp;
				if (tyTemp != "NULL")
					resistV.push_back(tyTemp);
			}
			for (size_t i = 0; i < 2; i++)
			{
				str >> tyTemp;
				if (tyTemp != "NULL")
					immuneV.push_back(tyTemp);
			}
			str.clear();
			line.clear();

			Type temp(type, weaknessV, resistV, immuneV);

			weaknessV.clear();
			resistV.clear();
			immuneV.clear();

			this->allTypes.push_back(temp);
		}
	}

	typeIn.close();
}