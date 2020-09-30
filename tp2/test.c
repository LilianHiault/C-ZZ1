#include<string.h>
#include<stdio.h>
#include<stdlib.h>

void saisir(char * s) 
{
  printf("Saisir une chaine\n");
  scanf("%s", s);
}

int main() 
{
  char *s = (char *)malloc(100 * sizeof(*s));

  printf("Entrer votre prenom. ");
  saisir(s);
  printf("Bonjour %s!\n", s);

  if (strcmp(s,"ddd") == 0) printf("bizarre \n");

  free(s);
  
  return 0;
}
