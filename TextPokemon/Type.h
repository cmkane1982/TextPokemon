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
    Type(std::string type, std::vector <std::string> weakness, std::vector <std::string> resist, std::vector <std::string> immune);
    ~Type();
    
    inline std::string getType() { return this->type; }
    inline std::vector <std::string> getWeakness() { return this->weakness; }
    inline std::vector <std::string> getResist() { return this->resist; }
    inline std::vector <std::string> getImmune() { return this->immune; }
    
    void initTypes();
    
    std::vector <Type> allTypes;
};
#endif