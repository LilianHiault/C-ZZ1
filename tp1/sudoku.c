#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define N 9

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

void afficher(int grille[][N])
{
  int i, j;
  int racine = sqrt(N);
  for(i=0; i<N; i++)
    {
      if(i % racine == 0)
	{
	  printf("-------------------------\n");
	}
      for(j=0; j<N; j++)
	{
	  if(j % racine == 0)
	    {
	      printf("| ");
	    }
	  printf("%d ", grille[i][j]);
	}
      printf("|\n");
    }
  printf("-------------------------\n");
}

int generer(int grille[][N])
{
  int i, j, k;
  int nonNuls;
  int affiche;

  for(j=0;j<N; ++j) 
    {
      for(i=0; i<N; ++i)
	grille[j][i] = (i + j*3 +j /3) %N +1 ; 
    }

  for(i=0; i<N; i++)
    {
      for(j=0; j<N; j++)
	{
	  affiche = rand() % 2;
	  if (!affiche)
	    {
	      grille[i][j] = 0;
	      nonNuls++;
	    }
	}
    }
  return nonNuls;
}

int main()
{
  int grille [N][N];

  int remplissage = N * N;

  srand(time(NULL));

  printf("SUDOKU !\n");
  
  initialiser(grille);
  remplissage = generer(grille);
  afficher(grille);

  return 0;
}
    
