#include <iostream>
#include <vector>
#include "../Pos.h"
#include "Streumon.h"
#include "../Entity.h"

using namespace std;


Streumon::Streumon(char monsterLetter, int x, int y, int hp, int dmg) : Entity(monsterLetter, x, y, hp, dmg) {}
