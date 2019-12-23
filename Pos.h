#ifndef POSITION_H_INCLUDED
#define POSITION_H_INCLUDED
#include <iostream>
#include <string>

#include"FonctionUtile.h"
#include "carte.h"
#include "personnage.h"
#include "Jeu.h"

using namespace std;

class Pos
{
private:

    std::vector<int> m_pos;
    std::vector<char> m_nom;
    Carte *m_carte;


public:
    Pos(Carte *Carte);

    int getTaille();

    int getPosJ();
    int getPositionX(int posChar);
    int getPositionY(int posChar);
    char getNom(int posPerso);
    bool getCle();


    std::vector<int> deplacementPossible(int posChar);
    void ChoixDeplacement(std::vector<int> PlacesLibres,int posChar,Jeu *j,Personnage *p);
    //2*posChar=y,2*posChar+1=x
    void deplacement(int choix,int posChar);
    void deplacementHaut(int posChar);
    void deplacementBas(int posChar);
    void deplacementGauche(int posChar);
    void deplacementDroite(int posChar);
    void deplacementDiagHG(int posChar); //HG= haut gauche
    void deplacementDiagHD(int posChar);// HD= haut droite
    void deplacementDiagBG(int posChar);// BG=bas Gauche
    void deplacementDiagBD(int posChar);//BD= bas droite

    std::vector<int> detectionMob(int posChar);
    void information(Jeu *j,Personnage *p);

    void afficherContenu();
};




#endif // POSITION_H_INCLUDED
