
#include "Battle.h"

void combat(Character *myChar, Rival *myRival)
{   
    std::cout << "\n" << myRival->getRivalName() << " attacks!\n\n";

    std::cout << "Press Enter to Continue...";
    std::cin.ignore();
    std::cin.get();

    bool pokemonLeft = true;
    bool myTurn = true;

    while (pokemonLeft)
    {
        int userChoice;
        int attackNum;
        int itemNum;
        int pokemonNum;

        system("CLS");
        combatDisplay(myChar->getActivePokemon(), myRival->getActivePokemon());
        do
        {
            std::cout << "Please Select (1 - 4): ";
            std::cin >> userChoice;
            switch (userChoice)
            {
            case 1:
                attackNum = displayMoves(myChar->getActivePokemon());
                if (attackNum != 0)
                {   
                    attack(myChar, myRival, attackNum);
                    myTurn = false;
                    
                }
                else
                {
                    myTurn = true;
                }
                break;
            case 2:
                pokemonNum = displayPokemon(myChar);
                break;
            case 3:
                itemNum = displayInventory(myChar->getInventory());
                if (itemNum != 0)
                {
                    myTurn = false;
                }
                else
                {
                    myTurn = true;
                }
                break;
            case 4:
                std::cout << "You Cannot Run. Please Select Again.\n";
                break;
            default:
                std::cout << "Invalid Selection. Please Select Again.\n";
                break;
            }
        } while (myTurn);
    }   
}

void combat(Character& myChar)
{

}

int displayPokemon(Character* myChar)
{
    std::string dispPokemon = "";
    int userChoice;

    if (myChar->getPokemon().size() > 0)
    {

        for (int i = 0; i < myChar->getPokemon().size(); i++)
        {
            dispPokemon += std::to_string(i + 1) + ": " + myChar->getPokemon().at(i).getName() + "\n";
        }

        std::cout << std::setfill('=') << std::setw(70) << " " << std::endl;

        std::cout << dispPokemon;

        std::cout << std::setfill('=') << std::setw(70) << " " << std::endl;

        std::cout << "Please Choose (1 - " << myChar->getPokemon().size() << " or 0 to Cancel): ";
        std::cin >> userChoice;
    }
    else
    {
        userChoice = 0;
    }

    return userChoice;
}

int displayInventory(Inventory myInv)
{
    int userChoice;
    std::stringstream items;

    for (int i = 0; i < myInv.getItems().size(); i++)
    {
        items << std::setw(20) << std::left << std::string(std::to_string(i + 1) + ": " + myInv.getItemName(i)) << std::setw(10) << std::left << std::string("Qty: " + std::to_string(myInv.getNumOwned(i))) << "\n";
    }

    std::cout << std::setfill('=') << std::setw(70) << " " << std::endl;

    std::cout << items.str();

    std::cout << std::setfill('=') << std::setw(70) << " " << std::endl;

    std::cout << "Please Choose (1 - " << myInv.getItems().size() << " or 0 to Cancel): ";
    std::cin >> userChoice;

    return userChoice;
}

int displayMoves(Pokemon* pokemon)
{
    int userChoice;
    std::string moves = "";

    for (int i = 0; i < pokemon->getNumSkills(); i++)
    {
        moves += std::to_string(i + 1) + ": " + pokemon->getSkill(i).getSkillName() + " ";
    }

    std::cout << std::setfill('=') << std::setw(70) << " " << std::endl;

    std::cout << std::string((70 - moves.size()) / 2, ' ');
    std::cout << moves << std::endl;

    std::cout << std::setfill('=') << std::setw(70) << " " << std::endl;

    std::cout << "Please Choose (1 - " << pokemon->getNumSkills() << " or 0 to Cancel): ";
    std::cin >> userChoice;

    return userChoice;
}

void combatDisplay(Pokemon *myPokemon, Pokemon *enemyPokemon)
{
    std::string combatActions[4] = { "Fight", "Pokemon", "Item", "Run"};
    std::string actions;

    std::cout << std::setfill('=') << std::setw(70) << " " << std::endl;

    std::cout << std::string((70 - 9) / 2, ' ');
    std::cout << "COMBAT!!!" << std::endl;

    std::cout << std::setfill('=') << std::setw(70) << " " << std::endl;

    std::cout << std::setfill('=') << std::setw(70) << " " << std::endl;

    std::cout << std::string((70 - myPokemon->getName().size()) / 2, ' ');
    std::cout << myPokemon->getName() << std::endl;
    std::cout << std::string((70 - std::to_string(myPokemon->getLevel()).length() - 5) / 2, ' ');
    std::cout << "LVL: " << myPokemon->getLevel() << std::endl;
    std::cout << std::string((70 - std::to_string(myPokemon->getHp()).length() - std::to_string(myPokemon->getMaxHp()).length() - 7) / 2, ' ');
    std::cout << "HP: " << myPokemon->getHp() << " / " << myPokemon->getMaxHp() << std::endl;

    std::cout << std::setfill('=') << std::setw(70) << " " << std::endl;

    std::cout << std::setfill('=') << std::setw(70) << " " << std::endl;

    std::cout << std::string((70 - enemyPokemon->getName().size()) / 2, ' ');
    std::cout << enemyPokemon->getName() << std::endl;
    std::cout << std::string((70 - std::to_string(enemyPokemon->getLevel()).length() - 5) / 2, ' ');
    std::cout << "LVL: " << enemyPokemon->getLevel() << std::endl;
    std::cout << std::string((70 - std::to_string(enemyPokemon->getHp()).length() - std::to_string(enemyPokemon->getMaxHp()).length() - 7) / 2, ' ');
    std::cout << "HP: " << enemyPokemon->getHp() << " / " << enemyPokemon->getMaxHp() << std::endl;

    std::cout << std::setfill('=') << std::setw(70) << " " << std::endl;

    std::cout << std::setfill('=') << std::setw(70) << " " << std::endl;

    std::cout << std::string((70 - 8) / 2, ' ');
    std::cout << "ACTIONS:" << std::endl;

    for (int index = 0; index < 4; index++)
    {
        if (index == 0)
            actions = std::to_string(index + 1) + ": " + combatActions[index];
        else
            actions += std::string(5, ' ') + std::to_string(index + 1) + ": " + combatActions[index];
    }

    std::cout << std::string((70 - actions.size()) / 2, ' ');
    std::cout << actions << std::endl;

    std::cout << std::setfill('=') << std::setw(70) << " " << std::endl << std::endl;
}

void attack(Character* myChar, Rival* myRival, int attackNum)
{
    int damage;
    int defense;
    int attack;
    int randAttack;
    int critRand = rand() % 255 + 1;
    double typeMult;
    double critMult;
    bool weak = false;
    bool resist = false;

    attackNum--;

    std::string attackType = myChar->getActivePokemon()->getSkill(attackNum).getSkillType();
    
    if (attackType == "NORMAL" || attackType == "FIGHTING" || attackType == "FLYING" || attackType == "GROUND" ||
        attackType == "ROCK" || attackType == "BUG" || attackType == "GHOST" || attackType == "POISON" || attackType == "STEEL")
    {
        defense = myRival->getActivePokemon()->getDef();
        attack = myChar->getActivePokemon()->getAtk();
    }
    else
    {
        defense = myRival->getActivePokemon()->getSpDef();
        attack = myChar->getActivePokemon()->getSpAtk();
    }

    if (critRand < myChar->getActivePokemon()->getSpeed() / 2)
        critMult = (2 * myChar->getActivePokemon()->getLevel() + 5) / (myChar->getActivePokemon()->getLevel() + 5);
    else
        critMult = 1;

    for (size_t i = 0; i < myRival->getActivePokemon()->getWeak().size() && !weak; i++)
    {
        if (myRival->getActivePokemon()->getWeak().at(i) == myChar->getActivePokemon()->getSkill(attackNum).getSkillType())
            weak = true;
    }

    for (size_t i = 0; i < myRival->getActivePokemon()->getResist().size() && !weak && !resist; i++)
    {
        if (myRival->getActivePokemon()->getResist().at(i) == myChar->getActivePokemon()->getSkill(attackNum).getSkillType())
            resist = true;
    }


    if (weak)
        typeMult = 2;
    else if (resist)
        typeMult = 0.5;
    else
        typeMult = 1;

    std::cout << myChar->getCharName() << " attacks with " << myChar->getActivePokemon()->getSkill(attackNum).getSkillName() << "\n";

    damage = (int)(((((2 * myChar->getActivePokemon()->getLevel() * critMult) / 5 + 2) * myChar->getActivePokemon()->getSkill(attackNum).getSkillPower() * attack / defense) / 15 + 2) * typeMult * (rand() % 38 + 217) / 255);

    myRival->getActivePokemon()->takeDamage(damage);

    if (weak)
        std::cout << "It is Super Effective!\n";
    else if (resist)
        std::cout << "It is Not Very Effective.\n";

    std::cout << "It hits for " << damage << " damage.\n\n";

    critRand = rand() % 255 + 1;

    randAttack = rand() % myRival->getActivePokemon()->getNumSkills();

    attackType = myRival->getActivePokemon()->getSkill(randAttack).getSkillType();

    if (attackType == "NORMAL" || attackType == "FIGHTING" || attackType == "FLYING" || attackType == "GROUND" ||
        attackType == "ROCK" || attackType == "BUG" || attackType == "GHOST" || attackType == "POISON" || attackType == "STEEL")
    {
        defense = myChar->getActivePokemon()->getDef();
        attack = myRival->getActivePokemon()->getAtk();
    }
    else
    {
        defense = myChar->getActivePokemon()->getSpDef();
        attack = myRival->getActivePokemon()->getSpAtk();
    }

    if (critRand < myRival->getActivePokemon()->getSpeed() / 2)
        critMult = (2 * myRival->getActivePokemon()->getLevel() + 5) / (myRival->getActivePokemon()->getLevel() + 5);
    else
        critMult = 1;

    for (size_t i = 0; i < myChar->getActivePokemon()->getWeak().size() && !weak; i++)
    {
        if (myChar->getActivePokemon()->getWeak().at(i) == myRival->getActivePokemon()->getSkill(randAttack).getSkillType())
            weak = true;
    }

    for (size_t i = 0; i < myChar->getActivePokemon()->getResist().size() && !weak && !resist; i++)
    {
        if (myChar->getActivePokemon()->getResist().at(i) == myRival->getActivePokemon()->getSkill(randAttack).getSkillType())
            resist = true;
    }

    if (weak)
        typeMult = 1.5;
    else if (resist)
        typeMult = 0.5;
    else
        typeMult = 1;

    std::cout << myRival->getRivalName() << " attacks with " << myRival->getActivePokemon()->getSkill(randAttack).getSkillName() << "\n";

    damage = (int)(((((2 * myRival->getActivePokemon()->getLevel() * critMult) / 5 + 2) * myRival->getActivePokemon()->getSkill(randAttack).getSkillPower() * attack / defense) / 50 + 2) * typeMult * (rand() % 38 + 217) / 255);

    myChar->getActivePokemon()->takeDamage(damage);

    if (weak)
        std::cout << "It is Super Effective!\n";
    else if (resist)
        std::cout << "It is Not Very Effective.\n";

    std::cout << "It hits for " << damage << " damage.\n";


    std::cout << "Press Enter to Continue...";
    std::cin.ignore();
    std::cin.get();
}