#include <stdio.h>
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
  while(cour != NULL)
    {
      printf("%s\n", cour->ligne);
      cour = cour->suiv;
    }
}      


void inser_debut(liste_t * li, char chaine[255])
{
  cellule_t element;
  strcpy(element.ligne, chaine);
  element.suiv = li->tete;
  li->tete = &element;
  if (li->fin == NULL)
    {
      li->fin = &element;
    }
  /* afficher(*li); */
}
  

void ajout_fin(liste_t li);

int main()
{
  char chaine[255] = "Hello world!";
  liste_t li = {NULL, NULL};
  /* afficher(li); */
  inser_debut(&li, chaine);
  afficher(li);
  return 0;
}
