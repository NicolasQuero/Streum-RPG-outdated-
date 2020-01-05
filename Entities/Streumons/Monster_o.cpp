#include <iostream>
#include <stdlib.h>

#include "Monster_o.h"
#include "Streumon.h"
#include "../Entity.h"
#include "../Pos.h"
#include "../../Combat.h"

using namespace std;

const int Monster_o::HP_MAX = 2;
const int Monster_o::BASE_DMG = 1;
const double Monster_o::DETECTION_RADIUS = 20;

Monster_o::Monster_o(int x, int y) : Streumon('o', x, y, HP_MAX, BASE_DMG) {}

void Monster_o::act(Entity &J, vector<vector<char>> &charMap, vector<Entity*> &streumons) {
    moveMonster(J, charMap, streumons);
}

void Monster_o::moveMonster(Entity &J, vector<vector<char>> &charMap, vector<Entity*> &streumons) {
    bool moved = false;
    if ( J.pos.dist(this->pos) < DETECTION_RADIUS ) { // Si le joueur est à une distance inférieure au rayon de détection
        int rand2 = rand()%3; // On choisit un nombre rand2 au hasard entre 1 et 2
        if (rand2 == 0) { // Pour rand2 == 0 on tente de se rapprocher du joueur sur l'axe des abscisses
            moved = moveMonsterInX(J, charMap, streumons);
            if (!moved) // moved vaut false si le déplacement a échoué, on essaye alors de se rapprocher sur l'axe des ordonnées
                moveMonsterInY(J, charMap, streumons);
        }
        else if (rand2 == 1) { // Pour rand2 == 1, on fait la même chose en commençant par l'axe Y au lieu de l'axe X
            moved = moveMonsterInY(J, charMap, streumons);
            if (!moved)
                moveMonsterInX(J, charMap, streumons);
        }
        else if (rand2 == 2) {
            moveMonsterAtRandom(J, charMap, streumons);
        }
    }
}

bool Monster_o::moveMonsterInX(Entity &J, vector<vector<char>> &charMap, vector<Entity*> &streumons) {
    bool moved = false;
    if (J.pos.x < this->pos.x) {
        moved = moveBy(Pos(-1,0), J, charMap, streumons);
    }
    else if (J.pos.x > this->pos.x) {
        moved = moveBy(Pos(1,0), J, charMap, streumons);
    }
    return moved;
}

/*bool Monster_o::moveX(int movement, Entity &J, vector<vector<char>> &charMap, vector<Entity*> &streumons) { // returns true if it could move, false otherwise
    if ( charMap[this->pos.x + movement][this->pos.y] == '#' || charMap[this->pos.x + movement][this->pos.y] == 'X') { // WALL DETECTED
        return false;
    }
    else {
        for (Entity* streumon : streumons) {
            if (streumon->pos.x == this->pos.x + movement && streumon->pos.y == pos.y) { // OTHER MONSTER AT TARGET LOCATION
                return false;
            }
        }
        if (J.pos.x == this->pos.x + movement && J.pos.y == this->pos.y) { // START COMBAT WITH PLAYER
            Combat newCombat = Combat(*this, J);
            return newCombat.startCombat();
        }
    }
    this->pos.x += movement; // NO COLLISION, MOVEMENT IS DONE
    return true;
}*/

bool Monster_o::moveMonsterInY(Entity &J, vector<vector<char>> &charMap, vector<Entity*> &streumons) {
    bool moved = false;
    if (J.pos.y < this->pos.y) {
        moved = moveBy(Pos(0,-1), J, charMap, streumons);
    }
    else if (J.pos.y > this->pos.y) {
        moved = moveBy(Pos(0,1), J, charMap, streumons);
    }
    return moved;
}

/*bool Monster_o::moveY(int movement, Entity &J, vector<vector<char>> &charMap, vector<Entity*> &streumons) {
    if ( charMap[this->pos.x][this->pos.y + movement] == '#' || charMap[this->pos.x][this->pos.y + movement] == 'X') { // WALL DETECTED
        return false;
    }
    else {
        for (Entity* streumon : streumons) {
            if (streumon->pos.y == this->pos.y + movement && streumon->pos.x == pos.x) // OTHER MONSTER AT TARGET LOCATION
                return false;
        }
        if (J.pos.y == this->pos.y + movement && J.pos.x == this->pos.x) { // START COMBAT WITH PLAYER
            cout << "start combat" << endl;
            return false;
        }
    }
    this->pos.y += movement; // NO COLLISION, MOVEMENT IS DONE
    return true;
}*/

bool Monster_o::moveBy(Pos movement, Entity &J, vector<vector<char>> &charMap, vector<Entity*> &streumons) {
    Pos targetPos = this->pos + movement;
    if ( charMap[targetPos.x][targetPos.y] == '#' || charMap[targetPos.x][targetPos.y] == 'X') { // WALL DETECTED
        return false;
    }
    else {
        for (Entity* streumon : streumons) {
            if (streumon->pos.y == targetPos.y && streumon->pos.x == targetPos.x) // OTHER MONSTER AT TARGET LOCATION
                return false;
        }
        if (J.pos.y == targetPos.y && J.pos.x == targetPos.x) { // START COMBAT WITH PLAYER
            Combat newCombat = Combat(*this, J);
            cout << "COMBAT" << endl;
            newCombat.startCombat();
            return true;

        }
    }
    this->pos += movement; // NO COLLISION, MOVEMENT IS DONE
    return true;
}

bool Monster_o::moveMonsterAtRandom(Entity &J, vector<vector<char>> &charMap, vector<Entity*> &streumons) {
    int rand9 = rand()%9;
    moveBy(DEPLACEMENTS_POS[rand9], J, charMap, streumons);
}

bool Monster_o::playCombatTurn(Entity &E) {
    return true;
}
