#include<stdio.h>

int compter1(char * chaine) 
{   
  int i = 0;

  while (*(chaine+i) != '\0')
     ++i;

  return i; 
}

int compter2(char * chaine) 
{   
  char * s = chaine;

  while (*chaine != '\0')
     ++chaine;

  return chaine - s; 
}

int compter3(char * chaine) 
{   
  char * s = chaine;

  while (*chaine++);

  return chaine - s - 1; 
}

int main()
{
  char * str = ""; // 8
  printf("compter1 : %d, compter2 : %d, compter3 : %d\n", compter1(str), compter2(str), compter3(str));
  return 0;
}
