#include"personnage.h"

Personnage::Personnage():m_nom("monstre"), m_vie(10), isAlive(true)
{

}
Personnage::Personnage(std::string nom,int vie,int degat):m_nom(nom),m_vie(vie),m_degat(degat), isAlive(true)
{

}

Personnage::~Personnage()
{
}

std::string  Personnage::getNom()const
{
    return m_nom;
}


int Personnage::getVie()const
{
    return m_vie;
}

int Personnage::getDegats()const
{
    return m_degat;
}

bool Personnage::getIsAlive()const
{
    return isAlive;
}

void Personnage::recevoirDegat(int degat)
{
    m_vie -=degat;
    if (m_vie<=0)
    {
        m_vie=0;
        isAlive=false;
    }
}

void Personnage::afficherEtat()const
{
    std::cout<<this->getNom()<<" :"<< std::endl;
    if(isAlive==true)
    {
        std::cout<<"il me reste: "<<this->getVie()<<" points vies"<< std::endl;
    }
    else{std::cout<<"est mort"<< std::endl;}

}

void Personnage::attaque(Personnage &cible)
{
    std::cout<< this->getNom()<<" attaque "<<cible.getNom()<<std::endl;
    std::cout<<cible.getNom()<<": perd "<<this->getDegats()<<" points de vies"<<std::endl;
    cible.recevoirDegat(m_degat);
    std::cout<<"il lui reste "<<cible.getVie()<<" points de vies"<<std::endl<<std::endl;

}

void Personnage::combat(Personnage *b)
{
    std::cout<<"debut du combat de "<<this->getNom()<<" contre "<< b->getNom()<<std::endl<<std::endl;
    do
    {
        if(this->getIsAlive()==true)
        {
            this->attaque(*b);
        }
        if( b->getIsAlive()==true)
        {
            b->attaque(*this);
        }

    }while(b->getIsAlive()==true && this->getIsAlive()==true);

    if(this->getIsAlive()==true)
    {
         std::cout << this->getNom() <<" sort victorieux de se combat"<<std::endl<<std::endl;
         this->isAlive=true;
         this->afficherEtat();
    }
    else if(b->getIsAlive()==true)
    {
        std::cout << b->getNom() <<" sort victorieux de se combat"<<std::endl<<std::endl;
        b->afficherEtat();
    }
}



