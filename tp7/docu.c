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
      strcpy(element->ligne, chaine);
      element->suiv = li->tete;
      
      li->tete = element;
      if (li->fin == NULL)
	{
	  li->fin = element;
	}
    }
  /* afficher(*li); */
}
  

void ajout_fin(liste_t * li, char chaine[255])
{
  cellule_t * element = (cellule_t*)malloc(sizeof(cellule_t));
  if (element != NULL)
    {
      // Fin de la liste
      strcpy(element->ligne, chaine); // Remplit les champs de élément      
      element->suiv = NULL;

      li->fin->suiv = element;
      li->fin = element;
      if (li->tete == NULL)
	{
	  li->tete = element;
	}
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
  

int main()
{
  char chaine[255] = "Hello world!";
  liste_t li = {NULL, NULL};

  /* afficher(li); */
  /* inser_debut(&li, chaine); */
  /* strcpy(chaine, "Coucou"); */
  /* inser_debut(&li, chaine); */
  /* strcpy(chaine, "Fini"); */
  /* ajout_fin(&li, chaine); */
  /* afficher(li); */

  while (!feof(stdin))
    {
      printf("Entrez une phrase (C-d pour quitter) :\n");
      fgets(chaine, 255, stdin);
      printf("%s\n", chaine);
    }

  liberer(&li);
  afficher(li);
  return 0;
}
