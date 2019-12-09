#ifndef CREAMAP_H_INCLUDED
#define CREAMAP_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class creaMap {

private:

    std::vector<std::string> mapStrings;
    int m_hauteur;
    int m_longueur;

public:

    creaMap();
    creaMap(std::string nomMap);
    ~creaMap();

    int getLongueur()const;
    int getHauteur()const;
    std::string getMapStrings(int i)const;

    void afficherMap()const;
    void creaMur(); //creation de mur
    void creaChoses(const std::string chose);//creation de chose peut prendre les valeurs :" Diamants, Streumons, Chargeurs" et cree les objets
    void modifierValeurMap(char a, int posX,int posY); //modifie un caractere en X,Y
    void ajouterElement();

    void enregistrerMap()const;

};



int demandeInt(int b , int c);
char demandeAouB(std::string a,std::string b,std::string c="",std::string d="");


#endif // CREAMAP_H_INCLUDED
