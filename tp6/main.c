#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <stdio.h>


void afficherEcran(SDL_Renderer * renderer, SDL_Surface * image, TTF_Font * font1)
{
  SDL_Rect rect;
  SDL_Texture * avatar;
  
  /* Couleur de fond */
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
  SDL_RenderClear(renderer);

  /* Dessiner en blanc */
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
  rect.x = rect.y = 0;
  rect.w = rect.h = 600;
  SDL_RenderFillRect(renderer, &rect);

  avatar = SDL_CreateTextureFromSurface(renderer, image);

  rect.x = 600;
  rect.y = 110;
  rect.w = rect.h = 128;
  SDL_RenderCopy(renderer, avatar, NULL, &rect);
  /* L'image a ete copiee dans le renderer qui sera plus tard affiche a l'ecran */

  int iW = 0;
  int iH = 0;
  SDL_Color     couleur  = {0, 0, 255, 255};        
  SDL_Surface * surf     = TTF_RenderText_Blended(font1, "Hello world !", couleur);
  SDL_Texture * texttext = SDL_CreateTextureFromSurface(renderer, surf);
  SDL_QueryTexture(texttext, NULL, NULL, &iW, &iH);
  SDL_RenderCopy(renderer, texttext, NULL, &rect);

  
  /* Afficher à l'écran */
  SDL_RenderPresent(renderer);
}


int main()
{
  /* --- VARIABLES --- */
  
  SDL_Window * window;
  SDL_Renderer * renderer;
  SDL_Event event;
  int flags=IMG_INIT_JPG|IMG_INIT_PNG;
  int initted= 0;

  
  int width = 1280;
  int height = 720;
  int running = 1;



  /* --- INITIALISATION SDL */
  
  // Initialisations graphiques
  if ((SDL_INIT_VIDEO) == -1)
    {
      fprintf(stderr, "Erreur d'initialisation des la SDL : %s\n", SDL_GetError());
      return EXIT_FAILURE;
    }

  // Fenêtre
  window = SDL_CreateWindow("Hello world !", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_RESIZABLE);
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

  TTF_Font * font1;
  font1 = TTF_OpenFont("/usr/share/fonts/opentype/firacode/FiraCode-Light.otf", 72);
  if (font1 == 0)
    {
      fprintf(stderr, "Erreur d'initialisation font : %s\n", TTF_GetError());
    }
  




  
  /* --- DESSINER ! --- */
  
  // Images
  SDL_Surface * image = NULL;
  image = IMG_Load("red.png");
  //  image = SDL_LOADBMP("coucou.bmp"); // Fonction standard de la SDL 2
  if(!image)
    {
      printf("IMG_Load: %s\n", IMG_GetError());
    }

  
  // Boucle d'évenement
  while (running)
    {
      while(SDL_PollEvent(&event))
	{
	  switch(event.type)
	    {
	    case SDL_WINDOWEVENT:
	      printf("Window event\n");
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
		  afficherEcran(renderer, image, font1);
		}
	      break;
	    case SDL_MOUSEBUTTONDOWN:
	      printf("Appui : %d %d\n", event.button.x, event.button.y);
	      break;
	    case SDL_QUIT:
	      printf("On quitte\n");
	      running = 0;
	    }
	}
    }
  
  
  // Temps d'attente
  SDL_Delay(1);


  /* --- QUITTER --- */
  
  // Fermer la fenêtre
  SDL_FreeSurface(image);
  SDL_DestroyWindow(window);
  
  // Quitter SDL
  IMG_Quit();
  TTF_Quit();
  SDL_Quit();
  return 0;
}
