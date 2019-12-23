#include "Jeu.h"
#include"FonctionUtile.h"

Jeu::Jeu()
{
    std::string MAP_PATH="JeuCree/Jeu.txt";
    std::ifstream flux(MAP_PATH.c_str()); //on ouvre en lecture la liste des nom de map et on affiche le nom des map existante.
    if(flux)
    {
        std::string Map;
        std::vector<std::string> vectString;
        while(getline(flux,Map))// on parcours toutes les map existante mais on affiche pas les maps "interdite"
        {
            if(Map=="---------------")
            {
                m_emplacementMap.push_back(vectString);
                vectString.clear();
            }
            else
            {
                vectString.push_back(Map);
            }
        }
        flux.close();
    }
    else{std::cout << "ERREUR: Impossible d'ouvrir en lecture le fichier de jeu cree." << std::endl;}
    this->miniMap();
}

void Jeu::miniMap() // cree un tableau identique que m_emplacementMap avec valeur -1 si il y a rien,0 si il y a une map
//1 si elle a ete deja visite,2 si le joueur est dessus
{
    std::vector<int> vectInt;
    for(int y=0; y<getTailleX()+2;y++){vectInt.push_back(-1);}
    m_miniMap.push_back(vectInt);
    for(int y=0; y<getTailleY();y++)
    {
        std::vector<int> vectInt;
        vectInt.push_back(-1);
        for(int x=0;x<getTailleX();x++)
        {
            if(m_emplacementMap[y][x].substr(0,6)=="Depart")
            {
                vectInt.push_back(2);
                m_posXj=x+1;
                m_posYj=y+1;
            }
            else if(m_emplacementMap[y][x].substr(0,7)!="       "){vectInt.push_back(0);}
            else (vectInt.push_back(-1));
        }
        vectInt.push_back(-1);
        m_miniMap.push_back(vectInt);
    }
    m_miniMap.push_back(vectInt);
}

int Jeu::getTailleX()
{
   return m_emplacementMap[0].size();
}

int Jeu::getTailleY()
{
    return m_emplacementMap.size();
}

int Jeu::getPosXJoueur()
{
    return m_posXj;
}

int Jeu::getPosYJoueur()
{
    return m_posYj;
}

std::string Jeu::getNomMap() //permet de savoir sur quelle map est le joueur
{
    return m_emplacementMap[m_posYj-1][m_posXj-1];
}

int Jeu::getValeurMiniMap(int posY,int posX) //permet de connaitre ou est le joueur sur la minimap
{
    return m_miniMap[posY][posX];
}


void Jeu::deplacementMiniMapGauche()
{
    m_miniMap[m_posYj][m_posXj]=1; // le joueur n'est plus sur la map,mais elle a ete visite
    m_miniMap[m_posYj][m_posXj-1]=2; //nouvelle map ou est le joueur
    m_posXj=m_posXj-1; //changement des coordonnees du joueur
}

void Jeu::deplacementMiniMapDroite()
{
    m_miniMap[m_posYj][m_posXj]=1;
    m_miniMap[m_posYj][m_posXj+1]=2;
    m_posXj=m_posXj+1;
}

void Jeu::deplacementMiniMapHaut()
{
    m_miniMap[m_posYj][m_posXj]=1;
    m_miniMap[m_posYj-1][m_posXj]=2;
    m_posYj=m_posYj-1;
}

void Jeu::deplacementMiniMapBas()
{
    m_miniMap[m_posYj][m_posXj]=1;
    m_miniMap[m_posYj+1][m_posXj]=2;
    m_posYj=m_posYj+1;
}

void Jeu::afficherMiniMap()
{
    std::cout<<std::endl<<"***Mini Map***"<<std::endl<<std::endl;
    for(int x=0; x<getTailleX();x++){std::cout<<"    "<<x+1<<"    ";}
    std::cout<<std::endl<<std::endl;
    for(int y=1; y<getTailleY()+1;y++)
    {
        for(int x=1;x<getTailleX()+1;x++)
        {
            if (m_miniMap[y][x]==2){std::cout<<".***J***.";}//presence du joueur
            else if((m_miniMap[y-1][x]>0||m_miniMap[y][x-1]>0||m_miniMap[y+1][x]>0||m_miniMap[y][x+1]>0||m_miniMap[y][x]>0) && m_miniMap[y][x]!=-1)
            {
                std::cout<<".*******.";
            }
            else(std::cout<<".       .");
        }
        std::cout<<"   "<<y<<std::endl;
    }
}

void Jeu::afficherMiniMap2()
{
    for(int y=0; y<getTailleY()+2;y++)
    {
        for(int x=0;x<getTailleX()+2;x++)
        {
            std::cout<<m_miniMap[y][x];
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl<<std::endl;
}


void Jeu::afficherSchemaJeu()
{
    for(int x=0; x<getTailleX();x++)
    {
        std::cout<<"    "<<x<<"    ";
    }
    std::cout<<std::endl<<std::endl;
    for(int y=0; y<getTailleY();y++)
    {
        for(int x=0;x<getTailleX();x++)
        {
            std::cout<<"."<<(m_emplacementMap[y][x]+"       ").substr(0,7)<<".";
        }
        std::cout<<"   "<<y<<std::endl;
    }
    std::cout<<std::endl<<std::endl;
}
