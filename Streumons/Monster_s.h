#ifndef MONSTER_S_H_INCLUDED
#define MONSTER_S_H_INCLUDED
#include <iostream>
#include <vector>
#include "Streumon.h"
#include "../Oueurj.h"

class Monster_s: public Streumon {
private:
    int base_hp = 1;
public:
    Monster_s(int x = -1, int y = -1);
    void act(Oueurj &J, vector<vector<char>> charMap, vector<Streumon*> streumons){}; // Il faut définir la fonction abstraite implémentée


};



#endif // MONSTER_S_H_INCLUDED
