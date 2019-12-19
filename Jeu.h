#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <string>


class Jeu
{
private:
    std::vector<std::vector<std::string> > m_emplacementMap;
    std::vector<std::vector<int> > m_miniMap;
    int m_posXj;  //position du joueur en X sur la miniMap
    int m_posYj;  //position du joueur en Y sur la miniMap

public:
    Jeu();
    ~Jeu();
    void miniMap();

    int getTailleY();
    int getTailleX();
    std::string getNomMap();
    int getValeurMiniMap(int posY,int posX);
    int getPosXJoueur();
    int getPosYJoueur();

    void deplacementMiniMapGauche();
    void deplacementMiniMapDroite();
    void deplacementMiniMapHaut();
    void deplacementMiniMapBas();

    void afficherMiniMap();
    void afficherSchemaJeu();
};

#endif // JEU_H_INCLUDED
