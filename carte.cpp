#include"carte.h"


Carte::Carte(std::string nomCarte)
{
    m_nomCarte=nomCarte;
    std::string MAP_PATH="Map/"+nomCarte+".txt";
    std::ifstream flux(MAP_PATH.c_str()); //on ouvre en lecture la liste des nom de map et on affiche le nom des map existante.
    if(flux)
    {
        int i=0;
        std::string Ligne;
        while(getline(flux,Ligne))// on parcours toutes les map existante mais on affiche pas les maps "interdite"
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

char Carte::getCharCarte(int Y,int X)
{
    return m_carte[Y][X];
}


void Carte::modifierValeurCarte(char a, int posY,int posX) // modifie le charactere en X Y par 'a'
{
    this->m_carte[posY][posX]=a;
}

void Carte::creaPorte(Jeu *miniMap,bool cle)
{
    if(miniMap->getValeurMiniMap(miniMap->getPosYJoueur()-1,miniMap->getPosXJoueur())!=-1)
    {
        creaPorteHaut(miniMap->getValeurMiniMap(miniMap->getPosYJoueur()-1,miniMap->getPosXJoueur()),cle);
    }
    if(miniMap->getValeurMiniMap(miniMap->getPosYJoueur()+1,miniMap->getPosXJoueur())!=-1)
    {
        creaPorteBas(miniMap->getValeurMiniMap(miniMap->getPosYJoueur()+1,miniMap->getPosXJoueur()),cle);
    }
    if(miniMap->getValeurMiniMap(miniMap->getPosYJoueur(),miniMap->getPosXJoueur()-1)!=-1)
    {
        creaPorteGauche(miniMap->getValeurMiniMap(miniMap->getPosYJoueur(),miniMap->getPosXJoueur()-1),cle);
    }
    if(miniMap->getValeurMiniMap(miniMap->getPosYJoueur(),miniMap->getPosXJoueur()+1)!=-1)
    {
        creaPorteDroite(miniMap->getValeurMiniMap(miniMap->getPosYJoueur(),miniMap->getPosXJoueur()+1),cle);
    }
}

void Carte::creaPorteHaut(int val,bool cle)
{
    char porte;
    if (val==0 && cle==false){porte='X';}
    else{porte=' ';}
    this->modifierValeurCarte(porte,0,(this->getLongueur())/2);
    bool j=false;
    int i=1;
    while(j!=true)
    {
        if(m_carte[i][((getLongueur())/2)-1]!=' '||m_carte[i][(getLongueur())/2]!=' '||m_carte[i][((getLongueur())/2)+1]!=' ')
        {
            this->modifierValeurCarte(' ',i,(this->getLongueur())/2);
            i++;
        }
        else(j=true);
    }
}

void Carte::creaPorteBas(int val,bool cle)
{
    char porte;
    if (val==0 && cle==false){porte='X';}
    else{porte=' ';}
    this->modifierValeurCarte(porte,this->getHauteur()-1,(this->getLongueur())/2);
    bool j=false;
    int i=1;
    while(j!=true)
    {
        if(m_carte[this->getHauteur()-1-i][((getLongueur())/2)-1]!=' '||m_carte[this->getHauteur()-1-i][(getLongueur())/2]!=' '||m_carte[this->getHauteur()-1-i][((getLongueur())/2)+1]!=' ')
        {
            this->modifierValeurCarte(' ',this->getHauteur()-1-i,(this->getLongueur())/2);
            i++;
        }
        else(j=true);
    }
}

void Carte::creaPorteGauche(int val,bool cle)
{
    char porte;
    if (val==0 && cle==false ){porte='X';}
    else{porte=' ';}
    this->modifierValeurCarte(porte,(this->getHauteur())/2,0);
    bool j=false;
    int i=1;
    while(j!=true)
    {
        if(m_carte[(getHauteur()/2)-1][i]!=' '||m_carte[getHauteur()/2][i]!=' '||m_carte[(getHauteur()/2)+1][i]!=' ')
        {
            this->modifierValeurCarte(' ',(this->getHauteur())/2,i);
            i++;
        }
        else(j=true);
    }
}

void Carte::creaPorteDroite(int val,bool cle)
{
    bool j=false;
    char porte;
    if (val==0 && cle==false){porte='X';}
    else{porte=' ';}
    this->modifierValeurCarte(porte,(this->getHauteur())/2,this->getLongueur()-1);
    int i=1;
    while(j!=true)
    {
        if(m_carte[(getHauteur()/2)-1][getLongueur()-1-i]!=' '||m_carte[getHauteur()/2][getLongueur()-1-i]!=' '||m_carte[(getHauteur()/2)+1][getLongueur()-1-i]!=' ')
        {
            this->modifierValeurCarte(' ',(this->getHauteur())/2,this->getLongueur()-1-i);
            i++;
        }
        else(j=true);
    }
}

void Carte::afficherCarte()
{
    std::cout<<std::endl;
    for(int i=0; i<this->getHauteur(); i++)
    {
        std::cout<<m_carte[i]<<std::endl;
    }
}
