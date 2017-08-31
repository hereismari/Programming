#include <bits/stdc++.h>
#define MAX 10030

using namespace std;


struct sorvete {
    int b, e;
    sorvete(int x=0, int y=0) { b = x; e = y;}
    bool operator < (sorvete const s) const {
        if(b != s.b) return b < s.b;
        return e > s.e;
    }
};

int p, s, x, y;
sorvete a[MAX];

int main() {

    int teste = 1;
    while(true) {
        scanf("%d %d",&p,&s);
        if(p == 0 && s == 0) break;
        for(int i = 0; i < s; i++) {scanf("%d %d",&x,&y); a[i] = sorvete(x,y);}
        sort(a, a + s);

        int begin = a[0].b;
        int end = a[0].e;
        printf("Teste %d\n", teste++);
        for(int i = 1; i < s; i++){
            if(a[i].b <= end) end = max(end, a[i].e);
            else {
                printf("%d %d\n", begin, end);
                begin = a[i].b;
                end = a[i].e;
            }
        }
        printf("%d %d\n", begin, end);
        printf("\n");
    }

    return 0;
}