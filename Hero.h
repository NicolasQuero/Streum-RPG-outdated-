#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED

#include"FonctionUtile.h"
#include"personnage.h"


class Hero : public Personnage
{

private:

    int m_argent;
    int m_potion;
    int m_mana;

public:

    Hero(std::string nom);
    virtual ~Hero();

    int getArgent() const;
    int getPotion() const;
    int getMana() const;

    void transactionArgent(int argent);
    void regagnerVie(int vie);
    void utiliserMana(int mana);
    void utiliserPotion();
    void executionAttaque(Personnage &cible,char choix);
    void virtual attaque(Personnage &cible);
    void virtual afficherEtat()const;
    void sePresenter()const;

};

#endif // HERO_H_INCLUDED
