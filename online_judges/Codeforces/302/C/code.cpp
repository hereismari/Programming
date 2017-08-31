#include <bits/stdc++.h>

#define MAX 505
int a[MAX], dp[MAX][MAX];

int main() {

    int n, m, b, MOD;
    scanf("%d %d %d %d", &n, &m, &b, &MOD);
   
    for(int i = 1; i <= n; i++) 
        scanf("%d", &a[i]);   
   
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            for(int k = a[i]; k <= b; k++) 
                dp[j][k] = (dp[j][k] + dp[j - 1][k - a[i]]) % MOD;
   
    int answer = 0;
    for(int i = 0; i <= b; i++) answer = (answer + dp[m][i]) % MOD;
    printf("%d\n", answer);
    return 0;
}
