#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct cellule 
{
  char ligne[255];
  struct cellule * suiv;
} cellule_t;

typedef struct liste 
{
  cellule_t * tete;
  cellule_t * fin;
} liste_t;



void afficher(liste_t li)
{
  cellule_t * cour = li.tete;
  printf("=> Début\n");
  while(cour != NULL)
    {
      printf("%s\n", cour->ligne);
      cour = cour->suiv;
    }
  printf("=> Fin\n");
}      


void inser_debut(liste_t * li, char chaine[255])
{
  cellule_t * element = (cellule_t*)malloc(sizeof(cellule_t));
  if (element != NULL)
    {
      // Remplir les champs de l'élément
      strcpy(element->ligne, chaine);
      element->suiv = li->tete;
      
      // Insertion
      li->tete = element;
      if (li->fin == NULL)
	{
	  li->fin = element;
	}
    }
  /* afficher(*li); */
}
  

void inser_fin(liste_t * li, char chaine[255])
{
  cellule_t * element = (cellule_t*)malloc(sizeof(cellule_t));
  /* cellule_t * dernier; */
  if (element != NULL)
    {
      // Remplit les champs de l'élément
      strcpy(element->ligne, chaine);
      element->suiv = NULL;

      // Insertion
      if (li->tete == NULL)
	{
	  li->tete = element;
	}
      else
	{
	  li->fin->suiv = element;
	}
      li->fin = element;
    }
}

void liberer(liste_t * li)
{
  cellule_t * cour = li->tete;
  cellule_t * lib = cour;
  if(li->tete != NULL)
    {
      while(cour != NULL)
	{
	  lib = cour;
	  cour = cour->suiv;
	  free(lib);
	}
      li->tete = NULL;
      li->fin = NULL;
    }
}      
  

int main(int argc, char * argv[])
{
  char chaine[255] = "Hello world!";
  liste_t li = {NULL, NULL};

  if (argc > 1)
    {
      FILE * fichier = fopen(argv[1], "r"); // Ouverture du fichier
      if (fichier)
	{
	  while (!feof(fichier))
	    {
	      fgets(chaine, 255, fichier);
	      if(chaine[0] == '#')
		{
		  inser_fin(&li, chaine);
		}
	    }
	  fclose(fichier);
	}
    }
  else perror("Le fichier ne peut pas être lu");
  
  /* while (!feof(stdin)) */
  /*   { */
  /*     printf("Entrez une phrase (C-d pour quitter) :\n"); */
  /*     fgets(chaine, 255, stdin); */
  /*     if (!feof(stdin)) inser_fin(&li, chaine); */
  /*     /\* printf("%s\n", chaine); *\/ */
  /*   } */

  afficher(li);
  liberer(&li);
  return 0;
}
