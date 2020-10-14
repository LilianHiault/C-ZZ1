#include "vecteur.h"
#include<stdlib.h>

// definition des fonctions declarees dans vecteur.h

typedef float * VecteurType;

void vecteurToFile(FILE * fichier, VecteurType vecteur, int ordre)
{
  int i = 0;
  if(fichier)
    {
      fprintf(fichier, "[ ");
      for(i=0; i<ordre; i++)
	{
	  fprintf(fichier, "%.3f ", vecteur[i]);
	}
      fprintf(fichier, "]");
    }
  else
    {
      fprintf(stderr, "Erreur de lecture du fichier.\n");
    }
}


float * vecteurFromFileByName(const char * nom, int * p_ordre)
{
  int i = 0;
  float valeur = 0;
  int nbRead = 0;
  /* char buffer[BUFSIZ]; */
  
  float * retour = NULL;
  
  FILE * fichier = NULL;
  fichier = fopen(nom, "r");
  if (fichier)
    {
      printf("%s opened\n", nom);
      fscanf(fichier, "%d", p_ordre);
      retour = (VecteurType)malloc(*p_ordre * sizeof(float)); // Vecteur à retourner
      printf("%d\n", *p_ordre);
      
      // 1ère version
      /* for(i =0; i<*p_ordre; i++) */
      /* 	{ */
      /* 	  fscanf(fichier, "%f", &valeur); */
      /* 	  retour[i] = valeur; */
      /* 	  printf("retour[%d] = %f\n", i, valeur); */
      /* 	} */

      // 2ème version : ne fonctionne pas du tout
      /* while(!feof(fichier)) */
      /* 	{ */
      /* 	  fgets(buffer, BUFSIZ, fichier); */
      /* 	  printf("buffer : %s\n", buffer); */
      /* 	  for(i =0; i<*p_ordre; i++) */
      /* 	    { */
      /* 	      sscanf(buffer, "%f", &valeur); */
      /* 	      retour[i] = valeur; */
      /* 	      printf("retour[%d] = %f\n", i, valeur); */
      /* 	    } */
      /* 	  i++; */
      /* 	} */

      // 3ème version
      while(i<*p_ordre)
	{
	  nbRead = fscanf(fichier, "%f", &valeur);
      	  retour[i] = valeur;
      	  printf("nbRead : %d, retour[%d] = %f\n", nbRead, i, valeur);
	  i++;
	}
      fclose(fichier);
      printf("terminé\n");
    }
  else
    {
      fprintf(stderr, "Erreur de lecture du fichier %s.\n", nom);
    }

  // Attention si vecteur non complet -> retourner NULL
      
  return retour;
}


/*
  float   produitScalaire() 
  {
  float retour;

  return retour;
  } 
*/
