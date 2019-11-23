#ifndef MONSTER_O_H_INCLUDED
#define MONSTER_O_H_INCLUDED
#include <iostream>
#include "Streumon.h"
#include "../Oueurj.h"

class Monster_o: public Streumon {
private:
    int base_hp = 2;
public:
    Monster_o(int x = -1, int y = -1);
    void act(Oueurj &J, vector<vector<char>> charMap, vector<Streumon*> streumons); // Il faut définir la fonction abstraite implémentée


};


#endif // MONSTER_O_H_INCLUDED
