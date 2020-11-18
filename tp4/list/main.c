#include <stdio.h>
#include "list.h"  

int main()
{
  int answer = 0;
  int val = 0;
  list_t * li = creerListe();
  /* list_t maillon = {1, NULL}; */
  /* afficherListe(li); */
  /* li = &maillon; */
  /* insererListe(&li, &maillon); */
  afficherListe(li);
  while(answer != 3)
    {
      printf("Que voulez vous faire ?\n1 - Afficher la liste\n2 - Insérer un nouvel élément\n3 - Quitter\n4 - Éditer un élément\n5 - Lire à partir d'un fichier texte\n");
      scanf("%d", &answer);
      printf("\n");
      switch (answer)
	{
	case 1:
	  printf("Affichage de la liste :\n");
	  afficherListe(li);
	  break;
	case 2:
	  printf("Insérer le nombre :\n");
	  scanf("%d", &val);
	  printf("Val = %d\n", val);
	  insererListe(&li, val);
	  break;
	case 3:
	  printf("Quitter\n");
	  break;
	case 4:
	  printf("Éditer l'élément à la position :\n");
	  break;
	case 5:
	  printf("Lire à partir du fichier :\n");
	  break;
	default:
	  printf("Entrée non valide\n");
	}
    }
  return 0;
}
