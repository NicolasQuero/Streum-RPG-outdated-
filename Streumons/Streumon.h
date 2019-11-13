#ifndef STREUMON_H_INCLUDED
#define STREUMON_H_INCLUDED
#include <iostream>
#include "../Pos.h"
#include "../Oueurj.h"

class Streumon {
protected:
    Streumon(char monsterLetter, int x = -1, int y = -1, int hp = 1);
    int hp;
    char type;
    bool isAlive;

public:
    Pos pos;
    virtual void act(Oueurj &J) = 0;
    int getHp() const;
    void addHp(int amount);

};



#endif // STREUMON_H_INCLUDED
