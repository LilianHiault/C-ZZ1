#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define N 3

int * tab[N];

int guichet_A;
int guichet_B;
int guichet_C;

void ouvre1()
{
  int r = rand() % N;
  guichet_A = 0;
  guichet_B = 0;
  guichet_C = 0;
  switch(r)
    {
    case 0:
      guichet_A = 1;
      break;
    case 1:
      guichet_B = 1;
      break;
    case 2:
      guichet_C = 1;
    }
}

void ouvre2()
{
  int r = rand() % N;
  int i;
  for(i=0; i<N; i++) *(tab[i]) = 0;
  *(tab[r]) = 1;
}

void initTab()
{
  tab[0] = &guichet_A;
  tab[1] = &guichet_B;
  tab[2] = &guichet_C;
}

int main()
{
  srand(time(NULL));
  initTab();
  ouvre1();
  ouvre2();
  return 0;
}
