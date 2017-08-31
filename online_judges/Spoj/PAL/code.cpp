#include <bits/stdc++.h>
#define MAX 3000
#define INF MAX*MAX
using namespace std;


int n, dp[MAX];
bool isPal[MAX][MAX];
char s[MAX];

int main() {

    int teste = 1;
    while(scanf("%d",&n) == 1 && n > 0) {
        
        scanf(" \n%s",s);
        memset(isPal, false, sizeof isPal);
        for(int i = 0; i < n; i++) isPal[i][i] = true;
        for(int j = 1; j < n; j++)
            for(int i = j-1; i >= 0; i--)
                isPal[i][j] = ((i+1>=j-1 || isPal[i+1][j-1]) && (s[i] == s[j]));

        for(int i = 0; i < n; i++){
            if(isPal[0][i]) dp[i] = 1;
            else {
                int j, min = INF;
                for(j = 1; j <= i; j++){
                    if(isPal[j][i] && (dp[j-1] + 1 < min))
                            min = dp[j-1] + 1;
                }
                dp[i] = min;
            }
        }

        printf("Teste %d\n%d\n\n",teste++, dp[n-1]);
    }

    return 0;
}