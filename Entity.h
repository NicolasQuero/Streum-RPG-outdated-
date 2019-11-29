#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED

#include <string>
#include <iostream>

class Entity
{

protected:

    std::string m_nom;
    int m_vie;
    int m_degat;
    bool isAlive;

public:

    Entity();
    Entity(std::string nom,int vie,int degat);
    virtual ~Entity();

    std::string getNom()const;
    int getVie()const;
    int getDegats()const;
    bool getIsAlive()const;
    void afficherEtat()const;

    void recevoirDegat(int degat);
    void virtual attaque(Entity &cible);
    void combat(Entity&b);

};




#endif // PERSONNAGE_H_INCLUDED
