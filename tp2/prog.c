#include <stdio.h>

int main()
{
   /* int i  , *ptri  = &i; */
   /* char c1 = '1', *ptrc1 = &c1; */
   double d = 4.4;
   double * ptrd = &d;
   char c2 = '2', *ptrc2 = &c2;

   /* printf("ptri = %u ptrc1 = %u \n",ptri, ptrc1); */
   /* printf("ptri = %x ptrc1 = %x \n",ptri, ptrc1); */
   // seule la version suivante ne genere pas d'avertissement
   /* printf("ptri = %p ptrc1 = %p \n",ptri, ptrc1); */
   /* printf("*ptri = %d et *ptrc1=%c \n", *ptri, *ptrc1); */
   
   /* ptri++; */
   /* ptrc1++; */
   
   /* printf("ptri = %u ptrc1 = %d \n",ptri, ptrc1); */
   // cela permet de voir la taille d'un int et d'un char en memoire
   // sizeof(int)  sizeof(char)

   printf("d = %f, ptrd = %p, &ptrd = %p\n", *ptrd, ptrd, &ptrd);
   ptrd += 2;
   printf("d = %f, ptrd = %p, &ptrd = %p\n", *ptrd, ptrd, &ptrd);

   printf("c2 = %c, ptrc2 = %p, &ptrc2 = %p\n", *ptrc2, ptrc2, &ptrc2);

   return 0 ;
}
