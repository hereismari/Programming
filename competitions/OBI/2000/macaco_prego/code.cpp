#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, teste = 1;
    int x1,x2,y1,y2,aux_x1,aux_x2,aux_y1,aux_y2;
    while(true) {
        scanf("%d",&n);
        if(n == 0) break;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        bool possible = true;
        for(int i = 0; i < n-1; i++) {
            scanf("%d %d %d %d",&aux_x1, &aux_y1, &aux_x2, &aux_y2);
            if(aux_x1 > x2) possible = false;
            if(aux_x2 < x1) possible = false;
            if(aux_y1 < y2) possible = false;
            if(aux_y2 > y1) possible = false;
            x1 = max(aux_x1, x1);
            x2 = min(aux_x2, x2);
            y1 = min(aux_y1, y1);
            y2 = max(aux_y2, y2);
        }

        printf("Teste %d\n",teste++);
        if(possible) printf("%d %d %d %d\n\n",x1,y1,x2,y2);
        else printf("nenhum\n\n");
    }


    return 0;
}
