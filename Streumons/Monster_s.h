#ifndef MONSTER_S_H_INCLUDED
#define MONSTER_S_H_INCLUDED
#include <iostream>
#include "Streumon.h"
#include "../Oueurj.h"

class Monster_s: public Streumon {
private:
    const char s_char = 's';
    const int s_hp = 1;
public:
    Monster_s(int x = -1, int y = -1);
    void act(Oueurj &J){}; // Il faut définir la fonction abstraite implémentée


};



#endif // MONSTER_S_H_INCLUDED
