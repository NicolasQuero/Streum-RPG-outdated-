#include <iostream>
#include <vector>

#include "Monster_s.h"
#include "Streumon.h"
#include "../Entity.h"

using namespace std;

const int Monster_s::HP_MAX = 1;
const int Monster_s::BASE_DMG = 1;

Monster_s::Monster_s(int x, int y) : Streumon('s', x, y, HP_MAX, BASE_DMG) {}

void Monster_s::act(Entity &J, vector<vector<char>> &charMap, vector<Entity*> &streumons) {}

bool Monster_s::playCombatTurn(Entity &E) {
    return attack(E);
}


