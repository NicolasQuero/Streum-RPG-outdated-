#include <iostream>
#include <fstream>
#include <vector>
#include "Oueurj.h"
#include "Board.h"
#include "GameMap.h"

#include <windows.h>
#pragma execution_character_set( "utf-8" )

using namespace std;



int main() {
    SetConsoleOutputCP( 1252 ); // Pour afficher les accents dans le terminal

    const string MAP_TEST = "maps/maptest.txt";

    GameMap mapTest = GameMap(MAP_TEST);
    Board board = Board(mapTest);

    board.printMap();
    int turn = 0;
    cout << endl << "****************** La partie débute, nous sommes au tour " << turn << " ******************" << endl << endl;
    while (board.gameOn && board.playTurn()) {
        turn ++;
        cout << endl << "****************** Le tour " << turn << " est terminé. ******************" << endl << endl;
        board.printMap();
    }

    return 0;
}

