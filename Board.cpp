#include <iostream>
#include "Oueurj.h"
#include "Board.h"
#include <vector>
#include <algorithm>

using namespace std;



Board::Board(vector<string> mapStrings) { // each string from the list must have the same length
    setMonsterLetters();
    setCharMaps(mapStrings); // stores the value of each character from mapText in charMap
    J = Oueurj(2, 3);
    setPlayer(J);
}

void Board::setMonsterLetters() {
    monsterLetters = {'s', 'S', 'e', 'E', 'o', 'O'};
}

void Board::setCharMaps(vector<string> mapStrings) {
    for (string line : mapStrings) { // On parcourt mapStrings avec line
        vector<char> charLine;
        vector<char> monsterLine;
        for (char c : line) { // Pour chaque caractère de line
            if (find(monsterLetters.begin(), monsterLetters.end(), c) != monsterLetters.end()) { // Si la lettre réprésente un monstre i.e. est contenue dans monsterLetters
                monsterLetters.push_back(c); // On ajoute le monstre dans monsterLine
                charLine.push_back(' '); // On ajoute la case vide de la map derrière le monstre dans charLine
            }
            else {
                monsterLine.push_back(' '); // Sinon on ajoute un caractère vide dans monsterLine
                charLine.push_back(c); // Et le caractère dans la charLine
            }
        }
        charMap.push_back(charLine); // On met la ligne charLine dans charMap
        monsterMap.push_back(monsterLine); // On met la ligne monsterLine dans monsterMap
    }
}

void Board::setPlayer(Oueurj &Joueur) {
    playerPos = Pos(Joueur.pos.x, Joueur.pos.y);
}

char Board::getCharAt(int &x, int &y) const { return charMap[x][y]; }

void Board::printMap() const {
    cout << playerPos.x << ", " << playerPos.y << endl;
    int x = 0; int y = 0;
    for (vector<char> line : charMap) {
        for (char c : line) {
            if (x == playerPos.x && y == playerPos.y) // Si le joueur est à la position rendue on l'affiche
                cout << 'J';
            else if (monsterMap[x][y] != ' ')
                cout << monsterMap[x][y];
            else // Sinon on affiche la map
                cout << c;
            y++;
        }
        x++;
        y = 0;
        cout << endl;
    }
}

