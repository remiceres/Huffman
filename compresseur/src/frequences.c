#include <stdlib.h>
#include <stdio.h>

#include "../include/frequences.h"

double* CalculFrequencesCaractere(FILE* fichier)
{
  //Déclaration du tableau de frequences.
  double* tab_frequence=(double*)malloc(256*sizeof(double));


  //initialisation du tableau
  for(int i=0 ; i<256 ; i++)
  {
    tab_frequence[i]=0;
  }

  //compte le nombre caractere total + nombre d'apparition de chaque carractère.
  unsigned int caractereLecture = '\0';
  int compteur = 0;

  while( ( (caractereLecture = fgetc(fichier)) ) != EOF )
  {
    compteur++;
    tab_frequence[caractereLecture]++;
  }

  //calcule les fréquences
  if ( compteur!=0 )
  {
      for(int j=0 ; j < 256 ; j++ )
      {
          tab_frequence[j] /= compteur;
      }
  }

return tab_frequence;
}
