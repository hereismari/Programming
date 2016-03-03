#include <bits/stdc++.h>

#define FAT 8
#define MAX 100400
#define INF MAX
using namespace std;

int n, fat[FAT+10];
int dp[MAX];

void calculateFatorial() {
    fat[0] = 1;
    dp[1] = 1;
    for(int i = 1; i <= FAT; i++){
        fat[i] = i*fat[i-1];
        dp[fat[i]] = 1;
    }
}

int answer() {

    if(dp[n] != INF) return dp[n];
    
    for(int i = 2; i <= n; i++){
        for(int j = 1; fat[j] < i && j <= FAT; j++)
            dp[i] = min(dp[i], dp[i-fat[j]] + 1);
   }
    
    return dp[n];
}

int main() {

    for(int i = 0; i < MAX; i++) dp[i] = INF;
    calculateFatorial();
    while(scanf("%d", &n) != EOF) {
        printf("%d\n", answer());
    }

    return 0;

}

