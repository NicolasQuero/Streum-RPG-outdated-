#include <iostream>
#include <fstream>
#include <vector>
#include "Oueurj.h"
#include "Board.h"
#include "GameMap.h"

using namespace std;



int main() {
    const string MAP_PATH = "maps/maptest.txt";

    GameMap mapTest = GameMap(MAP_PATH);
    Board board = Board(mapTest.getMapStrings());
    board.printMap();
    /*vector<string> mapStrings(mapTest.getMapStrings());
    for (string line : mapStrings) {
        cout << line << endl;
    }*/

    return 0;
}

