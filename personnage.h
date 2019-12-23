#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED

#include <string>
#include <iostream>


class Personnage
{

protected:

    std::string m_nom;
    int m_vie;
    int m_degat;
    bool isAlive;

public:

    Personnage();
    Personnage(std::string nom,int vie,int degat);
    virtual ~Personnage();

    std::string getNom()const;
    int getVie()const;
    int getDegats()const;
    bool getIsAlive()const;
    void virtual afficherEtat()const;

    void recevoirDegat(int degat);
    void virtual attaque(Personnage &cible);
    void combat(Personnage *b);

};




#endif // PERSONNAGE_H_INCLUDED
