#ifndef hall_of_fame_h
#define hall_of_fame_h

/* DECLARATION DES TYPES PERSONNELS */
// et de leur typedef si besoin
typedef struct donnee
{
  int score;
  char jeu[100];
  char alias[40];
} donnee_t;


/* DECLARATIONS DES METHODES */
void afficherDonnee(FILE *, donnee_t);
void saisirDonnee (FILE * , donnee_t *);
// mettre ici les autres declarations

#endif
