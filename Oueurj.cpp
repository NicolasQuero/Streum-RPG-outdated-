#include <iostream>
#include <vector>
#include "Streumons/Streumon.h"
#include "Oueurj.h"
#include "Pos.h"
#include "Board.h"

using namespace std;

const int Oueurj::HP_MAX = 5;
const Pos Oueurj::DEPLACEMENTS_POS[] = {Pos(1, -1), Pos(1, 0), Pos(1, 1), Pos(0, -1), Pos(0,0), Pos(0,1), Pos(-1, -1), Pos(-1, 0), Pos(-1, 1)};

Oueurj::Oueurj() : pos(), hp(HP_MAX), teleportsLeft(0), is_alive(true) {

}

Oueurj::Oueurj(Pos p) : pos(p), hp(HP_MAX), teleportsLeft(0), is_alive(true) {

}

Oueurj::Oueurj(int x, int y) : pos(x, y), hp(HP_MAX), teleportsLeft(0), is_alive(true) {

}

void Oueurj::act(vector<vector<char>> &charMap, vector<Streumon*> &streumons) {
    bool tourEnded = false;
    while (!tourEnded) { // Tant que le tour n'est pas valide on demande au joueur ce qu'il veut faire
        cout << "Que désirez-vous faire ?" << endl
        << "Se déplacer : d | Lancer un sort : s | Ouvrir l'inventaire : i | Quitter : q" << endl;
        string choice;
        cin >> choice;
        tourEnded = manageChoice(choice, charMap, streumons);
    }

}

bool Oueurj::quitGame() const {
    string confirmChoice;
    cout << "Êtes-vous sûr de vouloir quitter le jeu ? o/n" << endl;
    cin >> confirmChoice; // Demande de confirmation
    while (confirmChoice[0] != 'o' && confirmChoice[0] != 'n') {
        cout << "Êtes-vous sûr de vouloir quitter le jeu ? (Oui = o, Non = n)" << endl;
        cin >> confirmChoice; // Si le joueur n'a entré ni 'o' ni 'n' en premier caractère
    }
    if (confirmChoice[0] == 'o') { // Le joueur veut quitter
        Board::gameOn = false;
        return true;
    }
    else if (confirmChoice[0] == 'n') // Le joueur ne veut pas quitter
        return false;

}

bool Oueurj::manageChoice(string choice, vector<vector<char>> &charMap, vector<Streumon*> &streumons) {
    switch (choice[0]) {
    case 'd' : { // Le joueur veut se déplacer
        cout << "Déplacement :" << endl << "Où désirez-vous aller ? (sur l'une des 8 cases autour du joueur)" << endl
        << "1 bas gauche, 2 bas, 3 bas droite, 4 gauche, 5 sur place, 6 droite, 7 haut gauche, 8 haut, 9 haut droite (pavé numérique)" << endl;
        string choice2;
        cin >> choice2;
        int deplacement = choice2[0] - '0'; // on convertit l'entier entré sous forme de string en entier
        movePlayer(deplacement, charMap, streumons);
        return true;
    }
    case 's' : { // Sorts choisis
        cout << "Aucun sort." << endl;
        return false;
    }
    case 'i' : { // Inventaire choisi
        cout << "Pas d'inventaire." << endl;
        return false;
    }
    case 'q' : { // Quitter le jeu choisi
        return quitGame();
    }
    }
}


void Oueurj::movePlayer(int deplacement, vector<vector<char>> &charMap, vector<Streumon*> &streumons) {
    if (0 < deplacement && deplacement < 10) {
        Pos targetPos = pos + DEPLACEMENTS_POS[deplacement-1]; // Target position is the position of the player plus the vector associated to the movement
        cout << pos << " | " << targetPos << " | " << deplacement << endl;

        if (charMap[targetPos.x][targetPos.y] != '#' && charMap[targetPos.x][targetPos.y] != 'X') { // If it's not a wall
            char monsterType = whichMonsterAt(targetPos, streumons); // We check the monster type at the target position (if there is one)
            if ( monsterType == ' ' ) // Si il n'y a pas de monstre on se déplace
                pos = targetPos;
            else { // Sinon on se bat comme un vrai Oueurj ou on ajoute le mob au Streumédex
                cout << "Monstre " << monsterType << " rencontré !" << endl;
                inflictDamage(1); // Il nous inflige 1 point de dégâts
            }
        }

        else
            cout << "COULDN'T MOVE" << endl;

    }
}

char Oueurj::whichMonsterAt(Pos target, vector<Streumon*> &streumons) {
    for (Streumon* monster : streumons) {
        if (monster->pos == target)
            return monster->getType(); // monster found, return its type
    }
    return ' '; // no monster found, return empty char
}
