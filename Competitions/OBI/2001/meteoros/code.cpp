
#include <stdio.h>
#define MAX 100
int main()
{
int X1,Y1,X2,Y2,X,Y;
int i;
int n,cont,met;
scanf("%d%d%d%d",&X1,&Y1,&X2,&Y2);
cont=met=0;
    while(X1!=0 && Y1!=0 && X2!=0 && Y2!=0)
    {
            scanf("%d",&n);
            for(i=0;i<n;i++)
            {
                scanf("%d%d",&X,&Y);
                if((X>=X1 && X<=X2) && (Y<=Y1 && Y>=Y2))
                    met++;

            }
            cont++;
            printf("Teste %d\n%d\n",cont,met);
            met=0;
            scanf("%d%d%d%d",&X1,&Y1,&X2,&Y2);
    }
return 0;
}
