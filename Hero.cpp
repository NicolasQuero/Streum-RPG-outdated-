#include"Hero.h"

Hero::Hero(std::string nom) : Personnage(nom,100,10), m_argent(0) ,m_potion(5), m_mana(100)
{

}

Hero::~Hero()
{
}


int Hero::getArgent() const
{
    return m_argent;
}


void Hero::transactionArgent(int argent)
{
    m_argent+=argent;
}

int Hero::getPotion() const
{
    return m_potion;
}

int Hero::getMana() const
{
    return m_mana;
}

void Hero::utiliserMana(int mana)
{
    m_mana-=mana;
    if (m_mana<0)
    {
        m_mana=0;
    }
    else if (m_mana>101)
    {
        m_mana=100;
    }
}

void Hero::utiliserPotion()
{
    m_potion-=1;
    if (m_potion<0)
    {
        m_potion=0;
    }
}

void Hero::regagnerVie(int vie)
{
    m_vie+=vie;
    if (m_vie>100)
    {
        m_vie=100;
    }
}

void Hero::attaque(Personnage &cible)
{
    std::cout<<"c'est a votre tour de jouer !"<< std::endl;
    char choix;
    do
    {
        std::cout<<"que voulez vous faire?"<<std::endl<<"Attaquer au corps a corps:  a"<<std::endl;
        std::cout<<"prendre une Potion(-1potion)(il vous reste "<<this->getPotion()<<" potion(s)) :  p"<<std::endl;
        std::cout<<"lancer un Sort(-20 mana)(il vous reste "<< this->getMana()<<" de mana) :  s"<<std::endl;
        choix=demandeAouB("s","p","a");
        if (choix=='s')// regarder si il reste du mana
        {
            if(m_mana < 20)
            {
                std::cout<< "vous n'avez pas assez de mana, vous ne pouvez pas lancer de sort"<<std::endl;
                choix=' ';
            }
        }
        else if (choix =='p')//regarder si il reste des potion
        {
            if(m_potion < 1)
            {
                std::cout<< "vous n'avez pas assez de potion"<<std::endl;
                choix=' ';
            }
        }
    }while(choix!='a' && choix!='p' && choix!='s');
    this->executionAttaque(cible,choix);
}

void Hero::executionAttaque(Personnage &cible,char choix)
{
    if(choix=='a')
    {
        std::cout<< this->getNom()<<" attaque "<<cible.getNom()<<std::endl;
        std::cout<<cible.getNom()<<": perd "<<this->getDegats()<<" points de vies"<<std::endl;
        cible.recevoirDegat(this->getDegats());
        std::cout<<"il lui reste "<<cible.getVie()<<" points de vies"<<std::endl<<std::endl;
    }
    else if (choix=='p')
    {
        this->utiliserPotion();
        std::cout<<this->getNom()<<" regagne 30 point de vie"<<std::endl;
        this->regagnerVie(30);
    }
    else if (choix=='s')
    {
        this->utiliserMana(20);
        std::cout<< this->getNom()<<" attaque "<<cible.getNom()<<std::endl;
        std::cout<<this->getNom()<<" lance une boule de feu"<<std::endl;
        std::cout<<cible.getNom()<<": perd 30 points de vies"<<std::endl;
        cible.recevoirDegat(30);
        std::cout<<"il lui reste "<<cible.getVie()<<" points de vies"<<std::endl<<std::endl;
    }
}

void Hero::afficherEtat()const
{
    Personnage::afficherEtat();
    std::cout<<"j'ai encore "<<getMana()<<" points de Mana"<<std::endl;
    std::cout<<"il me reste "<<getPotion()<<" Potions"<<std::endl;
    std::cout<<"et je possede "<<getArgent()<<" pieces d'or"<<std::endl;
}

void Hero::sePresenter()const
{
    std::cout<<"je suis le hero ";
    afficherEtat();
}

