#include"carte.h"

Carte::Carte(std::string nomCarte)
{
    m_nomCarte=nomCarte;
    std::string MAP_PATH="Map/"+nomCarte+".txt";
    std::ifstream flux(MAP_PATH.c_str()); //on ouvre en lecture la carte ou est le joueur.
    if(flux)
    {
        int i=0;
        std::string Ligne;
        while(getline(flux,Ligne))
        {
            m_carte.push_back(Ligne);
            i++;
        }
        m_hauteur=i;
        flux.close();
    }
    else{std::cout << "ERREUR: Impossible d'ouvrir en lecture le fichier de Map cree." << std::endl;}
}

Carte::~Carte()
{

}

int Carte::getLongueur()
{
    m_longueur=m_carte[0].size();
   return m_longueur;
}

int Carte::getHauteur()
{
    return m_hauteur;
}

void Carte::modifierValeurCarte(char a, int posY,int posX) // modifie le charactere en X Y par 'a'
{
    this->m_carte[posY][posX]=a;
}

void Carte::creaPorte(Jeu miniMap)
{
    if(miniMap.getValeurMiniMap(miniMap.getPosYJoueur()-1,miniMap.getPosXJoueur())!=-1)// on regarde si il y a une map au dessus d'ou est le joueur
    {
        creaPorteHaut(miniMap.getValeurMiniMap(miniMap.getPosYJoueur()-1,miniMap.getPosXJoueur()));
    }
    if(miniMap.getValeurMiniMap(miniMap.getPosYJoueur()+1,miniMap.getPosXJoueur())!=-1)//...au dessous
    {
        creaPorteBas(miniMap.getValeurMiniMap(miniMap.getPosYJoueur()+1,miniMap.getPosXJoueur()));
    }
    if(miniMap.getValeurMiniMap(miniMap.getPosYJoueur(),miniMap.getPosXJoueur()-1)!=-1)//...a gauche
    {
        creaPorteGauche(miniMap.getValeurMiniMap(miniMap.getPosYJoueur(),miniMap.getPosXJoueur()-1));
    }
    if(miniMap.getValeurMiniMap(miniMap.getPosYJoueur(),miniMap.getPosXJoueur()+1)!=-1)//...a droite
    {
        creaPorteDroite(miniMap.getValeurMiniMap(miniMap.getPosYJoueur(),miniMap.getPosXJoueur()+1));
    }
}

void Carte::creaPorteHaut(int val)
{
    char porte;
    if (val==0){porte='X';}// si la map a jamais ete visite la porte est fermee
    else{porte=' ';}//sinon ouverte
    this->modifierValeurCarte(porte,0,(this->getLongueur())/2);
}

void Carte::creaPorteBas(int val)
{
    char porte;
    if (val==0){porte='X';}
    else{porte=' ';}
    this->modifierValeurCarte(porte,this->getHauteur()-1,(this->getLongueur())/2);
}

void Carte::creaPorteGauche(int val)
{
    char porte;
    if (val==0){porte='X';}
    else{porte=' ';}
    this->modifierValeurCarte(porte,(this->getHauteur())/2,0);
}

void Carte::creaPorteDroite(int val)
{
    char porte;
    if (val==0){porte='X';}
    else{porte=' ';}
    this->modifierValeurCarte(porte,(this->getHauteur())/2,this->getLongueur()-1);
}

void Carte::afficherCarte()
{
    std::cout<<std::endl;
    for(int i=0; i<this->getHauteur(); i++)
    {
        std::cout<<m_carte[i]<<std::endl;
    }
}
