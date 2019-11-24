#ifndef OUEURJ_H_INCLUDED
#define OUEURJ_H_INCLUDED
#include <iostream>
#include <vector>
#include "Streumons/Streumon.h"
#include "Pos.h"

class Streumon;

class Oueurj {
private:
    const static int HP_MAX;
    int hp, teleportsLeft;
    bool is_alive;
    static const Pos DEPLACEMENTS_POS [];
public:
    Pos pos;
    Oueurj();
    Oueurj(Pos p);
    Oueurj(int x, int y);
    int getHp() const { return hp; }
    int getTeleportsLeft() const { return teleportsLeft; }
    void inflictDamage(int dmg) {
        hp -= dmg;
        if (hp < 0)
            is_alive = false;
    }
    bool isAlive() const { return is_alive; }
    bool quitGame() const;
    char whichMonsterAt(Pos target, vector<Streumon*> &streumons);
    bool manageChoice(string choice, vector<vector<char>> &charMap, vector<Streumon*> &streumons);
    void movePlayer(int deplacement, vector<vector<char>> &charMap, vector<Streumon*> &streumons);
    void act(vector<vector<char>> &charMap, vector<Streumon*> &streumons);


};


#endif // OUEURJ_H_INCLUDED
