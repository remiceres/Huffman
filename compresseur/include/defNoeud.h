/**
 * \file
 * \brief Définit la structure Noeud
 *
 */

#ifndef __DEFNOEUD_H__
#define __DEFNOEUD_H__

/**
 *
 * \brief Noeud d'un arbre binaire
 *
 * Noeud est une petite structure comportant les indices de son noeud père
 * et de ses noeuds fils.
 * Lui est également associé la fréquence d'apparation
 * dans un fichier du caractère associé à ce noeud.
 */

typedef struct noeud
{
  unsigned int pere;/*!< Indices du noeud père*/
  unsigned int fg;/*!< Indices du fils gauche */
  unsigned int fd;  /*!< Indices du fils droit */
  double frequences;  /*!< Fréquence d'apparation du caractère lié au noeud */
}Noeud;

#endif
