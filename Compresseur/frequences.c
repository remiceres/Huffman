#include <stdlib.h>
#include <stdio.h>

#include "frequences.h"

double* calculFrequences(FILE* fichier)
{
  //Déclaration et initialisation du tableau de frequences.
  double* frequences=(double*)malloc(256*sizeof(double));

  for(int a=0 ; a<256 ; a++)
  {
    frequences[a]=0;
  }

  unsigned int caractereLecture = '\0';
  int compteur = 0;

  //boucle comte le nombre de caractere dans le fichier + incrémente dans le tableau le carractére trouvé.

  while( ( (caractereLecture = fgetc(fichier)) ) != EOF )
  {
    compteur++;
    frequences[caractereLecture]++;
  }




  //calcule les fréquences
  for(int j=0 ; j < 256 ; j++ )
  {
    frequences[j] /= compteur;
  }


  //(test) affichage
  for(int a=0 ; a<256 ; a++)
  {
    printf("%d = %f\n", a , frequences[a]);
  }


return frequences;
}
