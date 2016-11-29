#include "generation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void encodage(char** index, FILE* entre, FILE* sortie)
{
  //remer le cursseur de lecture au début du fichier
  rewind(entre);

  //crée un buffer
  char buffer[262];
  for (int i=0 ; i<262 ; i++)
  {
    buffer[i]='\0';
  }

  unsigned int caractereLecture = '\0';


  //boucle comte le nombre de caractere dans le fichier + incrémente dans le tableau le carractére trouvé.
  if (entre != NULL)
  {
    int somme = 0;


    while( ( (char)(caractereLecture = fgetc(entre)) ) != EOF )
    {
      strcat(buffer, index[(size_t)caractereLecture] );


      if ( buffer[8] != '\0' )
      {
        for (int i = 0 ; i<8 ; i++)
        {
          if (buffer[7-i] == '1')
          {
            printf("%f +", pow(2,i));
            somme += pow(2,i);
          }
        }

        fputc((char)somme, sortie);
        somme = 0;
        buffer[0] = '\0';
      }
    }
  }
  else
  {
    fprintf(stderr, "Le fichier est illisible \n");
    exit(1);
  }

  fclose(entre);

}
