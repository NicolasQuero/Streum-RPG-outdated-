#include <iostream>
#include <vector>
#include "Streumons/Streumon.h"
#include "Oueurj.h"
#include "Pos.h"
#include "Board.h"

using namespace std;

const Pos Oueurj::DEPLACEMENTS_POS[] = {Pos(-1,-1), Pos(0,-1), Pos(1, -1), Pos(-1,0), Pos(0,0), Pos(1,0), Pos(-1, 1), Pos(0, 1), Pos(1,1)};

Oueurj::Oueurj() : pos() {

}

Oueurj::Oueurj(Pos p) : pos(p) {

}

Oueurj::Oueurj(int x, int y) : pos(x, y) {

}

void Oueurj::act(vector<vector<char>> charMap, vector<Streumon*> streumons) {
    bool tourEnded = false;
    while (!tourEnded) {
        cout << "Que désirez-vous faire ?" << endl
        << "Se déplacer : d | Lancer un sort : s | Ouvrir l'inventaire : i | Quitter : q" << endl;
        string choice;
        cin >> choice;
        tourEnded = manageChoice1(choice);
    }

}

bool Oueurj::quitGame() const {
    string confirmChoice;
    cout << "Êtes-vous sûr de vouloir quitter le jeu ? o/n" << endl;
    cin >> confirmChoice;
    while (confirmChoice[0] != 'o' && confirmChoice[0] != 'n') {
        cout << "Êtes-vous sûr de vouloir quitter le jeu ? (Oui = o, Non = n)" << endl;
        cin >> confirmChoice;
    }
    if (confirmChoice[0] == 'o') {
        Board::gameOn = false;
        return true;
    }
    else if (confirmChoice[0] == 'n')
        return false;

}

bool Oueurj::manageChoice1(string choice) {
    switch (choice[0]) {
    case 'd' : {
        cout << "Déplacement :" << endl << "Où désirez-vous aller ? (sur l'une des 8 cases autour du joueur)" << endl
        << "1 bas gauche, 2 bas, 3 bas droite, 4 gauche, 6 droite, 7 haut gauche, 8 haut, 9 haut droite (pavé numérique)" << endl;
        string choice2;
        cin >> choice2;
        int deplacement = choice2[0] - '0'; // on convertit l'entier entré sous forme de string en entier
        movePlayer(deplacement);
        return true;
    }
    case 's' : {
        cout << "Aucun sort." << endl;
        return false;
    }
    case 'i' : {
        cout << "Pas d'inventaire." << endl;
        return false;
    }
    case 'q' : {
        return quitGame();
    }
    }
}


void Oueurj::movePlayer(int deplacement) {

}

