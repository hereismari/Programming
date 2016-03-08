#include <stdio.h>
#include <math.h>
int main()
{
int mov,n,cont,i;
cont =0;
scanf("%d",&n);
while(n!= 0)
{
mov = pow(2,n) -1;
cont++;
  printf("Teste %d\n%d\n\n",cont,mov);
scanf("%d",&n);
}
  
return 0;
}

