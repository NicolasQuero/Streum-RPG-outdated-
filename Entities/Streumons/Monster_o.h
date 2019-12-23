#ifndef MONSTER_O_H_INCLUDED
#define MONSTER_O_H_INCLUDED
#include <iostream>
#include "Streumon.h"
#include "../Oueurj.h"

class Monster_o: public Streumon {
private:
    const static int HP_MAX;
    const static int BASE_DMG;
public:
    Monster_o(int x = -1, int y = -1);
    void act(Entity &J, vector<vector<char>> &charMap, vector<Entity*> &streumons); // Il faut définir la fonction abstraite implémentée
    bool playCombatTurn(Entity &E);

};


#endif // MONSTER_O_H_INCLUDED
