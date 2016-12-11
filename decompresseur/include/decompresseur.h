#ifndef __DECOMPRESSEUR_H__
#define __DECOMPRESSEUR_H__

#define ERR_FORMAT 1

#include <stdio.h>

#include "../include/defNoeud.h"

int decompresseur(FILE* input_compress, FILE* output_compress);

#endif
