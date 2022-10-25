#ifndef __POKEMON_H__
#define __POKEMON_H__

#include "InclLib.h"
#include "Skills.h"
#include "Type.h"

class Pokemon:
    public Skills,
    public Type
{
private:
    std::string name;
    std::vector <std::string> type;
    std::vector <std::string> weak;
    std::vector <std::string> resist;
    std::vector <std::string> immune;
    int maxSkills;
    int numSkills;
    int level;
    int maxHp;
    int hp;
    int atk;
    int def;
    int spAtk;
    int spDef;
    int speed;
    int exp;
    int capRate;
    int evoLvl;
    int evoPokeIndex;
    int baseExp;
    std::vector <Skills> allMoves;
    std::vector <Skills> currMoves;
public:
    Pokemon();
    Pokemon(std::string name, std::vector <std::string> type, std::vector <std::string> weak, std::vector <std::string> resist,
            std::vector <std::string> immune, int maxHp, int atk, int def, int spAtk, int spDef, int speed, int rate,
            int evoLvl, int evoPokeIndex, int baseExp);
    ~Pokemon();

    // Accessors
    inline std::string getName() { return this->name; }
    inline int getLevel() { return this->level; }
    inline std::vector <std::string> getType() { return this->type; }
    inline std::vector <std::string> getWeak() { return this->weak; }
    inline std::vector <std::string> getResist() { return this->resist; }
    inline std::vector <std::string> getImmune() { return this->immune; }
    inline int getMaxHp() { return this->maxHp; }
    inline int getHp() { return this->hp; }
    inline int getAtk() { return this->atk; }
    inline int getDef() { return this->def; }
    inline int getSpAtk() { return this->spAtk; }
    inline int getSpDef() { return this->spDef; }
    inline int getSpeed() { return this->speed; }
    inline int getExp() { return this->exp; }
    inline size_t getNumSkills() { return this->allMoves.size(); }
    inline Skills getSkill(int index) { return this->allMoves.at(index); }
    inline int getRate() { return this->capRate; }
    inline int getEvoLvl() { return this->evoLvl; }
    inline int getEvoPokemon() { return this->evoPokeIndex; }
    inline int getBaseExp() { return this->baseExp; }

    // Modifiers
    inline void takeDamage(int damage) { this->hp -= damage; }

    // Functions
    void addSkill(Skills skill);
    void gainExp(int exp);
    void levelUp();
    void levelUp(int level);
    void initPokemon();

    std::vector <Pokemon> allPokemon;
};
#endif