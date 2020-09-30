#include<stdio.h>
#include<stdlib.h>

int main()
{
  double * tab;
  int n = 1000000;
  int i;
  tab = (int*)malloc(n * sizeof(*tab));
  for(i=0; i<n; i++)
    {
      tab[i] = i*i;
    }
  free(tab);
  return 0;
}
