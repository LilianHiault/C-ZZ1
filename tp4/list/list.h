#ifndef list_h
#define list_h

typedef struct list
{
  int value;
  struct list * next;
} list_t;

list_t * creerListe(void);
void afficherListe(list_t *);
  
#endif
