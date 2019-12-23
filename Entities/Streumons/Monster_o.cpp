#include <iostream>

#include "Monster_o.h"
#include "Streumon.h"
#include "../Entity.h"

using namespace std;

const int Monster_o::HP_MAX = 2;
const int Monster_o::BASE_DMG = 1;

Monster_o::Monster_o(int x, int y) : Streumon('o', x, y, HP_MAX, BASE_DMG) {}

void Monster_o::act(Entity &J, vector<vector<char>> &charMap, vector<Entity*> &streumons) {}

bool Monster_o::playCombatTurn(Entity &E) {
    return true;
}
