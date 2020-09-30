#include<stdio.h>

int main()
{
  int tab[] = {0,1,2,3,4,5};

  int  * p1;
  char * p2;

  printf("%lu %lu %lu\n", sizeof(char), sizeof(int), sizeof(double));

  p1 = tab; 
  ++p1;
  printf("%d\n", *p1); // 1

  p2 = (char *) p1;
  p2 += sizeof(int); // +4

  printf("%d\n", *((int*)p2)); //
  /* printf("%d\n", *(p1+6)); //  */

  /* p1 = NULL; */
  /* printf("%d", *p1); */

  return 0;
}
