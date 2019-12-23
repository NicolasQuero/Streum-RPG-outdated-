#ifndef MONSTRE_H_INCLUDED
#define MONSTRE_H_INCLUDED

#include"personnage.h"

class Monstre : public Personnage
{

private:

public:

    Monstre(std::string nom, int niveau);
    virtual ~Monstre();

};



#endif // MONSTRE_H_INCLUDED
