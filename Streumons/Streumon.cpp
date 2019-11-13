#include <iostream>
#include "../Pos.h"
#include "Streumon.h"


Streumon::Streumon(char monsterLetter, int x, int y, int hp) : pos( Pos(x, y) ), hp(hp), type(monsterLetter) {};

void Streumon::addHp(int amount) {
    hp += amount;
    if (hp < 0)
        isAlive = false;
}

int Streumon::getHp() const { return hp; }

