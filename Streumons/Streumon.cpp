#include <iostream>
#include <vector>
#include "../Pos.h"
#include "../Oueurj.h"
#include "Streumon.h"

using namespace std;


Streumon::Streumon(char monsterLetter, int x, int y, int hp) : pos( Pos(x, y) ), hp(hp), type(monsterLetter) {
    cout << monsterLetter << " " << pos << endl;
}

void Streumon::addHp(int amount) {
    hp += amount;
    if (hp < 0)
        isAlive = false;
}

int Streumon::getHp() const { return hp; }

char Streumon::getType() const { return type; }