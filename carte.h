#ifndef CARTE_H_INCLUDED
#define CARTE_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Jeu.h"

class Carte
{
private:
    std::vector<std::string> m_carte;
    int m_hauteur;
    int m_longueur;
    std::string m_nomCarte;

public:
    Carte(std::string nomCarte);
    ~Carte();

    int getLongueur();
    int getHauteur();
    void afficherCarte();
    char getCharCarte(int Y,int X);
    void modifierValeurCarte(char a,int posY,int posX);
    void creaPorte(Jeu *miniMap,bool cle=false);
    void creaPorteHaut(int val,bool cle);// val=0 carte non visite (porte fermée) val!=0 carte visite( porte ouverte)
    void creaPorteBas(int val,bool cle);// 'X' porte fermee
    void creaPorteGauche(int val,bool cle);
    void creaPorteDroite(int val,bool cle);

};
#endif // CARTE_H_INCLUDED
