
#include "Battle.h"
#include "main.h"

bool combat(Character *myChar, Rival *myRival)
{   
    std::cout << "\n" << myRival->getRivalName() << " attacks!\n\n";

    waitEnter();

    bool pokemonLeft = true;
    bool victory;

    while (pokemonLeft)
    {
        int userChoice;
        int attackNum;
        int itemNum;
        int pokemonNum;

        cls();
        combatDisplay(myChar->getActivePokemon(), myRival->getActivePokemon());

        std::cout << "Please Select (1 - 4): ";
        std::cin >> userChoice;
        switch (userChoice)
        {
        case 1:
            attackNum = displayMoves(myChar->getActivePokemon());
            if (attackNum != 0)
                attack(myChar->getActivePokemon(), myRival->getActivePokemon(), attackNum);
            break;
        case 2:
            pokemonNum = displayPokemon(myChar);
            if (myChar->getPokemon().at(pokemonNum - 1).getHp() > 0)
                myChar->setActivePokemon(pokemonNum - 1);
            else
            {
                std::cout << "That Pokemon Has Fainted.\n";
                waitEnter();
            }
            break;
        case 3:
            itemNum = displayInventory(myChar->getInventory());
            //if (itemNum != 0)
            break;
        case 4:
            std::cout << "You Cannot Run. Please Select Again.\n";
            waitEnter();
            break;
        default:
            std::cout << "Invalid Selection. Please Select Again.\n";
            waitEnter();
            break;
        }

        if (myChar->getActivePokemon()->getHp() <= 0)
        {
            bool livePokemon = false;

            std::cout << myChar->getActivePokemon()->getName() << " Has Fainted.\n";
            
            for (size_t i = 0; i < myChar->getPokemon().size() && !livePokemon; i++)
            {
                if (myChar->getPokemon().at(i).getHp() > 0)
                    livePokemon = true;
            }

            if (livePokemon)
            {
                bool validChoice = false;

                do
                {
                    pokemonNum = displayPokemon(myChar);
                    if (pokemonNum == 0)
                    {
                        std::cout << "You Cannot Cancel.\n";
                        waitEnter();
                    }
                    else if (myChar->getPokemon().at(pokemonNum - 1).getHp() > 0)
                    {
                        myChar->setActivePokemon(pokemonNum - 1);
                        validChoice = true;
                    }
                    else
                    {
                        std::cout << "That Pokemon Has Fainted.\n";
                        waitEnter();
                    }
                } while (!validChoice);
            }
            else
            {
                std::cout << "You Have No More Pokemon.\n";
                waitEnter();
                cls();
                std::cout << myRival->getRivalName() << ": HAHAHAHA! LOSER! I TOLD YOU I'M BETTER!\n";
                pokemonLeft = false;
                victory = false;
            }

        }

        if (myRival->getActivePokemon()->getHp() <= 0)
        {
            if (myRival->getPokemon().at(0).getHp() > 0)
            {
                myRival->setActivePokemon(0);
            }
            else
            {
                cls();
                std::cout << myRival->getRivalName() << ": YOU CHEATED! THAT OLD FART GAVE ME A DUD POKEMON!\n";
                pokemonLeft = false;
                victory = true;
            }
        }
    }

    return victory;
}

bool combat(Character* myChar)
{
    Pokemon randPokemon;
    int randNum;
    int randLvl;

    randLvl = rand() % 5 - (myChar->getActivePokemon()->getLevel() - 2);
    randNum = rand() % 151;

    randPokemon.allPokemon.at(randNum).levelUp(randLvl);

    std::cout << "\nA Random " << randPokemon.allPokemon.at(randNum).getName() << " appears!\n\n";

    waitEnter();

    bool pokemonLeft = true;
    bool myTurn = true;

    while (pokemonLeft)
    {
        int userChoice;
        int attackNum;
        int itemNum;
        int pokemonNum;

        cls();
        combatDisplay(myChar->getActivePokemon(), &randPokemon.allPokemon.at(randNum));
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
                    attack(myChar->getActivePokemon(), &randPokemon.allPokemon.at(randNum), attackNum);
                    myTurn = false;

                }
                else
                {
                    myTurn = true;
                }
                break;
            case 2:
                pokemonNum = displayPokemon(myChar);
                if (myChar->getPokemon().at(pokemonNum - 1).getHp() > 0)
                    myChar->setActivePokemon(pokemonNum - 1);
                else
                    std::cout << "That Pokemon Has Fainted.\n";
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
    return true;
}

int displayPokemon(Character* myChar)
{
    std::string dispPokemon = "";
    int userChoice;

    if (myChar->getPokemon().size() > 0)
    {

        for (int i = 0; i < myChar->getPokemon().size(); i++)
        {
            dispPokemon += std::to_string(i + 1) + ": " + myChar->getPokemon().at(i).getName() + 
                " HP: " + std::to_string(myChar->getPokemon().at(i).getHp()) + " / " + 
                std::to_string(myChar->getPokemon().at(i).getMaxHp()) + "\n";
        }

        std::cout << std::setfill('=') << std::setw(70) << " " << std::endl;

        std::cout << dispPokemon;

        std::cout << std::setfill('=') << std::setw(70) << " " << std::endl;

        std::cout << "Please Choose (1 - " << myChar->getPokemon().size() << " or 0 to Cancel): ";
        std::cin >> userChoice;
    }
    else
    {
        std::cout << "You Have No Other Pokemon\n";
        waitEnter();
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

void attack(Pokemon* myPokemon, Pokemon* enemyPokemon, int attackNum)
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

    std::string attackType = myPokemon->getSkill(attackNum).getSkillType();
    
    if (attackType == "NORMAL" || attackType == "FIGHTING" || attackType == "FLYING" || attackType == "GROUND" ||
        attackType == "ROCK" || attackType == "BUG" || attackType == "GHOST" || attackType == "POISON" || attackType == "STEEL")
    {
        defense = enemyPokemon->getDef();
        attack = myPokemon->getAtk();
    }
    else
    {
        defense = enemyPokemon->getSpDef();
        attack = myPokemon->getSpAtk();
    }

    if (critRand < myPokemon->getSpeed() / 2)
        critMult = (2.0 * myPokemon->getLevel() + 5) / (myPokemon->getLevel() + 5);
    else
        critMult = 1;

    for (size_t i = 0; i < enemyPokemon->getWeak().size() && !weak; i++)
    {
        if (enemyPokemon->getWeak().at(i) == myPokemon->getSkill(attackNum).getSkillType())
            weak = true;
    }

    for (size_t i = 0; i < enemyPokemon->getResist().size() && !weak && !resist; i++)
    {
        if (enemyPokemon->getResist().at(i) == myPokemon->getSkill(attackNum).getSkillType())
            resist = true;
    }


    if (weak)
        typeMult = 2;
    else if (resist)
        typeMult = 0.5;
    else
        typeMult = 1;

    std::cout << myPokemon->getName() << " attacks with " << myPokemon->getSkill(attackNum).getSkillName() << "\n";

    damage = (int)(((((2 * myPokemon->getLevel() * critMult) / 5 + 2) * myPokemon->getSkill(attackNum).getSkillPower() * attack / defense) / 25 + 2) * typeMult * (rand() % 38 + 217) / 255);

    enemyPokemon->takeDamage(damage);

    if (weak)
        std::cout << "It is Super Effective!\n";
    else if (resist)
        std::cout << "It is Not Very Effective.\n";

    std::cout << "It hits for " << damage << " damage.\n\n";

    if (enemyPokemon->getHp() > 0)
    {
        critRand = rand() % 255 + 1;

        randAttack = rand() % enemyPokemon->getNumSkills();

        attackType = enemyPokemon->getSkill(randAttack).getSkillType();

        if (attackType == "NORMAL" || attackType == "FIGHTING" || attackType == "FLYING" || attackType == "GROUND" ||
            attackType == "ROCK" || attackType == "BUG" || attackType == "GHOST" || attackType == "POISON" || attackType == "STEEL")
        {
            defense = myPokemon->getDef();
            attack = enemyPokemon->getAtk();
        }
        else
        {
            defense = myPokemon->getSpDef();
            attack = enemyPokemon->getSpAtk();
        }

        if (critRand < enemyPokemon->getSpeed() / 2)
            critMult = (2.0 * enemyPokemon->getLevel() + 5) / (enemyPokemon->getLevel() + 5);
        else
            critMult = 1;

        for (size_t i = 0; i < myPokemon->getWeak().size() && !weak; i++)
        {
            if (myPokemon->getWeak().at(i) == enemyPokemon->getSkill(randAttack).getSkillType())
                weak = true;
        }

        for (size_t i = 0; i < myPokemon->getResist().size() && !weak && !resist; i++)
        {
            if (myPokemon->getResist().at(i) == enemyPokemon->getSkill(randAttack).getSkillType())
                resist = true;
        }

        if (weak)
            typeMult = 1.5;
        else if (resist)
            typeMult = 0.5;
        else
            typeMult = 1;

        std::cout << enemyPokemon->getName() << " attacks with " << enemyPokemon->getSkill(randAttack).getSkillName() << "\n";

        damage = (int)(((((2 * enemyPokemon->getLevel() * critMult) / 5 + 2) * enemyPokemon->getSkill(randAttack).getSkillPower() * attack / defense) / 25 + 2) * typeMult * (rand() % 38 + 217) / 255);

        myPokemon->takeDamage(damage);

        if (weak)
            std::cout << "It is Super Effective!\n";
        else if (resist)
            std::cout << "It is Not Very Effective.\n";

        std::cout << "It hits for " << damage << " damage.\n";
    }
    else
        std::cout << enemyPokemon->getName() << " Has Fainted.\n";

    waitEnter();
}