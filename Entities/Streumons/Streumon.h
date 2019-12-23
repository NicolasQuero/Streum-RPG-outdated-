#ifndef STREUMON_H_INCLUDED
#define STREUMON_H_INCLUDED
#include <iostream>
#include <vector>
#include "../Pos.h"
#include "../Entity.h"

class Streumon : public Entity {
protected:
    Streumon(char monsterLetter, int x = -1, int y = -1, int hp = 1, int dmg = 1);

public:
    virtual void act(Entity &J, vector<vector<char>> &charMap, vector<Entity*> &streumons) = 0;
    ~Streumon() {};
};



#endif // STREUMON_H_INCLUDED