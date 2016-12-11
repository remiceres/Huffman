#include "../include/decompresseur.h"
#include <stdlib.h>


int verifOctetsMagiques(FILE* Entree)
{
    return fgetc(Entree)=='a' && fgetc(Entree)=='b' && fgetc(Entree)==20;
}

int reconstructionArbreRecursion(FILE* Entree, Noeud* Arbre, int* Prochain_indice)
{
    if( fgetc(Entree)==0 ) // je suis sur une feulles
    {
        return fgetc(Entree);
    }
    else //je suis sur un noeud
    {
        int Position = *Prochain_indice;
        (*Prochain_indice)++;

        Arbre[Position].fg=reconstructionArbreRecursion(Entree, Arbre, Prochain_indice);
        Arbre[Position].fd=reconstructionArbreRecursion(Entree, Arbre, Prochain_indice);

        return Position;
    }
}

Noeud* ReconstructionArbre(FILE* Entree)
{
    //déclaration et initialisation de l'arbre
    Noeud* Arbre = malloc(511 * sizeof(Noeud));
    //initialisation de pere, fg, fd et frequences
    for(int i=0 ; i<511 ; i++)
    {
        Arbre[i].pere=-1;
        Arbre[i].fg=-1;
        Arbre[i].fd=-1;
        Arbre[i].frequences=0;
    }

    //FONCTION : recursive qui met les valeurs dans l'arbre
    int Prochain_indice = 256;
    reconstructionArbreRecursion(Entree, Arbre, &Prochain_indice);

    return Arbre;
}
int VerifDernierOctet(FILE* Entree)
{
    if ( (getc(Entree))!= EOF ) //si le prochain octect est la fin du fichier
    {
        fseek(Entree,-1, SEEK_CUR);//retour du cursseur a la position d'origine
        return 0;
    }
    fseek(Entree,-1, SEEK_CUR);
    return 1;
}

void DecodageCaracteres(FILE* Entree, FILE* Sortie, Noeud* Arbre, int Quantite_utilise )
{
    int Indice = 256;

    int Octet_actuel;
    int Decalage = 0;
    int Fin;
    do
    {
        Octet_actuel=fgetc(Entree);

        Fin = VerifDernierOctet(Entree);
        if (Fin)
        {
            Decalage = 8 - Quantite_utilise ;
        }

        for(int Bit_actuel = 7 ; Bit_actuel >= Decalage ; Bit_actuel--)
        {

            if ( (Octet_actuel >> Bit_actuel) % 2 ) //si lie un 0
            {
                if ( Arbre[Arbre[Indice].fd].fd == -1 )
                {
                    fputc(Arbre[Indice].fd, Sortie);
                    Indice=256;
                }
                else
                {
                    Indice = Arbre[Indice].fd;
                }
            }
            else //si lie un 1
            {
                if ( Arbre[Arbre[Indice].fg].fg == -1 ) ///A A A A A EXTRAIIIIRE
                {
                    fputc(Arbre[Indice].fg, Sortie);
                    Indice=256;
                }
                else
                {
                    Indice = Arbre[Indice].fg;
                }
            }
        }
    }while ( !Fin );

}


int Decompression(FILE* Entree, FILE* Sortie)
{

    printf("Décomprétion\n");

    //FONCTION : verifie la présences des octect magique
    if ( !verifOctetsMagiques( Entree ) )
    {
        return ERR_FORMAT;
    }

    //définition et récupération du nombre de 0 inutile a la fin du fichier
    int Quantite_utilise = fgetc(Entree);

    if (!VerifDernierOctet(Entree))
    {
        //FONCTION reconstruction de l'arbre
        Noeud* Arbre = ReconstructionArbre(Entree);

        //FONCTION écriture des carracteres
        DecodageCaracteres(Entree, Sortie, Arbre, Quantite_utilise);

        //destruction de larbre
        free(Arbre);
    }

    return 0;
}


//TODO : VALGRIND
