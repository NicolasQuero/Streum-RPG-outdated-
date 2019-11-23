#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
#include <iostream>
#include <vector>
#include "Streumons/Streumon.h"

using namespace std;

class Board {
private:
    vector<vector<char>> charMap;
    const vector<char> monsterPossibleLetters = {'s', 'S', 'e', 'E', 'o', 'O'}; // vector of the possible letters associated to a monster
    vector<Streumon*> monstersOnMap; // Un vector d'objets abstraits doit être un vector de pointeurs
    Oueurj J;
    Pos playerPos;

public:
    static bool gameOn;
    static void setGameOn(bool a) {gameOn = a;};
    Board(vector<string> mapStrings);
    void addMonster(char c, int i, int j);
    void setCharMaps(vector<string> mapStrings);
    void setPlayer(Oueurj &J);
    char getCharAt(int &x, int &y) const;
    void printMap() const ;
    bool playTurn();
    ~Board();

};


#endif // BOARD_H_INCLUDED
