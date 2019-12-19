#ifndef CARTE_H_INCLUDED
#define CARTE_H_INCLUDED

#include "Jeu.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

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

    void modifierValeurCarte(char a,int posY,int posX);
    void creaPorte(Jeu miniMap);
    void creaPorteHaut(int val);// val=0 carte non visite (porte fermée) val!=0 carte visite( porte ouverte)
    void creaPorteBas(int val);// 'X' porte fermee
    void creaPorteGauche(int val);
    void creaPorteDroite(int val);

    void afficherCarte();
};
#endif // CARTE_H_INCLUDED
