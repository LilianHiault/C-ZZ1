#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define N 9 // Taille de la matrice
#define ALEA 2 // Plus ALEA est grand plus la grille sera remplie

int initialiser(int grille[][N])
{
  int i, j;
  for(i=0; i<N; i++)
    {
      for(j=0; j<N; j++)
	{
	  grille[i][j] = 0;
	}
    }
  return 0;
}

void affLigne(int racine)
{
  int i;
  int n =  2 * (N + (racine + 1)) - 1;
  for(i=0; i<n; i++) printf("-");
  printf("\n");
}

void afficher(int grille[][N])
{
  int i, j;
  int racine = sqrt(N);
  for(i=0; i<N; i++)
    {
      if(i % racine == 0)
	{
	  affLigne(racine);
	}
      for(j=0; j<N; j++)
	{
	  if(j % racine == 0)
	    {
	      printf("| ");
	    }
	  if(grille[i][j] == 0)
	    {
	      printf(". ");
	    }
	  else
	    {
	      printf("%d ", grille[i][j]);
	    }
	}
      printf("|\n");
    }
  affLigne(racine);
  printf("\n");
}

int cacher(int grille[][N])
{
  int i, j;
  int remplissage = N * N;
  int affiche;
  for(i=0; i<N; i++)
    {
      for(j=0; j<N; j++)
	{
	  affiche = rand() % ALEA;
	  if (!affiche)
	    {
	      grille[i][j] = 0;
	      remplissage--;
	    }
	}
    }
  return remplissage;
}
  

int generer(int grille[][N])
{
  int i, j;
  int remplissage;

  for(j=0;j<N; ++j) 
    {
      for(i=0; i<N; ++i)
	grille[j][i] = (i + j*3 +j /3) %N +1 ; 
    }
  remplissage = cacher(grille);  
  return remplissage;
}

void saisir(int grille[][N])
{
  int i, j, v;
  int valide;
  
  printf("Entrez les indices i, j et la valeur v à placer.\n");
  do
    {
      valide = 0;
      printf("Ligne : ");
      scanf("%d", &i);
      printf("Colonne: ");
      scanf("%d", &j);
      printf("Valeur : ");
      scanf("%d", &v);
      
      if((i > 0) && (i <= N) && (j > 0) && (j <= N))
	{
	  if((v > 0) && (v <= N) && grille[i-1][j-1] == 0)
	    {
	      valide = 1;
	      grille[i-1][j-1] = v;
	      printf("[%d][%d] = %d\n", i, j, v);
	    }
	  else
	    {
	      printf("%d : valeur non valide ou case déjà remplie.\n", v);
	    }
	}
      else
	{
	  printf("%d, %d : les coordonées sont en dehors du tableau.\n", i, j);
	}
    }
  while (!valide);
}

int verifierLigneColonne(int num, char sens[], int grille[][N])
{
  int erreur = 0;
  int ligneColonne[N];
  int i = 0;
  int val = 0;
  for(i=0; i<N; i++) ligneColonne[i] = 0;
  if(strcmp(sens, "HORIZ") == 0)
    {
      // Horizontal
      while(i<N && erreur == 0)
	{
	  val = grille[num][i];
	  ligneColonne[val] ++;
	  if(ligneColonne[val] != 1)
	    {
	      erreur = 1;
	    }
	  i++;
	}
    }
  else if(strcmp(sens, "VERT") == 0)
    {
      // Vertical
      while(i<N && erreur == 0)
	{
	val = grille[i][num];
	  ligneColonne[val] ++;
	  if(ligneColonne[val] != 1)
	    {
	      erreur = 1;
	    }
	  i++;
	}
    }
  else
    {
      erreur = 1;
    }
  return erreur;
}

int verifierRegion(int k, int l, int grille[][N])
{
  return 0;
}

int verifierGrille(int grille[][N])
{
  return 0;
}

int main()
{
  int grille [N][N];

  int rempli = N * N;
  int remplissage;

  srand(time(NULL));

  printf("SUDOKU\n");
  
  initialiser(grille);
  remplissage = generer(grille);
  afficher(grille);
  while (remplissage < rempli)
    {
      saisir(grille);
      remplissage++;
      printf("Remplissage : %d\n", remplissage);
      printf("%d\n", verifierLigneColonne(1, "HORIZ", grille));
      afficher(grille);
    }
  // Vérif victoire
  return 0;
}
    
