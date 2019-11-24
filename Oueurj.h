#ifndef OUEURJ_H_INCLUDED
#define OUEURJ_H_INCLUDED
#include <iostream>
#include <vector>
#include "Streumons/Streumon.h"
#include "Pos.h"

class Streumon;

class Oueurj {
private:
    static const Pos DEPLACEMENTS_POS [];
public:
    Pos pos;
    Oueurj();
    Oueurj(Pos p);
    Oueurj(int x, int y);
    bool quitGame() const;
    bool manageChoice1(string choice, vector<vector<char>> charMap);
    void movePlayer(int deplacement, vector<vector<char>> charMap);
    void act(vector<vector<char>> charMap, vector<Streumon*> streumons);


};


#endif // OUEURJ_H_INCLUDED
