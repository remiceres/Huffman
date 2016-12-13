#include "../include/constrcArbre.h"
#include <stdlib.h>
#include <stdio.h>


//FONCTION : initialisation de l'arbre
void IniTabl(double* tabfrequence, Noeud* Arbre)
{
    //initialisation de pere, fg, fd et frequences
    for(int i=0 ; i<511 ; i++)
    {
        Arbre[i].pere=-1;
        Arbre[i].fg=-1;
        Arbre[i].fd=-1;
        Arbre[i].frequences=0;
    }

    //initialisation des fréquences avec les valeurs à partir du tableau de frequences calculées a partir du fichier d'entrée
    if ( tabfrequence != NULL)
    {
        for(int j=0 ; j<256 ; j++)
        {
            Arbre[j].frequences = tabfrequence[j];
        }
    }
}


//FONCTION : determine les deux noeud de frequence les plus faibles
int NoeudMin(Noeud* Arbre, int Indice_precedent)
{
    double Frequence_min = 1;
    int Indice_min = -1;

    for(int i=0 ; i<511 ; i++)
    {
        if (Arbre[i].frequences > 0  &&  Arbre[i].frequences <= Frequence_min
            && Arbre[i].pere == -1  &&  i != Indice_precedent)
        {
            Frequence_min = Arbre[i].frequences;
            Indice_min = i;
        }
    }

  return Indice_min;


}

void NoeudPere(Noeud* Arbre, int* Nouv_noeud, int Indice_min1, int Indice_min2)
{

    if ( Indice_min2 != -1) //si 2 fils sont disponibles
    {
        Arbre[*Nouv_noeud].fg = Indice_min1;
        Arbre[*Nouv_noeud].fd = Indice_min2;
        Arbre[*Nouv_noeud].frequences = Arbre[Indice_min1].frequences + Arbre[Indice_min2].frequences;

        Arbre[Indice_min1].pere = *Nouv_noeud;
        Arbre[Indice_min2].pere = *Nouv_noeud;
    }
    else
    {
        if ( Indice_min1 == -1 ) // si aucun fils n'est disponible
        {
            *Nouv_noeud = -1;
        }
        else //si 1 seul fils est disponible
        {
            Arbre[*Nouv_noeud].fg = Indice_min1;
            Arbre[*Nouv_noeud].fd = '\0';

            Arbre[Indice_min1].pere = *Nouv_noeud;
            Arbre['\0'].pere = *Nouv_noeud;

            Arbre[*Nouv_noeud].frequences = Arbre[Indice_min1].frequences + Arbre['\0'].frequences;


        }
    }
    (*Nouv_noeud)++;
}

int ConstrcArbre(double* Tab_frequence, Noeud* Arbre)
{
    //initialisation de l'arbre
    IniTabl(Tab_frequence,Arbre);

    //compte le nombre de feuilles
    int Nb_Feuilles = 0;

    for (int i=0 ; i<256 ; i++)
    {
        if (Tab_frequence[i] > 0)
        {
            Nb_Feuilles++;
        }
    }

    //compte le nombre de Noeuds
    int Nb_noeud = 2 * Nb_Feuilles - 1;
    int Noeuds_utilises = Nb_Feuilles;

    //trouve les noeuds minimaux et construction de l'arbre
    int Indice_min1;
    int Indice_min2;
    int Nouv_noeud = 256;

  do
  {

    Indice_min1 = NoeudMin(Arbre, -1);

    Indice_min2 = NoeudMin(Arbre, Indice_min1);

    NoeudPere(Arbre, &Nouv_noeud, Indice_min1, Indice_min2);

    Noeuds_utilises++;

    } while (Noeuds_utilises < Nb_noeud);


    return Nouv_noeud - 1;
}
