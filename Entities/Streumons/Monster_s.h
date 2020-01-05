#ifndef MONSTER_S_H_INCLUDED
#define MONSTER_S_H_INCLUDED
#include <iostream>
#include <vector>
#include "Streumon.h"
#include "../Oueurj.h"
#include "../Entity.h"
#include "../../GameMap.h"

class Monster_s: public Streumon {
private:
    const static int HP_MAX;
    const static int BASE_DMG;
public:
    Monster_s(int x = -1, int y = -1);
    void act(Entity &J, GameMap &gameMap, vector<vector<char>> &charMap, vector<Entity*> &streumons); // Il faut définir la fonction abstraite implémentée
    bool playCombatTurn(Entity &E);

};



#endif // MONSTER_S_H_INCLUDED
