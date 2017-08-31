#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);

    int ans = 0, v = 0, i = 1;

    while(v <= n) {
        
        v = 0;
        int aux = 1;
        int a = i;
        while(a) {
            v = v + aux * (a & 1);
            a = a >> 1;
            aux *= 10;
        }
        
        if(v <= n) ans++;
        i++;
    }

    printf("%d\n", ans);
    return 0;
}
