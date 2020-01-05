#ifndef GAMEMAP_H_INCLUDED
#define GAMEMAP_H_INCLUDED

#include "Jeu.h"
#include "Entities/Pos.h"
#include <vector>


using namespace std;

class GameMap {
protected:
    vector<string> mapStrings;
    int m_hauteur;
    int m_longueur;
    bool cle_obtenue;
public:

    GameMap(const string nomMap);
    //GameMap(const GameMap& gamemap);
    vector<string> getMapStrings() const;

    int getLongueur();
    int getHauteur();
    void afficherGameMap();
    char getCharGameMap(int Y,int X);
    void modifierValeurGameMap(char a,int posY,int posX);
    void prendreCle() { cle_obtenue = true; }
    bool CleObtenu();
    Pos getPortesPos(char c);
    void creaPorte(Jeu *miniMap,bool cle=false);
    void creaPorteHaut(int val,bool cle);// val=0 carte non visite (porte fermée) val!=0 carte visite( porte ouverte)
    void creaPorteBas(int val,bool cle);// 'X' porte fermee
    void creaPorteGauche(int val,bool cle);
    void creaPorteDroite(int val,bool cle);
};



#endif // GAMEMAP_H_INCLUDED
