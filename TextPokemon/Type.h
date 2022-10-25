#ifndef __TYPE_H__
#define __TYPE_H__

#include "InclLib.h"

class Type
{
private:
    std::string type;
    std::vector <std::string> weakness;
    std::vector <std::string> resist;
    std::vector <std::string> immune;
public:
    Type();
    ~Type();
    inline void setType(std::string type) { this->type = type; }
    inline void setWeakness(std::vector <std::string> weakness) { this->weakness = weakness; }
    inline void setResist(std::vector <std::string> resist) { this->resist = resist; }
    inline void setImmune(std::vector <std::string> immune) { this->immune = immune; }
    inline std::string getType() { return this->type; }
    inline std::vector <std::string> getWeakness() { return this->weakness; }
    inline std::vector <std::string> getResist() { return this->resist; }
    inline std::vector <std::string> getImmune() { return this->immune; }
    std::vector <Type> allTypes;
    void popTypes();
};
#endif