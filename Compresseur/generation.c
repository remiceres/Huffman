#include "generation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int decoder_buffer(char* buffer, int quantite_utilise) {
  int somme = 0;
  int nb_decode = quantite_utilise > 8 ? 8 : quantite_utilise;

  for (int i = 0 ; i < nb_decode ; i++)
  {
    if ( buffer[i] == '1' ) {
      somme += 1;
    }

    if ( i < nb_decode - 1 ) {
      somme <<= 1;
    }
  }

  somme <<= 8 - nb_decode;
  return somme;
}

void decaler_buffer(char* buffer, int quantite_utilise) {
  for (int i = 8; i <= quantite_utilise; i++)
  {
    buffer[i - 8] = buffer[i];
  }
}

void ecriture_arbre(Noeud* arbre, int racine, FILE* sortie)
{
  if (arbre[racine].fg == -1)
  {
    // Je suis une feuille
    fputc(0,sortie);
    fputc(racine,sortie);
  }
  else
  {
    // Je suis un noeud
    fputc(1,sortie);
    ecriture_arbre(arbre, arbre[racine].fg, sortie);
    ecriture_arbre(arbre, arbre[racine].fd, sortie);
  }
}

void encodage(char** index, FILE* entre, FILE* sortie, int nbCaractere, int racine, Noeud* arbre)
{
  //remer le cursseur de lecture au début du fichier
  rewind(entre);

  //crée un buffer et initialisation a 0
  char buffer[262] = "";

  unsigned int caractereLecture = '\0';

  //écriture des octect magiques
  fputc('a',sortie);
  fputc('b',sortie);
  fputc(20,sortie);//ecrit le caractére numéro 20

  //reserve place pour conter les 0 inutile de fremin
  fputc('\0', sortie);

  //nombre de carractère différent
//  fwrite(&nbCaractere, sizeof(nbCaractere), 1, sortie);


  //eccriture de l'arbre
  if (racine != -1)
  {
    ecriture_arbre(arbre, racine, sortie);
  }


  //boucle comte le nombre de caractere dans le fichier + incrémente dans le tableau le carractére trouvé.
  int quantite_utilise = 0;

  if (entre != NULL)
  {
    while( (caractereLecture = fgetc(entre) ) != EOF )
    {
      strcat(buffer, index[(size_t)caractereLecture] );
      quantite_utilise += strlen(index[(size_t) caractereLecture]);

      while ( quantite_utilise >= 8 )
      {
        int octet = decoder_buffer(buffer, quantite_utilise);
        fputc(octet, sortie);

        decaler_buffer(buffer, quantite_utilise);
        quantite_utilise -= 8;
      }
    }
  }

  else
  {
    fprintf(stderr, "Le fichier est illisible \n");
    exit(1);
  }

  if ( quantite_utilise > 0 )
  {
    int octet = decoder_buffer(buffer, quantite_utilise);
    fputc(octet, sortie);
  }
  else
  {
    quantite_utilise = 8;
  }

  //eccriture du nombre de 0 inutile
  fseek(sortie, 3 , SEEK_SET);
  fputc( quantite_utilise, sortie);


  fclose(sortie);
  fclose(entre);

}
