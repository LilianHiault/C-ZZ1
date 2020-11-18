#include <stdio.h>
#include "list.h"

list_t * creerListe(void)
{
  return NULL;
}


void afficherListe(list_t * li)
{
  list_t * c = li;
  printf("[tête] =>");
  while(c != NULL)
    {
      printf(" %d =>", c->value);
      c = c->next;
    }
  printf(" [fin]\n");
}

void insererListe(list_t ** li, int val)
{
  list_t maillon = {val, NULL};
  maillon.next = *li;
  *li = &maillon;
  afficherListe(*li);
}
