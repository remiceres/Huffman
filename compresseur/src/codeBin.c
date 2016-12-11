#include "../include/codeBin.h"
#include "../include/defNoeud.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//ajout 1 ou 0 a la fin de la chaine
char* nouvelleChaine(int Long_ancienne_chaine, char* Ancienne_chaine, char Vall_ajout)
{

    //déclaration de la nouvelle chaine
    char* Nouvelle_chaine = (char*) malloc((Long_ancienne_chaine+1)*sizeof(char));

    //copie des ancienne valeurs de la chaine
    strcpy(Nouvelle_chaine, Ancienne_chaine);
    // ajout de la nouvelle valeurs
    Nouvelle_chaine[Long_ancienne_chaine-1] = Vall_ajout;
    Nouvelle_chaine[Long_ancienne_chaine] = '\0';

    return Nouvelle_chaine;
}


// fonction crée les codes binaires
void InitIndex(char** Index, Noeud* Arbre, int Actuel, char* Chaine, int Long_chaine)
{

    if(Arbre[Actuel].fg==-1)//si el est sur une feille
    {
        Index[(size_t) Actuel] = Chaine;

    }
    else//si il es sur un noeud
    {
        InitIndex(Index, Arbre, Arbre[Actuel].fg, nouvelleChaine(Long_chaine, Chaine, '0'), Long_chaine+1 );
        InitIndex(Index, Arbre, Arbre[Actuel].fd, nouvelleChaine(Long_chaine, Chaine, '1'), Long_chaine+1 );

        //libération de l'ancienne chaine
        free(Chaine);
    }

}


char** CodeBin(Noeud* Arbre, int Ind_racine)
{
    //déclaration et initialisation du tableau des codes binaire de chaque caracteres
    char** Index = (char**) malloc( sizeof(char*) * 256 );
    for(int i=0; i<256 ; i++)
    {
        Index[i]=NULL;
    }

    //déclaration et initialisation d'un chaine de carracteres
    char* Chaine_vide = (char*)malloc(sizeof(char)) ;
    Chaine_vide[0]='\0';

    //construction de tableau de chaine de caractere
    if (Ind_racine != -1)
    {
        InitIndex(Index, Arbre, Ind_racine, Chaine_vide, 1);

    }
    else //cas ou l'arbre est vide
    {
        return NULL;
    }

    return Index;
}
