#include <bits/stdc++.h>

using namespace std;

void solve(int len, int dist) {
    
    for(int mask = 0; mask < pow(2, len); mask++) {
        
        int cont = 0;
        string s = "";
        for(int j = 0; j < len; j++) {
            if(mask & (1 << j)) cont++;
            s += (mask & (1 << j) ? "1" : "0");
        }

        if(cont == dist) { 
            for(int j = len-1; j >= 0; j--) {
                printf("%c", s[j]);
            }
            printf("\n");
        }
    }
}


int main() {

    int t;
    scanf("%d", &t);

    int n, m;
    while(t--) {
        scanf("%d %d", &n, &m);
        solve(n, m);
        if(t) printf("\n");
    }

    return 0;
}
