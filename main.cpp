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

int deroulementJeu(Jeu *j,int k,int turn,Oueurj *O);


int main() {
    SetConsoleOutputCP( 1252 ); // Pour afficher les accents dans le terminal

    const string MAP_TEST = "maptest";

    Jeu j;
    j.afficherMiniMap();
    int k=-1;//definit s'ou on viens
    int turn=0;
    Oueurj O;
    do{
        deroulementJeu(&j,k,turn,&O);
    }while(j.getNomMap()!="fin");
    cout<<"vous avez gagner";
    return 0;
}



int deroulementJeu(Jeu *j,int k,int turn,Oueurj *O)
{
    GameMap Map(j->getNomMap());
    Map.creaPorte(j,1);
    int posXminiMap, posYminiMap;

    if(k==0){posYminiMap=Map.getHauteur()-2,posXminiMap=(Map.getLongueur())/2;} // on vient d'en haut, on cree le joueur en bas
    else if(k==1){posYminiMap=2,posXminiMap=(Map.getLongueur())/2;}//... d'en bas,... en haut
    else if(k==2){posYminiMap=(Map.getHauteur())/2,posXminiMap=(Map.getLongueur())-2;}//... de gauche,... a gauche
    else if(k==3){posYminiMap=(Map.getHauteur())/2,posXminiMap=1;}//... de droite,... a droite
    else if(k==-1){posYminiMap=(Map.getHauteur())/2,posXminiMap=(Map.getLongueur())/2;}

    O->pos=Pos(posYminiMap,posXminiMap);
    Board board = Board(Map,*O);
    board.printMap();
    cout << endl << "****************** La partie débute, nous sommes au tour " << turn << " ******************" << endl << endl;
    while (board.gameOn && board.playTurn()){
        turn ++;
        if (O->pos.y==Map.getHauteur()-2&&O->pos.x==(Map.getLongueur())/2){break;}
        else if(O->pos.y==1&&O->pos.x==(Map.getLongueur())/2){break;}
        else if (O->pos.y==1&&O->pos.x==(Map.getLongueur())/2){break;}
        else if (O->pos.y==(Map.getHauteur())/2&&O->pos.x==(Map.getLongueur())/2){break;}
        cout << endl << "****************** Le tour " << turn << " est terminé. ******************" << endl << endl;
        board.printMap();
    }
        cout<<"ca marche";
}
