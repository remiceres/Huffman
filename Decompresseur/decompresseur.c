#include "decompresseur.h"
#include "../Compresseur/constrcArbre.h"
#include <stdlib.h>


int verif_octets_magiques(FILE* input_compress)
{
  return fgetc(input_compress)=='a' && fgetc(input_compress)=='b' && fgetc(input_compress)==20;
}

int reconstruction_arbre_recursion(FILE* input_compress, Noeud* arbre, int* i)
{
  if( fgetc(input_compress)==0 )
  {
    return fgetc(input_compress);
  }
  else
  {
    arbre[*i].fg=reconstruction_arbre_recursion(input_compress,arbre,i);
    arbre[*i].fd=reconstruction_arbre_recursion(input_compress,arbre,i);
    *i = *i +1;
    return *i-1;
  }
}

Noeud* reconstruction_arbre(FILE* input_compress)
{
  //déclaration et initialisation de l'arbre
  Noeud* arbre = malloc(sizeof(Noeud));
  initabl(NULL,arbre);

  //FONCTION : recursive qui met les valeurs dans l'arbre
  int prochain_indice = 256;
  reconstruction_arbre_recursion(input_compress, arbre, &prochain_indice);
  return arbre;
}

void decodage_caracteres(FILE* input_compress,FILE* output_compress,Noeud* arbre )
{
  int indice = 256;
  while ( !feof(input_compress) )
  {
    int octet_actuel = fgetc(input_compress);

    for(int bit_actuel = 7 ; bit_actuel>=0 ; bit_actuel--)
    {
      if ( (octet_actuel >> bit_actuel) % 2 )
      {
        if ( arbre[indice].fd == -1 )
        {
          fputc(indice, output_compress);
          indice=256;
        }
        else
        {
          indice = arbre[indice].fd;
        }
      }
      else
      {
        if ( arbre[indice].fg == -1 ) ///A A A A A EXTRAIIIIRE
        {
          fputc(indice, output_compress);
          indice=256;
        }
        else
        {
          indice = arbre[indice].fg;
        }
      }
    }
  }
}


int decompresseur(FILE* input_compress, FILE* output_compress)
{
  //FONCTION : verifie la présences des octect magique
  if ( !verif_octets_magiques(input_compress) )
  {
    return ERR_FORMAT;
  }

  //définition et récupération du nombre de 0 inutile a la fin du fichier
  int nb_0_inutile = fgetc(input_compress);

  //FONCTION reconstruction de l'arbre
  Noeud* arbre = reconstruction_arbre(input_compress);

  //FONCTION écriture des carracteres
  decodage_caracteres(input_compress,output_compress, arbre);



return 0;
}


//TODO : libéré, délivré ou tu ne le détruira jamais (l'arbre)
//TODO : VALGRIND
