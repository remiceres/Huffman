/**
 * \file
 * \brief Déclaration de la fonction de génération du fichier compressé
 *
 */
#ifndef __GENERATION_H__
#define __GENERATION_H__
#include <stdio.h>
#include "defNoeud.h"

/**
 * \fn void Generation(char** index, FILE* entre, FILE* sortie, int racine,  Noeud* arbre)
 * \brief Ecrit dans le fichier "compressé" les codes binaires des caractères
 *
 * \param index Tableau de codes binaires associés aux différents caractères
 * \param entre Fichier d'entrée
 * \param sorti Fichier de sortie (fichier comrpessé)
 * \param racine Indice de la racine de l'arbre
 * \param arbre Arbre
 */
void Generation(char** index, FILE* entre, FILE* sortie, int racine,  Noeud* arbre);

#endif
