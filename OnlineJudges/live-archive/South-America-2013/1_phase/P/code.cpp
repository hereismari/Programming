#include <bits/stdc++.h>
#define MAX 1500000
#define INF 1500000
using namespace std;

int a[MAX];
int dp[MAX];

int main() {

    int n,l,t1,t2;
    while(scanf("%d %d %d %d",&n,&l,&t1,&t2) != EOF) {
        for(int i = 0; i < n; i++){
            scanf("%d",&a[i]);
        }

        sort(a,a+n);
        int ans = INF;
        for(int i = 0; i < n; i++){
            memset(dp,INF,sizeof dp);
            dp[0] = 0;
            int ans1 = 0, ans2 = 0;
            for(int k = 0; k < n; k++){
                while(ans2 < n-1 && a[ans2+1] <= a[k] + t2) {ans2++;}
                while(ans1 < n-1 && a[ans1+1] <= a[k] + t1) {ans1++;}
                dp[ans1+1] = min(dp[ans1+1],dp[k] + t1);
                dp[ans2+1] = min(dp[ans2+1],dp[k] + t2);
            }
            ans = min(ans,dp[n]);
            swap(a[0],a[n]);
            a[n] += l;
            for(int j = 0; j < n; j++) {a[j] = a[j+1]; }
        }
        printf("%d\n",ans);
    }
    return 0;
}
