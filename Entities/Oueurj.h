#ifndef OUEURJ_H_INCLUDED
#define OUEURJ_H_INCLUDED
#include <iostream>
#include <vector>
#include "Entity.h"
#include "Pos.h"

class Oueurj : public Entity {
private:
    const static int HP_MAX, BASE_DMG;
    int teleportsLeft;
    static const Pos DEPLACEMENTS_POS [];
public:
    Oueurj();
    Oueurj(Pos p);
    Oueurj(int x, int y);
    int getTeleportsLeft() const { return teleportsLeft; }
    bool useTeleport(int x, int y) { return false; } // Fonction à définir
    bool quitGame() const;
    int monsterIndexAt(Pos target, vector<Entity*> &streumons);
    bool manageChoice(string choice, vector<vector<char>> &charMap, vector<Entity*> &streumons);
    void movePlayer(int deplacement, vector<vector<char>> &charMap, vector<Entity*> &streumons);
    void act(Entity &J, vector<vector<char>> &charMap, vector<Entity*> &streumons);
    bool playCombatTurn(Entity &E);
    ~Oueurj() {};

};


#endif // OUEURJ_H_INCLUDED
