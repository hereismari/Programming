#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF) {
        
        int x;
        set<int> s;
        for(int i = 0; i < n; i++) {
            scanf("%d", &x);
            if(i == 0) printf("%d", x);
            else if(s.find(x) == s.end()) printf(" %d", x);
            s.insert(x);
        }

        printf("\n");

    }

    return 0;
}
