/**
 * \file
 * \brief Définit la fonction de génération des fréquences
 *
 */

#ifndef __FREQUENCES_H__
#define __FREQUENCES_H__
#include <stdio.h>

/**
 * \fn double* CalculFrequencesCaractere (FILE* fichier)
 * \brief Fonction de calcul de la répartition des fréquences dans un fichier
 *
 * \param fichier Fichier où les fréquences des caractères doivent être calculées
 * \return tab_frequence Un tableau contenant les fréquences des caractères
 * contenus dans le fichier.
 * L'indice d'une case correspond au code ASCII du caractère correspondant
 */
double* CalculFrequencesCaractere(FILE* fichier);

#endif
