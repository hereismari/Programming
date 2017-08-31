#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m;
    int count = 1;
    
    while(scanf("%d %d", &n, &m) != 0 && n && m) {
        
        int d[n+1], p[n+1];
        for(int i = 1; i <= n; i++) scanf("%d %d", &d[i], &p[i]);

        int dp[m+1];
        for(int i = 0; i <= m; i++) dp[i] = 0;

        int ans = 0;
        for(int i = 0; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(d[j] <= i) {
                    ans = max(dp[i-d[j]] + p[j], ans);
                }

                dp[i] = ans;
            }
        }

        printf("Instancia %d\n", count++);
        printf("%d\n\n", dp[m]);
    }

    return 0;
}
