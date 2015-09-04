#include <stdio.h>
#include <math.h>

int main()
{
    int n,cont=0;

    scanf("%d",&n);
    while(n!=-1)
    {
        cont++;
        n=(pow(4,n)+pow(2,n+1)+1);
        printf("Teste %d\n%d\n\n",cont,n);
        scanf("%d",&n);
    }
    return 0;
}
