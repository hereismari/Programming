#include<stdio.h>
#define N 500+5
#define M 500+5
int matriz[N][M];
int v[N],n,m;
int main() {

    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++)
        for(int j = 1;j <= m ; j++)
            scanf("%d",&matriz[i][j]);
    
    for(int i = 1; i <= n; i++)
        v[i] = m + i;

    for(int i = 1; i <= n; i++)
        for (int j = m ; j >= 1; j--)
            if (matriz[i][j] != 0)
                v[i] = j;
    bool crescente = true;
    for (int i = 1; i < n; i++)
        if (v[i] >= v[i+1])
            crescente = false;
    printf(crescente?"S\n":"N\n");
    return 0;
}



