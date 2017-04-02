#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    int c = 1;
    while(true) {

        scanf("%d", &n);
        if(n == 0) break;
    
        int ans = 0, x;
        for(int i = 0; i < n; i++) {
            scanf("%d", &x);
            ans += bool(x);
        }

        printf("Case %d: %d\n", c++, ans - (n - ans));
    }

}
