#include <iostream>

#include "Monster_o.h"
#include "Streumon.h"

class Streumon;

using namespace std;

Monster_o::Monster_o(int x, int y) : Streumon('o', x, y, base_hp) {};

void Monster_o::act(Oueurj &J, vector<vector<char>> charMap, vector<Streumon*> streumons) {

}

