#include "../include/generation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int DecoderBuffer(char* Buffer, int Quantite_utilise) {
    int Res_Conver = 0;
    int Nb_decode = Quantite_utilise > 8 ? 8 : Quantite_utilise; //taite le cas de fin du fichier

    for (int i = 0 ; i < Nb_decode ; i++)
    {
        if ( Buffer[i] == '1' )
        {
            Res_Conver += 1;
        }

        if ( i < Nb_decode - 1 ) //e décale dans tous les cas sauf si il est sur le dernier bits
        {
            Res_Conver <<= 1;
        }
    }

    Res_Conver <<= 8 - Nb_decode;//décale du nombre de bits manquant
    return Res_Conver;
}

void DecalerBuffer(char* Buffer, int Quantite_utilise)
{
    for (int i = 8; i <= Quantite_utilise; i++)
    {
        Buffer[i - 8] = Buffer[i];
    }
}

void EcritureArbre(Noeud* Arbre, int Ind_racine, FILE* Sortie)
{
    if (Arbre[Ind_racine].fg == -1)
    {
        // Je suis une feuille
        fputc(0,Sortie);
        fputc(Ind_racine,Sortie);
    }
    else
    {
        // Je suis un noeud
        fputc(1,Sortie);
        EcritureArbre(Arbre, Arbre[Ind_racine].fg, Sortie);
        EcritureArbre(Arbre, Arbre[Ind_racine].fd, Sortie);
    }
}

void Generation(char** Index, FILE* Entree, FILE* Sortie, int Ind_racine, Noeud* Arbre)
{
    //remet le cursseur de lecture au début du fichier
    rewind(Entree);

    //crée un buffer et initialisation a 0
    char Buffer[262] = "";

    unsigned int Caractere_lecture = '\0';

    //écriture des octect magiques
    fputc('a',Sortie);
    fputc('b',Sortie);
    fputc(20,Sortie);//ecrit le caractére numéro 20

    //reserve place pour conter les 0 inutile de fremin
    fputc('\0', Sortie);



    //eccriture de l'arbre
    if (Ind_racine != -1) //exlu le cas ou l'arbre est vide;
    {
        EcritureArbre(Arbre, Ind_racine, Sortie);
    }


    //boucle comte le nombre de caractere dans le fichier + incrémente dans le tableau le carractére trouvé.
    int Quantite_utilise = 0;

    while( (Caractere_lecture = fgetc(Entree) ) != EOF )
    {
        strcat(Buffer, Index[(size_t)Caractere_lecture] );
        Quantite_utilise += strlen(Index[(size_t) Caractere_lecture]);

        while ( Quantite_utilise >= 8 )
        {
            int Octet = DecoderBuffer(Buffer, Quantite_utilise);
            fputc(Octet, Sortie);
            DecalerBuffer(Buffer, Quantite_utilise);
            Quantite_utilise -= 8;
        }
    }

    if ( Quantite_utilise > 0 )
    {
        int Octet_final = DecoderBuffer(Buffer, Quantite_utilise);
        fputc(Octet_final, Sortie);
    }
    else
    {
        Quantite_utilise = 8;
    }

    //eccriture du nombre de 0 utile sur le dernier octect
    fseek(Sortie, 3 , SEEK_SET);
    fputc( Quantite_utilise, Sortie);
}
