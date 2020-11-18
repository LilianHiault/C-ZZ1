#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX_COUPS 22
#define COULEURS 6
#define TAILLE 12

void initialiser(int grille[][TAILLE])
/* Initialise le tableau en 2 dim grille de taille TAILLE
   avec des entiers aléatoires entre 0 et (COULEURS-1) */
{
  int i, j;
  for(i=0; i<TAILLE; i++)
    {
      for(j=0; j<TAILLE; j++)
	{
	  grille[i][j] = rand() % COULEURS;
	}
    }
}

void afficherGrille(int grille[][TAILLE])
/* Affiche la grille de jeu */
{
  int i, j;
  for(i=0; i<TAILLE; i++)
    {
      for(j=0; j<TAILLE; j++)
	{
	  printf("%d ", grille[i][j]);
	}
      printf("\n");
    }
}


int fin(int grille[][TAILLE])
/* Renvoie 1 si la grille est remplie de la même couleur
   Renvoie 0 sinon */
{
  int rempli = 1;
  int i, j;
  int couleur = grille[0][0];
  for(i=0; i<TAILLE; i++)
    {
      for(j=0; j<TAILLE; j++)
	{
	  if(grille[i][j] != couleur)
	    {
	      rempli = 0;
	    }
	}
    }
  return rempli;
}


void remplir(int grille[][TAILLE], int couleur, int nouvCouleur, int i, int j)
/* Propage la nouvelle couleur à ces voisins de même couleur */
{
  if (i < TAILLE && i >= 0 && j < TAILLE && j >= 0)
    {
      if(grille[i][j] == couleur)
	{
	  grille[i][j] = nouvCouleur;
	  remplir(grille, couleur, nouvCouleur, i, j+1);
	  remplir(grille, couleur, nouvCouleur, i, j-1);
	  remplir(grille, couleur, nouvCouleur, i+1, j);
	  remplir(grille, couleur, nouvCouleur, i-1, j);
	}
    }
}


int main()
{
  int grille[TAILLE][TAILLE]; // Grille de couleurs
  int couleur, nouvCouleur;
  int coups = 0;
  int gagne;
  
  srand(time(NULL));

  initialiser(grille);
  couleur = grille[0][0];
  nouvCouleur = couleur;
  remplir(grille, couleur, nouvCouleur, 0, 0);
  afficherGrille(grille);
  gagne = fin(grille);

  printf("Vous devez remplir la grille d'une seule couleur en %d coups !\nEntrez '999' pour quitter.\n", MAX_COUPS);

  do
    {
      printf("\nNombre de coups : %d.\n", coups);
      printf("Entrez une couleur : ");
      scanf("%d", &nouvCouleur);
      remplir(grille, couleur, nouvCouleur, 0, 0);
      couleur = nouvCouleur;
      afficherGrille(grille);
      coups++;
      gagne = fin(grille);
    }
  while (couleur != 999 && coups < MAX_COUPS && !gagne);
  return 0;
}
