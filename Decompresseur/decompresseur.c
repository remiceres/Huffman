#include "decompresseur.h"
#include "../Compresseur/constrcArbre.h"
#include <stdlib.h>


int verif_octets_magiques(FILE* input_compress)
{
  return fgetc(input_compress)=='a' && fgetc(input_compress)=='b' && fgetc(input_compress)==20;
}

void reconstruction_arbre_recursion(Noeud* arbre, int* i)
{
  
}

int reconstruction_arbre(FILE* input_compress)
{
  //déclaration et initialisation de l'arbre
  Noeud* arbre = malloc(sizeof(Noeud));
  initabl(NULL,arbre);

  //FONCTION : recursive qui met les valeurs dans l'arbre
  int prochain_indice = 256;
  reconstruction_arbre_recursion(arbre, &prochain_indice);
}

int decompresseur(FILE* input_compress)
{
  //FONCTION : verifie la présences des octect magique
  if ( !verif_octets_magiques(input_compress) )
  {
    return ERR_FORMAT;
  }

  //définition et récupération du nombre de 0 inutile a la fin du fichier
  int nb_0_inutile = (int)fgetc(input_compress);

  //FONCTION reconstruction de l'arbre
  int* racine = reconstruction_arbre(input_compress);


return 0;
}


//TODO : libéré, délivré ou tu ne le détruira jamais (l'arbre)
//TODO : VALGRIND
