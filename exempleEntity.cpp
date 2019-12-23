#include"personnage.h"

Entity::Entity() : m_nom("monstre"), m_vie(10), isAlive(true)
{

}
Entity::Entity(std::string nom,int vie,int degat):m_nom(nom),m_vie(vie),m_degat(degat)
{

}

Entity::~Entity()
{
}

std::string  Entity::getNom()const
{
    return m_nom;
}


int Entity::getVie()const
{
    return m_vie;
}

int Entity::getDegats()const
{
    return m_degat;
}

bool Entity::getIsAlive()const
{
    return isAlive;
}



void Entity::recevoirDegat(int degat)
{
    m_vie -=degat;
    if (m_vie<=0)
    {
        m_vie=0;
        isAlive=false;
    }
}

void Entity::afficherEtat()const
{
    std::cout<<this->getNom()<<" :"<< std::endl;
    if(isAlive==true)
    {
        std::cout<<"il me reste: "<<this->getVie()<<" points vies"<< std::endl;
    }
    else{std::cout<<"est mort"<< std::endl;}

}

void Entity::attaque(Entity &cible)
{
    std::cout<< this->getNom()<<" attaque "<<cible.getNom()<<std::endl;
    std::cout<<cible.getNom()<<": perd "<<this->getDegats()<<" points de vies"<<std::endl;
    cible.recevoirDegat(m_degat);
    std::cout<<"il lui reste "<<cible.getVie()<<" points de vies"<<std::endl<<std::endl;

}

void Entity::combat(Entity&b)
{
    std::cout<<"debut du combat de "<<this->getNom()<<" contre "<< b.getNom()<<std::endl<<std::endl;
    while(b.getIsAlive()==true&&this->getIsAlive()==true)
    {
        if(this->getIsAlive()==true)
        {

            this->attaque(b);
        }
        if( b.getIsAlive()==true)
        {
            b.attaque(*this);
        }
    }
    if(this->getIsAlive()==true)
    {
         std::cout << this->getNom() <<" sort victorieux de se combat"<<std::endl<<std::endl;
         this->isAlive=true;
         this->afficherEtat();
    }
    else if(b.getIsAlive()==true)
    {
        std::cout << b.getNom() <<" sort victorieux de se combat"<<std::endl<<std::endl;
        b.afficherEtat();
    }
}
