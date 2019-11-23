#ifndef STREUMON_H_INCLUDED
#define STREUMON_H_INCLUDED
#include <iostream>
#include <vector>
#include "../Pos.h"
#include "../Oueurj.h"

class Oueurj;

class Streumon {
public:
    Pos pos;
protected:
    int hp;
    char type;
    bool isAlive;
    Streumon(char monsterLetter, int x = -1, int y = -1, int hp = 1);

public:
    virtual void act(Oueurj &J, vector<vector<char>> charMap, vector<Streumon*> streumons) = 0;
    int getHp() const;
    void addHp(int amount);
    char getType() const;

};



#endif // STREUMON_H_INCLUDED
