#include <bits/stdc++.h>
#define MAX 10000

int main() {

    int n, x;
    scanf("%d",&n);
    int ans = 0, aux = 0;
    for(int i = 0; i < n; i++){
        scanf("%d",&x);
        aux += x;
        if(aux > ans) ans = aux;
        else if(aux < 0) aux = 0;
    }

    printf("%d\n",ans);
    return 0;
}
