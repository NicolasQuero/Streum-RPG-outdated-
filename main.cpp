#include <iostream>
#include "Jeu.h"
#include"carte.h"


using namespace std;

int main()
{

    Jeu j;
    j.afficherSchemaJeu();
    j.afficherMiniMap();

    j.deplacementMiniMapGauche();
    j.afficherMiniMap();
    Carte c(j.getNomMap());
    c.creaPorte(j);
    c.afficherCarte();

    j.deplacementMiniMapDroite();
    j.afficherMiniMap();
    Carte c1(j.getNomMap());
    c1.creaPorte(j);
    c1.afficherCarte();

    j.deplacementMiniMapHaut();
    j.afficherMiniMap();
    Carte c2(j.getNomMap());
    c2.creaPorte(j);
    c2.afficherCarte();

    return 0;
}
