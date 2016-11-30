#include "constrcArbre.h"
#include <stdlib.h>
#include <stdio.h>


//(fonction) initialisation de l'arbre
void initabl(double* tabfrequence, Noeud* arbre)
{
  //initialisation de pere, fg, fd et frequences
  for(int i=0 ; i<511 ; i++)
  {
    arbre[i].pere=-1;
    arbre[i].fg=-1;
    arbre[i].fd=-1;
    arbre[i].frequences=0;
  }

  //initialisation des fréquences avec les valeurs a partir du tableau de frequences calculer a partir du document
  if ( tabfrequence != NULL)
  {
    for(int j=0 ; j<256 ; j++)
    {
      arbre[j].frequences = tabfrequence[j];
    }
  }
}


//fonction qui determine les deux noeuds de frequences les plus faibles
void noeudMin(Noeud* arbre, int* indice_1, double* frequences_1, int indiceprecedent)
{
  double fremin = 1;
  int indicefremin = -1;

  for(int i=0 ; i<511 ; i++)
  {
    if (arbre[i].frequences > 0 && arbre[i].frequences <= fremin)
    {

      if (arbre[i].pere == -1  &&  i != indiceprecedent)
      {
        fremin = arbre[i].frequences;
        indicefremin = i;
      }
    }
  }

  *indice_1 = indicefremin;
  *frequences_1 = arbre[indicefremin].frequences;


}

void NoeudPere(Noeud* arbre, int indicemin1, int indicemin2, int* nouvNoeud)
{
  if ( indicemin2!=-1)
  {
    arbre[*nouvNoeud].fg = indicemin1;
    arbre[*nouvNoeud].fd = indicemin2;
    arbre[*nouvNoeud].frequences = arbre[indicemin1].frequences + arbre[indicemin2].frequences;

    arbre[indicemin1].pere = *nouvNoeud;
    arbre[indicemin2].pere = *nouvNoeud;

    printf("indicemin1 = %d | indicemin2 = %d | noeudPere= = %d | frequence Noeud pere : %f \n", indicemin1, indicemin2, *nouvNoeud, arbre[*nouvNoeud].frequences);
  }
  else
  {
    *nouvNoeud = indicemin1;
  }
  (*nouvNoeud)++;


}






void constrcArbre(double* tabfrequence, Noeud* arbre, int* indRacine, int* nbCarractere)
{

  //initialisation de l'arbre
  initabl(tabfrequence,arbre);

  //trouver le noeuds minimeaux
  int indicemin1;
  double frequencesmin1;
  int indicemin2;
  double frequencesmin2;

  int nouvnoeud = 256;

  //////////

  int compteur_Feuilles = 0;

  for (int i = 0; i < 256; i++) {
    if (tabfrequence[i] > 0) {
      compteur_Feuilles++;
    }
  }

  int compteur_Noeud = 2 * compteur_Feuilles - 1;
  int noeuds_utilises = compteur_Feuilles;

  /////////

  do {

    noeudMin(arbre, &indicemin1, &frequencesmin1, -1); // FrequenceMin1 ne sert a rien il n'est pas utilisé par la suite

    noeudMin(arbre, &indicemin2, &frequencesmin2, indicemin1);// idem pour fmin2

    // printf("Indice 1 : %d  |  Indice 2 : %d\n", indicemin1, indicemin2);

    NoeudPere(arbre, indicemin1, indicemin2, &nouvnoeud);
    noeuds_utilises++;

  } while (noeuds_utilises < compteur_Noeud);

  *nbCarractere = compteur_Feuilles;
  *indRacine = nouvnoeud-1;

}
