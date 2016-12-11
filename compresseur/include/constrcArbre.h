/**
* \file
* \brief Déclaration de la fonction qui va construire l'arbre
*
*/
#ifndef __CONSTRCARBRE_H__
#define __CONSTRCARBRE_H__
#include "defNoeud.h"

/**
 * \fn int ConstrcArbre (double* tab_frequence,Noeud* arbre)
 * \brief Construction de l'arbre
 *
 * \param tab_frequence Tableau des fréquences de répartition des caractères
 * \param arbre Arbre préalablement initialisé
 * \return Ind_racine Indicide de la racine de l'arbre
 */
int ConstrcArbre(double*,Noeud*);


#endif
