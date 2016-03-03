#include <stdio.h>
#include <string.h>
int main()
{
    char c;
int k,i,n,x,t,controle;
scanf("%d",&n);

k=1;

while(n!=0)
{
t=0;
controle=1;
for(i=1;i<=n*2-1;i++)
{
   if (i%2==0)
   {
       scanf("%c",&c);
       if (c=='+')
        controle=1;
       else
        controle=0;
   }
   else
   {
       scanf("%d",&x);
       if (controle)
        t+=x;
       else t-=x;

   }

}
printf("Teste %d\n%d\n",k,t);
k++;
scanf("%d",&n);
}

return 0;
}
