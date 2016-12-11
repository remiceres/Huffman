/**
 * \file
 * \biref Déclaration de la fonction de décompression
 *
 */
#ifndef __DECOMPRESSEUR_H__
#define __DECOMPRESSEUR_H__

/**
 * \brief Définit ERR_FORMAT = 1
 */
#define ERR_FORMAT 1

#include <stdio.h>

#include "../include/defNoeud.h"

/**
 * \brief Fonction permettant de décompresser un fichier
 *
 * \param Entree Fichier compressé d'entrée
 * \param Sortie Fichier de sortie décompressé
 * \return Retourne ERR_FORMAT si ce n'est pas un fichier qui peut être décompressé,
 * retourne 0 sinon
 */
int Decompression(FILE* Entree, FILE* Sortie);

#endif
