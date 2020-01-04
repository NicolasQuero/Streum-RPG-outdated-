#ifndef SMONSTRE_H_INCLUDED
#define SMONSTRE_H_INCLUDED

#include <ctime>
#include <vector>
#include"personnage.h"

class sMonstre : public Personnage
{

private:
    int m_niveau;

public:

    sMonstre(std::string nom, int niveau);
    virtual ~sMonstre();

    int getNiveau();
    int IARandom(std::vector<int> PlacesLibres);
};


#endif // SMONSTRE_H_INCLUDED
