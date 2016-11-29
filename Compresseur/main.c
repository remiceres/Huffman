#include "frequences.h"
#include "constrcArbre.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "defNoeud.h"
#include "codeBin.h"
#include "generation.h"


int main(int argc, char** argv)
{
  if(argc != 2)
  {
    fprintf(stderr, "usage %s <Fichier>  \n", argv[0] );
    return 1;
  }

  //ouverture du fichier
  FILE* fichier;
  fichier = fopen( argv[1] , "r" );

  if (fichier == NULL)
  {
    fprintf(stderr, "Le fichier est illisible : %s\n", strerror(errno));
    exit(1);
  }


  double* tab = calculFrequences(fichier);




  //Déclaration de l'arbre
  Noeud arbre[511];
  //déclaration de l'indice de la racine
  int indRacine;
  //déclaration du nombre de noeud différent
  int nbCaractere;
  //construction de l'arbre
  constrcArbre(tab, arbre, &indRacine, &nbCaractere);


  //création de l'index
  char** index = codeBin(arbre, indRacine);

  //test affiche
  if (indRacine != -1)
  {
    for (int i=0 ; i<256 ; i++)
    {
      if( index[i] != NULL)
      {
        printf("%3d : %16s\n", i, index[i]);
      }
    }
  }

  //ouverture du fichier sortie
  FILE* sortie;
  sortie = fopen( strcat(argv[1],".huff") , "w" );

  encodage(index, fichier, sortie, nbCaractere, indRacine, arbre);



  // FIXME: Penser à désallouer le tableau de fréquences
  // FIXME: Penser à désallouer le tableau de initIndex
  // FIXME: Désallouer les tabeaux des chaînes
  //  TODO: Traiter les cas particuliers
  //  TODO: Fermer le fichier a compréssé
  //  TODO:fremer le ficher de sortie




  return 0;
}
