/**
 * \file
 * \brief Déclaration de la fonction qui va générer les codes binaires
 *
 */
#ifndef __CODEBIN_H__
#define __CODEBIN_H__
#include "defNoeud.h"

/**
 * \fn char** CodeBin(Noeud* arbre,int racine)
 * \brief Génère les codes binaires
 *
 * Ces codes binaires sont associés à chaque caractère présent
 * dans le fichier d'origine.
 *
 * \param arbre Arbre
 * \param racine Indice de la racine de l'Arbre
 * \return Index Tableau associant les codes binaires aux différents caractères
 */
char** CodeBin(Noeud*, int);

#endif
