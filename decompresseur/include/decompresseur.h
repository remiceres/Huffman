#ifndef __DECOMPRESSEUR_H__
#define __DECOMPRESSEUR_H__

#define ERR_FORMAT 1

#include <stdio.h>

#include "../include/defNoeud.h"

int Decompression(FILE* Entree, FILE* Sortie);

#endif
