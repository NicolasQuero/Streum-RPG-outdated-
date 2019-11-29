#include "creaMap.h"

creaMap::creaMap()//cree la base de la map
{
    std::cout<< std::endl << "Bienvenue dans la creation de Map" << std::endl <<std::endl;
    std::cout << "De quelle longueur voulez vous votre Map? (Axe des X)"<< std::endl << "(valeur de 10 a 100)"<<std::endl;
    int longMap;
    longMap=demandeInt(10,100);

    std::cout << "De quelle hauteur voulez vous votre Map? (Axe des Y)" << std::endl << "(valeur de 10 a 100)"<<std::endl; // on cree les deux valeurs qui seront la taille de la map
    int hautMap;
    hautMap=demandeInt(10,100);


    m_longueur=longMap;
    m_hauteur=hautMap;

    std::string creationLigne[hautMap];
    for (int i(0);i<hautMap;i++)
    {
        for (int j(0);j<longMap;j++)
        {
            if(j==0 || i==0 || i==hautMap-1 || j==longMap-1)
            {
                creationLigne[i]+="#";
            }
            else
            {
                creationLigne[i]+=" ";
            }
        }
        mapStrings.push_back(creationLigne[i]);
    }
    afficherMap();
}

creaMap::~creaMap()
{
}

int creaMap::getLongueur()const
{
    return m_longueur;
}

int creaMap::getHauteur()const
{
    return m_hauteur;
}

std::string creaMap::getMapStrings(int i)const
{
    return mapStrings[i];
}

void creaMap::afficherMap()const
{
    std::cout<< std::endl;
    for(int j(0);j< this->getLongueur();j++)
    {
        if (j<9)
        {
            std::cout<<j+1<<"  ";
        }
        else
        {
            std::cout<<j+1<<" ";
        }
    }
    std::cout<<std::endl<<std::endl;
    for(int i(0);i< this->getHauteur();i++)
    {
        for(int j(0);j<this->getLongueur();j++)
        {
        std::cout<<this->getMapStrings(i)[j]<<"  ";
        }
      std::cout<<i+1<<std::endl;
    }
    std::cout<< std::endl;
}


void creaMap::creaMur()//on demande si le joueur veut cree des murs sur la map, puis on les construits.
{
    std::vector<std::string> copieMapStrings=mapStrings;
    std::cout << "voulez vous creer des murs supplementaires dans la salle ? (attention de ne pas vous enfermer)" << std::endl << "(oui (o) ou non (n))"<<std::endl;
    std::string oOUn;
    oOUn=demandeAouB("o","n");
    if (oOUn=="n")
    {
        std::cout << "tres bien, passons a l'etape suivante" << std::endl;
    }
    else
    {
        std::cout << "voulez vous creer des murs horizontaux ou verticaux ?" << std::endl << "(horizontaux (h) ou verticaux(v))"<<std::endl;
        std::string hOUv;
        hOUv=demandeAouB("h","v");
        std::cout << "a quelle position en X voulez vous creer le debut de votre mur ?" << std::endl <<"valeur de 2 a "<< getLongueur()-1 << std::endl;
        int valX = demandeInt(2,getLongueur()-1);
        std::cout << "a quelle position en Y voulez vous creer le debut de votre mur ?" << std::endl <<"valeur de 2 a "<< getHauteur()-1 << std::endl;
        int valY = demandeInt(2,getHauteur()-1);
        std::cout << "de quelle taille voulez vous votre mur ?" << std::endl;
        if (hOUv=="h")
        {
            std::cout <<"valeur de "<<1<<" a "<<getLongueur()-valX<< std::endl;
            int valDist = demandeInt(1,getLongueur()-valX);
            for (int i=0;i<valDist;i++)
            {
                this->modifierValeurMap('#',valX-1+i,valY-1);
            }
        }
        else
        {
            std::cout <<"valeur de "<<1<<" a "<<getHauteur()-valY<< std::endl;
            int valDist = demandeInt(1,getHauteur()-valY);
            for (int i=0;i<valDist;i++)
            {
                this->modifierValeurMap('#',valX-1,valY-1+i);
            }
        }
        this->afficherMap();
        std::cout << "ce mur vous convient-il ?" << std::endl << "(oui (o) ou non (n))"<<std::endl;
        oOUn=demandeAouB("o","n");
        if (oOUn=="n")
        {
            mapStrings=copieMapStrings;
            this->afficherMap();
        }
        this->creaMur(); // on recree d'autre mur si le joueur demande
    }
}

void creaMap::creaChoses(const std::string chose)
{
    std::vector<std::string> copieMapStrings=mapStrings;
    this->afficherMap();
    std::cout << "voulez vous ajouter des "<<chose<<" dans la salle ? (attention vous ne pouvez pas cree de "<<chose<<" sur les murs)" << std::endl << "(oui (o) ou non (n))"<<std::endl;
    std::string oOUn;
    oOUn=demandeAouB("o","n");
    if (oOUn=="n" && chose!="Chargeurs")
    {
        std::cout << "tres bien, passons a l'etape suivante" << std::endl;
    }
    else if(oOUn=="n");
    else
    {
        std::string sOUS;
        if (chose=="Streumons")
        {
            std::cout << "voulez vous creer de simple Streumons ou des Streumons plus puissant ?" << std::endl << "(Streumons (s) ou Streumons puissant(S))"<<std::endl;
            sOUS=demandeAouB("s","S");
        }
        else if (chose=="Diamants")
        {
            std::cout << "Si vous creez un Diamant sur un Streumon, le Streumon sera instantanement detruit ecrase par le Diamants" << std::endl;
            sOUS="D";
        }
        else if (chose=="Chargeurs")
        {
            std::cout << "les Chargeurs ne peuvent pas etre cree sur les Diamants ou sur les Streumons" << std::endl;
            sOUS="C";
        }
        else
        {
            std::cout << "cette chose n existe pas encore dans l univers du jeu" << std::endl;
        }
        std::cout << "a quelle position en X voulez vous creer le "<<chose<<" ?" << std::endl <<"valeur de 2 a "<< getLongueur()-1 << std::endl;
        int valX = demandeInt(2,getLongueur()-1);
        std::cout << "a quelle position en Y voulez vous creer le "<<chose<<" ?" << std::endl <<"valeur de 2 a "<< getHauteur()-1 << std::endl;
        int valY = demandeInt(2,getHauteur()-1);
        if (getMapStrings(valY-1)[valX-1]=='#')
        {
            std::cout << "ne soyez pas tetu, je vous ai dit que l'on ne pouvais pas creer de "<<chose<<" sur les murs"<< std::endl;
            this->creaChoses(chose);
        }
        else if((getMapStrings(valY-1)[valX-1]=='s'||getMapStrings(valY-1)[valX-1]=='S'||getMapStrings(valY-1)[valX-1]=='D' )&& sOUS!="D")
        {
            std::cout << "vous ne pouvez pas creer de "<<chose<<" sur les murs, sur les Streumons ou sur les Diamants"<< std::endl;
            this->creaChoses(chose);
        }
        else
        {
            this->modifierValeurMap(sOUS[0],valX-1,valY-1);
            this->afficherMap();
            std::cout << "cet emplacement pour le "<<chose<<" vous convient-il ?" << std::endl << "(oui (o) ou non (n))"<<std::endl;
            oOUn=demandeAouB("o","n");
            if (oOUn=="n")
            {
                mapStrings=copieMapStrings;
            }
            this->creaChoses(chose);
        }
    }
}

void creaMap::modifierValeurMap(char a, int posX,int posY) // modifie le charactere en X Y par 'a'
{
    this->mapStrings[posY][posX]=a;
}

void creaMap::ajouterElement()
{
    this->creaMur();
    this->creaChoses("Streumons"); //on cree les monstres
    this->creaChoses("Diamants"); //on cree les Diamants
    this->creaChoses("Chargeurs"); //on cree les Chargeurs
    bool i = false ;
    do
    {
        std::cout<<"cette map vous convient-elle ?" <<std::endl<<"il est encore temps de la modifier(ajouter des murs, des Streumons ..."<< std::endl<<"(oui (o) ou non (n))"<<std::endl;
        char oOUn=demandeAouB("o","n");
        if (oOUn=='o')
        {
            i=true;
        }
        else
        {
            std::cout << "voulez vous ajouter des murs ?(m), des Streumons ? (s), des Diamants ?(d), ou des Chargeurs ?(c)";
            char oOUn=demandeAouB("m","s","d","c");
            if(oOUn=='m')
            {
                this->creaMur(); //permet de cree les mur supplementaire de la salle
            }
            else if (oOUn=='s')
            {
                this->creaChoses("Streumons"); //on cree les monstres

            }
            else if (oOUn=='d')
            {
                this->creaChoses("Diamants"); //on cree les Diamants
            }
            else
            {
                this->creaChoses("Chargeurs"); //on cree les Chargeurs
            }
        }
    }while (i==false);
}

void creaMap::enregistrerMap() const
{
    std::cout<<"felicitation votre map est terminee"<<std::endl;
    bool i=false;
    std::string liste="ListeMap/ListeMap.txt";
    std::string MAP_PATH;
    std::ifstream fluxII(liste); //on ouvre en lecture la liste des nom de map et on regarde si se nom existe deja
    if(fluxII)
    {
        do
        {
        std::cout<<"sous quel nom voulez vous enregistrer votre map ?"<<std::endl;
        i=0;
        std::cin >> MAP_PATH;
            std::string ligne;
            while(getline(fluxII, ligne))
            {
                 if (MAP_PATH==ligne) //si le nom est deja pris, on en redemande un autre
                 {
                    std::cout<< "se nom est deja utilise, vous ne pouvez pas ecraser une map deja existante, merci de choisir un autre nom."<< std::endl;
                    i=true;
                 }
            }
        }while(i!=false);
        fluxII.close();
    }
    else{std::cout << "ERREUR: Impossible d'ouvrir en lecture le fichier de liste des nom de Map." << std::endl;}
    std::ofstream fluxIII(liste.c_str(), std::ios::app); //on ouvre le fichier en mode ecriture pour ajouter le nom de la nouvelle map a la liste de map
    if(fluxIII)
    {
        fluxIII<<std::endl<<MAP_PATH;
        fluxIII.close();
    }
    else {std::cout << "ERREUR: Impossible d'ouvrir en ecriture le fichier de liste des nom de Map." << std::endl;}

    std::ofstream flux(("Map/"+MAP_PATH+".txt").c_str()); //on cree un nouveau txt pour enregistrer la map a l'interieur
    if(flux.is_open())
    {
        for(int i(0);i< this->getHauteur();i++)
        {
            flux<<this->getMapStrings(i)<<std::endl;
        }
        flux.close();
    }
    else{std::cout<<"erreur ouverture fichier";}

    std::cout<< "la map "<<MAP_PATH<<" a bien ete cree."<<std::endl<<std::endl;
}



//#########################################
//fonction en dehors de CreaMap::

char demandeAouB(std::string a,std::string b,std::string c,std::string d) // verifie si l'utilisateur a bien choisie oui ou non
{
    std::string AouB;
    std::cin.clear();
    std::cin >> AouB;
    while(AouB!=a && AouB!=b && AouB!=c && AouB!=d)
    {
        if(d!="")
        {
            std::cout <<"la valeur est incorrect, merci de choisir  entre ("<<a<<") et ("<<b<<")"<<" et ("<<c<<") et ("<<d<<")"<< std::endl;
        }
        else if (c!="")
        {
            std::cout <<"la valeur est incorrect, merci de choisir  entre ("<<a<<") et ("<<b<<")"<< std::endl;
        }
        else
        {
            std::cout <<"la valeur est incorrect, merci de choisir  entre ("<<a<<") et ("<<b<<")"<< std::endl;
        }
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin>> AouB;
    }
    return (AouB[0])  ;
}


int demandeInt(int b, int c) //verifie la selection entre deux valeur b et c
{
    int val;
    std::cin.clear();
    std::cin >> val;
    while (val < b  || val > c || std::cin.fail() )
    {
        std::cout <<"la valeur est incorrect, merci de choisir une valeur entre" <<b<<" et "<<c<< std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin>> val;
    }
    return val;
}
