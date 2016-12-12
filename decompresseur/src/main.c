#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "../include/defNoeud.h"
#include "../include/decompresseur.h"

FILE* OuvertureFichier(char* nom_fichier, char* option)
{
    //ouverture du fichier
    FILE* fichier;
    fichier = fopen( nom_fichier , option );

    if ( fichier==NULL && strcmp("r",option) )
    {
      fprintf(stderr, "Le fichier d'entrée est illisible : %s \n", strerror(errno));
      exit(1);
    }

    if ( fichier==NULL && strcmp("w",option) )
    {
        fprintf(stderr, "Le fichier de sortie est non inscriptible : %s \n", strerror(errno));
        exit(1);
    }

    return fichier;
}

int main(int argc, char** argv)
{
    //vérifie le nombre d'arguments.
    if(argc!=2)
    {
        fprintf(stderr, "Usage: dehuf [Fichier source] \n" );
        return 1;
    }

    //ouverture des fichiers d'entrée et de sortie
    FILE* Entree = OuvertureFichier( argv[1], "r" );
    FILE* Sortie = OuvertureFichier( "Résultat", "w" );

    //Decompression
    Decompression(Entree, Sortie);

    // Pour améliorer affichage du fichier de sortie sur le terminal
    printf("\n");

    //fermeture des fichiers
    fclose(Entree);
    fclose(Sortie);

    return 0;
}
