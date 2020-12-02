#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>


#define MAX_COUPS 22
#define COULEURS 6
#define TAILLE 12


/* --- FONCTIONS --- */

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


/* FONCTIONS SDL */
void afficherEcran(SDL_Renderer * renderer)
{
}


int main()
{
  /* --- VARIABLES --- */
  int grille[TAILLE][TAILLE]; // Grille de couleurs
  int couleur, nouvCouleur;
  int coups = 0;
  int gagne;
  int running = 1;

  
  /* --- VARIABLES SDL --- */
  SDL_Window * window;
  SDL_Renderer * renderer;
  SDL_Event event;
  
  int width = 1280;
  int height = 720;
  int flags=IMG_INIT_JPG|IMG_INIT_PNG;
  int initted= 0;
  
  
  /* --- INITIALISATION SDL --- */

  // Initialisations graphiques
  if ((SDL_INIT_VIDEO) == -1)
    {
      fprintf(stderr, "Erreur d'initialisation des la SDL : %s\n", SDL_GetError());
      return EXIT_FAILURE;
    }

  // Fenêtre
  window = SDL_CreateWindow("Flood it!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_RESIZABLE);
  if (window == 0)
    {
      fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
      // Fermer la fenêtre
      SDL_DestroyWindow(window);
      // Quitter SDL
      SDL_Quit();
      return  EXIT_FAILURE;
    }

  // "Moteur graphique"
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); /* SDL_RENDEERER_SOFTWARE */
  if (renderer == 0)
    {
      fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
      // Fermer la fenêtre
      SDL_DestroyWindow(window);
      // Quitter SDL
      SDL_Quit();
      return EXIT_FAILURE;
    }

  initted = IMG_Init(flags);

  if((initted&flags) != flags) 
    {
      printf("IMG_Init: Impossible d'initialiser le support des formats JPG et PNG requis!\n");
      printf("IMG_Init: %s\n", IMG_GetError());
    }

  /* Initialisation texte */
  if (TTF_Init() != 0)
    {
      fprintf(stderr, "Erreur d'initialisation TTF : %s\n", TTF_GetError());
    }
  

  /* --- INITIALISATION FLOOD-IT --- */
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
      /* --- BOUCLE D'ÉVENEMENTS SDL --- */
       while(SDL_PollEvent(&event))
	{
	  switch(event.type)
	    {
	    case SDL_WINDOWEVENT:
	      /* printf("Window event\n"); */
	      switch (event.window.event)
		{
		case SDL_WINDOWEVENT_CLOSE:
		  printf("Appui de la croix\n");
		  break;
		case SDL_WINDOWEVENT_SIZE_CHANGED:
		  width = event.window.data1;
		  height = event.window.data2;
		  printf("Size : %d %d\n", width, height);
		  break;
		default:
		  afficherEcran(renderer);
		}
	      break;
	    case SDL_MOUSEBUTTONDOWN:
	      printf("Appui : %d %d\n", event.button.x, event.button.y);
	      break;
	    case SDL_QUIT:
	      printf("Quitter\n");
	      running = 0;
	    }
	}

      /* BOUCLE D'ÉVENEMENTS TERMINAL --- */
      printf("\nNombre de coups : %d.\n", coups);
      printf("Entrez une couleur : ");
      scanf("%d", &nouvCouleur);
      remplir(grille, couleur, nouvCouleur, 0, 0);
      couleur = nouvCouleur;
      afficherGrille(grille);
      coups++;
      gagne = fin(grille);
      if(couleur == 999) running = 0;
    }
  while (running && coups < MAX_COUPS && !gagne);


  /* --- QUITTER SDL --- */
  SDL_DestroyWindow(window);
  IMG_Quit();
  TTF_Quit();
  SDL_Quit();
  return 0;
}
