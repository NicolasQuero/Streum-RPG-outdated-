#include <iostream>
#include <fstream>
#include <vector>
#include "Entities/Oueurj.h"
#include "Board.h"
#include "GameMap.h"
#include "Jeu.h"
#include <windows.h>
#pragma execution_character_set( "utf-8" )

using namespace std;



int main() {
    SetConsoleOutputCP( 1252 ); // Pour afficher les accents dans le terminal

    const string MAP_TEST = "maptest";

    Jeu j;
    j.afficherMiniMap();
    int k=-1;//definit s'ou on viens
    do{

        GameMap Map(j.getNomMap());
        Map.creaPorte(&j,1);

        int posX, posY;

        if(k==0){posY=Map.getHauteur()-2,posX=(Map.getLongueur())/2;} // on vient d'en haut, on cree le joueur en bas
        else if(k==1){posY=1,posX=(Map.getLongueur())/2;}//... d'en bas,... en haut
        else if(k==2){posY=(Map.getHauteur())/2,posX=(Map.getLongueur())-2;}//... de gauche,... a gauche
        else if(k==3){posY=(Map.getHauteur())/2,posX=1;}//... de droite,... a droite
        else if(k==-1){posY=(Map.getHauteur())/2,posX=(Map.getLongueur())/2;}
        Oueurj O(posY,posX);
        Board board = Board(Map,O);

        board.printMap();
        int turn = 0;
        cout << endl << "****************** La partie débute, nous sommes au tour " << turn << " ******************" << endl << endl;
        while (board.gameOn && board.playTurn()) {
            turn ++;
            cout << endl << "****************** Le tour " << turn << " est terminé. ******************" << endl << endl;
            board.printMap();
        }
    }while(j.getNomMap()!="fin");
    cout<<"vous avez gagner";
    return 0;
}

