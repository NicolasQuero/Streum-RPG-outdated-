#include <iostream>
#include "Pos.h"


Pos::Pos(Carte *Carte)
{
    m_carte = Carte;
    for(int i=0;i<Carte->getHauteur();i++)
    {
        for(int j=0;j<Carte->getLongueur();j++)
        {
            if(Carte->getCharCarte(i,j)=='S'||Carte->getCharCarte(i,j)=='s'||Carte->getCharCarte(i,j)=='J'||Carte->getCharCarte(i,j)=='D')
            {
                m_pos.push_back(i);
                m_pos.push_back(j);
                m_nom.push_back(Carte->getCharCarte(i,j));
            }
        }
    }
}

int Pos::getTaille()
{
    return m_nom.size();
}

int Pos::getPosJ()
{
    int i=0;
    while(m_nom[i]!='J')
    {
        i++;
    }
    return i;
}

bool Pos::getCle()
{
    bool cle=true;
    for(int i=0;i<getTaille();i++)
    {
        if(m_nom[i]=='D'){cle=false;}
    }
    return cle;
}

int Pos::getPositionY(int posChar)
{
    return m_pos[2*posChar];
}


int Pos::getPositionX(int posChar)
{
    return m_pos[2*posChar+1];
}

char Pos::getNom(int posPerso)
{
    return m_nom[posPerso];
}

std::vector<int> Pos::deplacementPossible(int posChar)
{
    std::vector<int> PlacesLibres;
    int cas=1;
    for(int y=1;y>-2;y--)
    {
        for(int x=-1;x<2;x++)
        {
            if(m_pos[(2*posChar)]+y<0||m_pos[(2*posChar)]+y>m_carte->getHauteur()){}
            else if (m_pos[2*posChar+1]+x<0||m_pos[2*posChar+1]+x>m_carte->getLongueur()){}
            else if(m_carte->getCharCarte(m_pos[(2*posChar)]+y,m_pos[2*posChar+1]+x)!='#'
                                &&m_carte->getCharCarte(m_pos[(2*posChar)]+y,m_pos[2*posChar+1]+x)!='X')
            {
                PlacesLibres.push_back(cas);
            }
            cas++;
        }
    }
    return PlacesLibres;
}

void Pos::ChoixDeplacement(std::vector<int> PlacesLibres,int posChar,Jeu *j,Personnage *p)
{
    bool b=false;
    std::cout<<std::endl<<"vous pouvez aller:"<<std::endl;
    int a=PlacesLibres.size(), choix;
    for(int i=0;i<a;i++)
    {
        if(PlacesLibres[i]==1){std::cout<<"en diagonale bas gauche (1)"<<std::endl;}
        else if(PlacesLibres[i]==2){std::cout<<"en bas (2)"<<std::endl;}
        else if(PlacesLibres[i]==3){std::cout<<"en diagonale bas droite (3)"<<std::endl;}
        else if(PlacesLibres[i]==4){std::cout<<"a gauche (4)"<<std::endl;}
        else if(PlacesLibres[i]==5){std::cout<<"ne pas bouger (5)"<<std::endl;}
        else if(PlacesLibres[i]==6){std::cout<<"a droite (6)"<<std::endl;}
        else if(PlacesLibres[i]==7){std::cout<<"en diagonale haut gauche (7)"<<std::endl;}
        else if(PlacesLibres[i]==8){std::cout<<"en haut (8)"<<std::endl;}
        else if(PlacesLibres[i]==9){std::cout<<"en diagonale haut droite (9)"<<std::endl;}
    }
    std::cout<<std::endl<<"vous pouvez acceder aux informations avec (0)"<<std::endl<<"cela vous coute un tour"<<std::endl<<std::endl;
    std::cout<<"que voulez vous faire ?"<<std::endl;
    do
    {
        choix=demandeInt(0,9);
        for(int i=0;i<a;i++)
        {
            if(choix==PlacesLibres[i]){b=true;}
            else if(choix==0)
            {
                information(j,p);
                choix=5;
                b=true;
            }
        }
        if(b==false){(std::cout<<"valeur incorrect, merci de choisir une des valeur proposee si dessus"<<std::endl);}
    }while(b!=true);
    deplacement(choix,posChar);
}

void Pos::deplacement(int choix,int posChar)
{
    if(choix==1){deplacementDiagBG(posChar);}
    else if(choix==2){deplacementBas(posChar);}
    else if(choix==3){deplacementDiagBD(posChar);}
    else if(choix==4){deplacementGauche(posChar);}
    else if(choix==6){deplacementDroite(posChar);}
    else if(choix==7){deplacementDiagHG(posChar);}
    else if(choix==8){deplacementHaut(posChar);}
    else if(choix==9){deplacementDiagHD(posChar);}
}

void Pos::deplacementHaut(int posChar)
{
    m_carte->modifierValeurCarte(' ',m_pos[2*posChar],m_pos[2*posChar+1]);
    m_pos[2*posChar]=m_pos[2*posChar]-1;
    m_carte->modifierValeurCarte(m_nom[posChar],m_pos[2*posChar],m_pos[2*posChar+1]);
}

void Pos::deplacementBas(int posChar)
{
    m_carte->modifierValeurCarte(' ',m_pos[2*posChar],m_pos[2*posChar+1]);
    m_pos[2*posChar]=m_pos[2*posChar]+1;
    m_carte->modifierValeurCarte(m_nom[posChar],m_pos[2*posChar],m_pos[2*posChar+1]);
}
void Pos::deplacementGauche(int posChar)
{
    m_carte->modifierValeurCarte(' ',m_pos[2*posChar],m_pos[2*posChar+1]);
    m_pos[2*posChar+1]=m_pos[2*posChar+1]-1;
    m_carte->modifierValeurCarte(m_nom[posChar],m_pos[2*posChar],m_pos[2*posChar+1]);
}
void Pos::deplacementDroite(int posChar)
{
    m_carte->modifierValeurCarte(' ',m_pos[2*posChar],m_pos[2*posChar+1]);
    m_pos[2*posChar+1]=m_pos[2*posChar+1]+1;
    m_carte->modifierValeurCarte(m_nom[posChar],m_pos[2*posChar],m_pos[2*posChar+1]);
}

void Pos::deplacementDiagHG(int posChar)
{
    this->deplacementHaut(posChar);
    this->deplacementGauche(posChar);
}
void Pos::deplacementDiagHD(int posChar)
{
    this->deplacementHaut(posChar);
    this->deplacementDroite(posChar);
}
void Pos::deplacementDiagBG(int posChar)
{
    this->deplacementBas(posChar);
    this->deplacementGauche(posChar);
}
void Pos::deplacementDiagBD(int posChar)
{
    this->deplacementBas(posChar);
    this->deplacementDroite(posChar);
}

std::vector<int> Pos::detectionMob(int posChar)
{
    std::vector<int> PlacesMob;;
    for(int y=1;y>-2;y--)
    {
        for(int x=-1;x<2;x++)
        {
            if(m_pos[(2*posChar)]+y<0||m_pos[(2*posChar)]+y>m_carte->getHauteur()-1){}
            else if (m_pos[2*posChar+1]+x<0||m_pos[2*posChar+1]+x>m_carte->getLongueur()-1){}
            else if(m_carte->getCharCarte(m_pos[(2*posChar)]+y,m_pos[2*posChar+1]+x)=='s'
                                ||m_carte->getCharCarte(m_pos[(2*posChar)]+y,m_pos[2*posChar+1]+x)=='S')
            {
                for (int i=0;i<getTaille();i++)
                {
                    if (m_pos[2*i]==m_pos[(2*posChar)]+y && m_pos[(2*i)+1]==m_pos[(2*posChar)+1]+x){PlacesMob.push_back(i);}
                }
            }
        }
    }
    return PlacesMob;
}

void Pos::information(Jeu *j,Personnage *p)
{
    std::cout<<"que voulez vous faire ?"<<std::endl;
    std::cout<<"information joueur (i)"<<std::endl;
    std::cout<<"afficher la Minimap (m)"<<std::endl;
    char choix=demandeAouB("i","m");
    if(choix=='m'){j->afficherMiniMap();}
    else if(choix=='i'){p->afficherEtat();}
}

void Pos::afficherContenu()
{
    for(int i=0;i<getTaille();i++)
    {
        std::cout<<"Y: "<<m_pos[2*i]<<" X: "<<m_pos[2*i+1]<<std::endl;
        std::cout<<"Nom: "<< m_nom[i] <<std::endl;
    }
}
