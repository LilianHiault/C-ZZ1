#ifndef list_h
#define list_h

typedef struct list
{
  int value;
  struct list * next;
} list_t;

/* La tête de la liste contient l'adresse vers le premier élément de la liste.
   Si la liste est vide la tête contient la valeur NULL. */

list_t * creerListe(void);
void afficherListe(list_t *);
void insererListe(list_t **, int);

#endif
