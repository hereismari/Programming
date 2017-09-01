#include <stdio.h>
#define FALSE 0
#define TRUE 1
int main()
{
    int N,i,j,cont,maior,x,fim=FALSE;
    char m[101][101];

    scanf("%d",&N);

    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            scanf("\n%c",&m[i][j]);

    maior = 0;
    cont = 0;
    for (i = 0; i < N; i++)
    {
        for ( j = 0; j < N;j++)
        {
            if ( fim == FALSE)
                x = j;
            else
                x = N - j - 1;

            if (m[i][x] == 'o')
                cont++;
            else if (m[i][x] == 'A')
            {
                if (cont > maior)
                    maior = cont;
                cont = 0;
            }

        }
        if ( fim == FALSE)
           fim = TRUE;
        else
           fim = FALSE;
    }
    if (cont > maior)
                    maior = cont;
    printf("%d",maior);

    return 0;
}

