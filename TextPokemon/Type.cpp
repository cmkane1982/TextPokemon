#include "Type.h"

Type::Type()
{
	this->type = "NONE";
}

Type::~Type()
{

}

void Type::popTypes()
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
			Type temp;

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

			temp.setType(type);
			temp.setWeakness(weaknessV);
			temp.setResist(resistV);
			temp.setImmune(immuneV);

			weaknessV.clear();
			resistV.clear();
			immuneV.clear();

			this->allTypes.push_back(temp);
		}
	}

	typeIn.close();
}