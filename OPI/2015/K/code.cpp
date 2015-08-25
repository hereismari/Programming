#include <bits/stdc++.h>
#define MAX 3000

using namespace std;
int n, m, a[MAX];
int sum_acum[MAX], dp[MAX][MAX], divi[MAX][MAX];

bool realValue(int n) {
    int result =  (n % 10 < 5) ? (n - (n % 10)): n + (10 -( n % 10));
    printf("%d\n", result);
    return result;
}

void goDP() {
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int pos_ans1 = realValue(dp[i][j-1] + realValue(sum_acum[n-1] - sum_acum[j-1]));
            int pos_ans2 = realValue(dp[i][j-1] + a[j] + realValue(sum_acum[n-1] - sum_acum[j]));

            if(pos_ans1 < pos_ans2) {
                divi[i][j] = divi[i][j-1] + 1;
                dp[i][j] = pos_ans1;
            }
            else {
                divi[i][j] = divi[i][j-1];
                dp[i][j] = pos_ans2;
            }
        }
    }
}


int main() {

    while(scanf("%d %d",&n,&m) != EOF) {

        for(int i = 0; i < n; i++) {scanf("%d",&a[i]); sum_acum[i] = a[i];}
        for(int i = 1; i <= n; i++) sum_acum[i] += sum_acum[i-1];
        memset(dp, 0, sizeof dp);
        memset(divi, 0, sizeof divi);
        int ans = INT_MAX;
        goDP();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(divi[i][j] <= m) ans = min(ans,divi[i][j]);
        printf("%d\n",ans);
    }
    return 0;
}
