#include"sMonstre.h"


sMonstre::sMonstre(std::string nom,int niveau) : Personnage(nom,niveau*30,niveau*3)  //la force du monstre et sa vie depend de son niveau
{
    m_niveau=niveau;
}

sMonstre::~sMonstre()
{
}

int sMonstre::getNiveau()
{
    return m_niveau;
}

int sMonstre::IARandom(std::vector<int> PlacesLibres)
{
    int taillePL=PlacesLibres.size();
    srand(time(NULL));
    int alea = rand()%taillePL;
    return(PlacesLibres[alea]);
}
