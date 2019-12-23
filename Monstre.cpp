#include"Monstre.h"


Monstre::Monstre(std::string nom,int niveau) : Personnage(nom,niveau*30,niveau*3)  //la force du monstre et sa vie depend de son niveau
{
}

Monstre::~Monstre()
{
}
