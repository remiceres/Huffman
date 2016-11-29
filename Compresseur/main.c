#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "frequences.h"
#include "constrcArbre.h"
#include "defNoeud.h"
#include "codeBin.h"
#include "generation.h"

void compression(char* nomFichier)
{
    //ouverture du fichier
    FILE* input;
    input = fopen( nomFichier , "r" );

    if (input == NULL)
    {
      fprintf(stderr, "Le fichier est illisible : %s\n", strerror(errno));
      exit(1);
    }

    //FONCTION : calcule les frequences d'apparition des carractére dans le fichier a compréssé
    double* tab = calculFrequences(input);

    //Déclaration de l'arbre
    Noeud arbre[511];
    //déclaration de l'indice de la racine
    int indRacine;
    //déclaration du nombre de noeud différent
    int nbCaractere;


    //FONCTION : construction de l'arbre
    constrcArbre(tab, arbre, &indRacine, &nbCaractere);


    //FONCTION : création de l'index
    char** index = codeBin(arbre, indRacine);


    // //test affiche
    // if (indRacine != -1)
    // {
    //   for (int i=0 ; i<256 ; i++)
    //   {
    //     if( index[i] != NULL)
    //     {
    //       printf("%3d : %16s\n", i, index[i]);
    //     }
    //   }
    // }

    //ouverture du fichier sortie
    FILE* output;
    output = fopen( strcat(nomFichier,".huff") , "w" );

    //fonction ecriture fichier sortie
    encodage(index, input, output, nbCaractere, indRacine, arbre);
}

int main(int argc, char** argv)
{

    //vérifie le nombre d'arguments.
    if(argc != 2)
    {
      fprintf(stderr, "usage %s <Fichier>  \n", argv[0] );
      return 1;
    }







  // FIXME: Penser à désallouer le tableau de fréquences
  // FIXME: Penser à désallouer le tableau de initIndex
  // FIXME: Désallouer les tabeaux des chaînes
  //  TODO: Traiter les cas particuliers
  //  TODO: Fermer le fichier a compréssé
  //  TODO:fremer le ficher de sortie




  return 0;
}
