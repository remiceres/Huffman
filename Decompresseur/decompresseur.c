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
    int position = *i;
    (*i)++;

    arbre[position].fg=reconstruction_arbre_recursion(input_compress,arbre,i);
    arbre[position].fd=reconstruction_arbre_recursion(input_compress,arbre,i);
    printf("Indice actuel : %d | Indice gauche : %d  |  Indice droit : %d\n",position, arbre[position].fg, arbre[position].fd);

    return position;
  }
}

Noeud* reconstruction_arbre(FILE* input_compress)
{
  //déclaration et initialisation de l'arbre
  Noeud* arbre = malloc(511 * sizeof(Noeud));
  initabl(NULL,arbre);

  //FONCTION : recursive qui met les valeurs dans l'arbre
  int prochain_indice = 256;
  reconstruction_arbre_recursion(input_compress, arbre, &prochain_indice);
  return arbre;
}
int verif_dernier_octet(FILE* input_compress, int octet_actuel)
{

  if ( (octet_actuel = getc(input_compress))!= EOF )
  {
    fseek(input_compress,-1, SEEK_CUR);
    return 0;
  }
  fseek(input_compress,-1, SEEK_CUR);
  return 1;
}

void decodage_caracteres(FILE* input_compress,FILE* output_compress,Noeud* arbre, int quantite_utilise )
{
  int indice = 256;

  int octet_actuel;
  int decalage = 0;
  int fin;

  do
  {

    octet_actuel=fgetc(input_compress);
    fin = verif_dernier_octet(input_compress, octet_actuel);

    if (fin) {
      decalage = 8 - quantite_utilise ;
    }

    for(int bit_actuel = 7 ; bit_actuel >= decalage ; bit_actuel--)
    {

      if ( (octet_actuel >> bit_actuel) % 2 )
      {
        if ( arbre[arbre[indice].fd].fd == -1 )
        {
          printf("%d ", ( octet_actuel>>bit_actuel) % 2 );
          printf("indice : %c \n", arbre[indice].fd);
          fputc(arbre[indice].fd, output_compress);
          indice=256;
        }
        else
        {
          printf("%d ", ( octet_actuel>>bit_actuel) % 2 );

          indice = arbre[indice].fd;
        }
      }
      else
      {
        if ( arbre[arbre[indice].fg].fg == -1 ) ///A A A A A EXTRAIIIIRE
        {
          printf("%d ", ( octet_actuel>>bit_actuel) % 2 );
          printf("indice : %c \n", arbre[indice].fg);

          fputc(arbre[indice].fg, output_compress);
          indice=256;
        }
        else
        {
          printf("%d ", ( octet_actuel>>bit_actuel) % 2 );

          indice = arbre[indice].fg;
        }
      }
    }
  }while ( !fin );
}


int decompresseur(FILE* input_compress, FILE* output_compress)
{
  //FONCTION : verifie la présences des octect magique
  if ( !verif_octets_magiques(input_compress) )
  {
    return ERR_FORMAT;
  }

  //définition et récupération du nombre de 0 inutile a la fin du fichier
  int quantite_utilise = fgetc(input_compress);
  printf("%i\n", quantite_utilise );

  //FONCTION reconstruction de l'arbre
  Noeud* arbre = reconstruction_arbre(input_compress);

  //FONCTION écriture des carracteres
  decodage_caracteres(input_compress,output_compress, arbre, quantite_utilise);



return 0;
}


//TODO : libéré, délivré ou tu ne le détruira jamais (l'arbre)
//TODO : VALGRIND
