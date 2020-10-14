#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hall_of_fame.h"

// Affiche dans un fichier les champs de d
void afficherDonnee(FILE * file, donnee_t d) {
  fprintf(file, "%s : %s avec %d\n", d.nom, d.alias, d.score);
}

// Écrit dans la structure pointée par p le contenu du fichier
void saisirDonnee(FILE *file, donnee_t * p){
  char buffer[BUFSIZ];
  fgets(buffer, BUFSIZ, file);
  sscanf(buffer, "%s", p->nom);

  fgets(buffer, BUFSIZ, file);
  sscanf(buffer, "%s", p->alias);

  fgets(buffer, BUFSIZ, file);
  sscanf(buffer, "%d", &(p->score));
}

// Permet de lire les données à partir d'un fichier texte et retourne la taille du tableau
int tableauFromFilename(const char * fileName, donnee_t * tableau)
{
  int i = 0;
  int taille = 0;
  FILE * fichier = NULL;
  fichier = fopen(fileName, "r");
  if (fichier)
    {
      while(!feof(fichier))
	{
	  saisirDonnee(fichier, &tableau[i]);
	  i++;
	}
      taille = i;
      printf("Affiche strctures :\n");
      for(i=0; i<taille; i++)
	{
	  afficherDonnee(stdout, tableau[i]);
	}
      fclose(fichier);
    }
  else
    {
      fprintf(stderr, "Erreur de lecture du fichier %s.\n", fileName);
    }
  printf("Taille : %d\n", taille);
  return taille;
}
