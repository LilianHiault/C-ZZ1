#include<stdio.h>

void echangeParValeur(int a, int b)
{
  int c = a;
  a = b;
  b = c;
}

void echangeParAdresse(int * pa, int *pb)
{
  int c = *pa;
  *pa = *pb;
  *pb = c;
}
  

int main()
{
  int a = 4;
  int b = 0;
  printf("Échange %d, %d\n", a, b);
  /* echangeParValeur(a, b); */
  echangeParAdresse(&a, &b);
  printf("%d, %d\n", a, b);
  return 0;
}
