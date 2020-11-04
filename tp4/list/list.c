#include <stdio.h>
#include "list.h"

list_t * creerListe(void)
{
  return NULL;
}


void afficherListe(list_t * li)
{
  if (li != NULL)
    {
      list_t * c = li;
      while(c->next != NULL)
	{
	  printf("%d\n", c->value);
	}
    }
  else
    {
      printf("La liste est vide !\n");
    }
}
