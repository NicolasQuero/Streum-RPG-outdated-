#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
#include <iostream>
#include <vector>

using namespace std;

class Board {
private:
    vector<vector<char>> charMap, monsterMap;
    vector<char> monsterLetters;
    void setMonsterLetters();
    Oueurj J;
    Pos playerPos;

public:
    Board(vector<string> mapStrings);
    void setCharMaps(vector<string> mapStrings);
    void setPlayer(Oueurj &J);
    char getCharAt(int &x, int &y) const;
    void printMap() const ;

};


#endif // BOARD_H_INCLUDED
