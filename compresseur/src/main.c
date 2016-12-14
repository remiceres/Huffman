#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


#include "../include/frequences.h"
#include "../include/constrcArbre.h"
#include "../include/defNoeud.h"
#include "../include/codeBin.h"
#include "../include/generation.h"

void AffichageArbre(Noeud* Arbre, int Ind_racine)
{
    if(Ind_racine!=-1)
    {

        printf("│ %-5d │ %-11d │ %-10d │ %-4d │ %-10f │\n", Ind_racine, Arbre[Ind_racine].fg, Arbre[Ind_racine].fd, Arbre[Ind_racine].pere, Arbre[Ind_racine].frequences );
        AffichageArbre(Arbre, Arbre[Ind_racine].fg);
        AffichageArbre(Arbre, Arbre[Ind_racine].fd);
    }
}

long int CalculeTaille(FILE* Fichier)
{
    fseek(Fichier, 0, SEEK_END);
    return ftell(Fichier);
}

void Compression(FILE* Entree,FILE* Sortie)
{

    //FONCTION : calcule les frequences d'apparition des caractères dans le fichier a compresser
    double* Tab_frequence = CalculFrequencesCaractere(Entree);

    //Affichage des fréquences de chaque caractère si non null
    printf("\nCaractères et leur probabilité d’apparition :\n");
    printf("┌────────────┬──────────────────────────┐\n");
    printf("│ Caractères │ Probabilité d’apparition │\n");
    printf("├────────────┼──────────────────────────┤\n");


    for(int a=0 ; a<256 ; a++)
    {
        if( Tab_frequence[a] != 0)
        {
            printf("│%-11d │%-25f │\n", a , Tab_frequence[a]);

        }
    }
    printf("└────────────┴──────────────────────────┘ \n");
    printf("\n \n");




    //Déclaration de l'arbre
    Noeud Arbre[511];

    //déclaration de l'indice de la racine
    int Ind_racine;

    //FONCTION : construction de l'arbre
    Ind_racine = ConstrcArbre(Tab_frequence, Arbre);

    //affiche l'arbre
    printf("\nArbre de Huffman : \n");
    printf("┌───────┬─────────────┬────────────┬──────┬────────────┐\n");
    printf("│ Noeud │ Fils gauche │ Fils droit │ Père │ Frequences │\n");
    printf("├───────┼─────────────┼────────────┼──────┼────────────┤\n");
    AffichageArbre(Arbre, Ind_racine);
    printf("└───────┴─────────────┴────────────┴──────┴────────────┘\n");

    printf("\n \n");



    //FONCTION : création de l'index
    char** Index = CodeBin(Arbre, Ind_racine);

    //affiche l'index
    printf("Code binaire de chaque caractère :\n");
    printf("┌────────────┬──────────────────────────────────┐\n");
    printf("│ Caractères │ Code binaire                     │\n");
    printf("├────────────┼──────────────────────────────────┤\n");


    float Somme = 0;
    int Nb = 0;
    for(int a=0 ; a<256 ; a++)
    {
        if( Index!=NULL && Index[a] != NULL)
        {
            Nb++;
            Somme += strlen(Index[a]);
            printf("│ %-10d │ %-32s │\n", a , Index[a]);
        }
    }
    printf("└────────────┴──────────────────────────────────┘ \n");

    printf("\nLa longueur moyenne des codes est de %f", Somme/Nb );
    printf("\n \n");

    //fonction: écriture du fichier de sortie
    Generation(Index, Entree, Sortie, Ind_racine, Arbre);

    //affiche le ratio de compression
    long int Taille_Entree = CalculeTaille(Entree);
    long int Taille_Sortie = CalculeTaille(Sortie);

    printf("Taille originelle : %ld octets\nTaille compressée : %ld octets\n\nGain : %f %% \n", Taille_Entree, Taille_Sortie, (float)(Taille_Entree-Taille_Sortie)/(float)Taille_Entree*100);

    //destruction des tableaux
    if ( Index!=NULL)
    {
        free(Tab_frequence);
        for(int i=0; i<256 ; i++)
        {
            free(Index[i]);
        }
        free(Index);
    }
}

FILE* OuvertureFichier(char* nom_fichier, char* option)
{
    //ouverture du fichier
    FILE* fichier;
    fichier = fopen( nom_fichier , option );

    if ( fichier==NULL)
    {
      fprintf(stderr, "Le fichier %s est illisible : %s \n", nom_fichier, strerror(errno));
      exit(1);
    }


    return fichier;
}

int main(int argc, char** argv)
{
    //vérifie le nombre d'arguments.
    if(argc!=3)
    {
        fprintf(stderr, "Usage: huf [Fichier source] [Fichier destination]\n" );
        return 1;
    }

    //ouverture des fichiers d'entrée et de sortie

    FILE* entree = OuvertureFichier( argv[1], "r" );
    FILE* sortie = OuvertureFichier( strcat(argv[2],".huf"), "w" );

    //Compression
    Compression(entree, sortie);

    //fermeture des fichiers
    fclose(entree);
    fclose(sortie);

    return 0;
}
