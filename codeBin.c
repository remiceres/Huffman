#include "codeBin.h"
#include "defNoeud.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//ajout 1 ou 0 a la fin de la chaine
char* nouvelleChaine(int longanciennechaine, char* anciennechaine, char vallAjout)
{

  //déclaration de la nouvelle chaine
  char* nouvelleChaine = (char*) malloc((longanciennechaine+1)*sizeof(char));

  //copie des ancienne valeurs de la chaine
  strcpy(nouvelleChaine,anciennechaine);
  // ajout de la nouvelle valeurs
  nouvelleChaine[longanciennechaine-1] = vallAjout;
  nouvelleChaine[longanciennechaine] = '\0';




  return nouvelleChaine;
}


// fonction crée les codes binaires
void initIndex(char** codes, Noeud* arbre, int actuel, char* chaine, int longchaine)
{

  if(arbre[actuel].fg==-1 && arbre[actuel].fd==-1)
  {

    codes[(size_t) actuel] = chaine;
  }
  else
  {
    initIndex(codes, arbre, arbre[actuel].fg, nouvelleChaine(longchaine, chaine, '0'), longchaine+1 );
    initIndex(codes, arbre, arbre[actuel].fd, nouvelleChaine(longchaine, chaine, '1'), longchaine+1 );

    //libération de l'ancienne chaine
    free(chaine);
  }
}


char** codeBin(Noeud* arbre, int racine)
{
  //déclaration du tableau des codes binaire de chaque lettre
  char** codes = (char**) malloc( sizeof(char*) * 256 );
  for(int i=0; i<256 ; i++)
  {
    codes[i]=NULL;
  }

  //construction de tableau de chaine de caractere
  char* chaineVide = (char*)malloc(sizeof(char)) ;
  chaineVide[0]='\0';

  if (racine != -1)
  {
    initIndex(codes, arbre, racine, chaineVide, 1);
  }
  else
  {
    return NULL;
  }




return codes;
}
