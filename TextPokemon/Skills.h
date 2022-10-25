#ifndef __SKILLS_H__
#define __SKILLS_H__

#include "InclLib.h"

class Skills
{
private:
    int index;
    std::string name;
    std::string type;
    int power;
    int acc;
    int maxUses;
    int numUses;
public:
    Skills(std::string name, std::string type, int power, int acc, int maxUses);
    Skills();
    virtual ~Skills();

    inline std::string getSkillName() { return this->name; }
    inline std::string getSkillType() { return this->type; }
    inline int getSkillPower() { return this->power; }
    inline int getSkillAcc() { return this->acc; }
    inline int getSkillUses() { return this->numUses; }
    inline int getMaxSkillUses() { return this->maxUses; }
    
    void useSkill();
    void resetSkillUses();
    void initSkills();

    std::vector <Skills> allSkills;
    
};
#endif