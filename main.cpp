#include <iostream>

#include"Pos.h"
#include"Hero.h"
#include "Jeu.h"
#include"carte.h"
#include"sMonstre.h"

int deroulementJeu(Jeu *j,int k,Hero *h);
void MonstrePresentCombat(int nbMOb,Pos *p,Personnage *h, Carte *c);
void deplacementHero(Jeu *j, Carte *c,Hero *h);
void deplacementMob(Carte *c,Hero *h);

using namespace std;

int main()
{
    Jeu j;
    cout<<"comment voulez-vous appeler votre Hero ?"<<endl;
    string nom;
    cin>> nom;
    Hero h(nom);
    h.sePresenter();
    j.afficherMiniMap();
    int k=-1;
    do
    {
        k=deroulementJeu(&j,k,&h);
    }while(j.getNomMap()!="fin");
    if (j.getNomMap()=="fin"){cout<<"vous avez gagner";}
    return 0;
}


int deroulementJeu(Jeu *j,int k,Hero *h)
{
    Carte c(j->getNomMap());  //on cree la carte en fonction d'ou se situe le joueur
    Pos p(&c); //on regarde les elements present sur la map et leurs position( monstre, cle ...)
    c.creaPorte(j,p.getCle()); // on cree les portes
    if(k==0){c.modifierValeurCarte('J',(c.getHauteur()-2),(c.getLongueur())/2);} // on vient d'en bas, on cree le joueur en bas
    else if(k==1){c.modifierValeurCarte('J',1,(c.getLongueur())/2);}//... d'en haut,... en haut
    else if(k==2){c.modifierValeurCarte('J',(c.getHauteur())/2,(c.getLongueur())-2);}//... de gauche,... a gauche
    else if(k==3){c.modifierValeurCarte('J',(c.getHauteur())/2,1);}//... de droite,... a droite
    else if(k==-1){c.modifierValeurCarte('J',(c.getHauteur())/2,(c.getLongueur())/2);}//on ne viens de nul part ( debut de partie ou teleportation )
    do
    {
        deplacementHero(j,&c,h);
        deplacementMob(&c,h);
    }while(c.getCharCarte(0,(c.getLongueur())/2)!='J' && c.getCharCarte(c.getHauteur()-1,(c.getLongueur())/2)!='J'  // on regarde si le joueur ne se situe pas sur une porte ouverte.
            && c.getCharCarte((c.getHauteur())/2,0)!='J' && c.getCharCarte((c.getHauteur())/2,c.getLongueur()-1)!='J');

    if(c.getCharCarte(0,(c.getLongueur())/2)=='J'){j->deplacementMiniMapHaut() , k=0;}  // on change de map, en retenant d'ou vient le joueur
    if(c.getCharCarte(c.getHauteur()-1,(c.getLongueur())/2)=='J'){j->deplacementMiniMapBas() , k=1;}
    if(c.getCharCarte((c.getHauteur())/2,0)=='J'){j->deplacementMiniMapGauche() , k=2 ;}
    if(c.getCharCarte((c.getHauteur())/2,c.getLongueur()-1)=='J'){j->deplacementMiniMapDroite() , k=3;}
    j->afficherMiniMap();
    return k;
}


void deplacementHero(Jeu *j, Carte *c,Hero *h)
{
    Pos p(c);  //on regarde les elements present sur la map ( monstre, cle ...) et leurs position qui sera modifie a chaque tour
    c->afficherCarte();
    c->creaPorte(j,p.getCle()); // on aura a recree les portes si on a les cle ( les ouvrir)
    p.ChoixDeplacement(p.deplacementPossible(p.getPosJ()),p.getPosJ(),j,h);
    int nbMOb=p.detectionMob(p.getPosJ()).size(); // on regarde la presence de monstre autour du joueur
    if(nbMOb>0){MonstrePresentCombat(nbMOb,&p,h,c);} // on lance le combat si un Monstre est present
    cout<<endl;
}

void deplacementMob(Carte *c,Hero *h)
{
      Pos p(c);
      int taillePosp=p.getTaille();
      for(int i=0;i<taillePosp;i++)
      {
          if(p.getNom(i)=='s'||p.getNom(i)=='S')
          {
              sMonstre s("Monstre s",1);
              int ChoixDepalcement=s.IARandom(p.deplacementPossible(i));
              p.deplacement(ChoixDepalcement,i);
              //int nbMOb=p.detectionMob(i).size();
              //if(nbMOb>0){MonstrePresentCombat(nbMOb,&p,&s,c);}
          }
      }
}

void MonstrePresentCombat(int nbMOb,Pos *p,Personnage *h, Carte *c)
{
    c->afficherCarte();
    for(int i=0;i<nbMOb;i++)
    {
        if(p->getNom(p->detectionMob(p->getPosJ())[i])=='s') //on lance un combat en fonction de quel monstre on affronte
        {
            sMonstre s("Monstre s",1);
            h->combat(&s);
        }
        else if(p->getNom(p->detectionMob(p->getPosJ())[i])=='S')
        {
            sMonstre s("Monstre S",2);
            h->combat(&s);
        }
        c->modifierValeurCarte(' ',p->getPositionY(p->detectionMob(p->getPosJ())[i]),p->getPositionX(p->detectionMob(p->getPosJ())[i])); // on libere la place si le monstre meurt
    }
}
