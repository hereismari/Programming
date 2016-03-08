#include <bits/stdc++.h> 

#define MAX 1010 
#define EPS 1e-7

#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

int n, m, x, y;

int main() {
 
    scanf("%d %d %d %d", &n, &m, &x, &y);
    
    char mat[n+1][m+1];
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("\n%c", &mat[i][j]);
    
    int need[2][m+1];
    for(int j = 1; j <= m; j++) {
        need[0][j] = need[1][j] = 0;
        for(int i = 1; i <= n; i++) {
            need[0][j] += (mat[i][j] == '.');
            need[1][j] += (mat[i][j] == '#');
        }
    }

    ll acum[2][m+1];
    acum[0][0] = acum[1][0] = 0;

    for(int i = 1; i <= m; i++) { 
        acum[0][i] = acum[0][i-1] + need[0][i];
        acum[1][i] = acum[1][i-1] + need[1][i];
    }

    ll dp[2][m+1];

    dp[0][0] = 0;
    dp[1][0] = 0;

    ll aux1, aux2;

    for(int i = 1; i <= m; i++) {
        
       aux1 = aux2 = INT_MAX;
       for(int j = x; j <= y && j <= i; j++) {
            aux1 = min(dp[1][i-j] + acum[0][i] - acum[0][i-j], aux1);
            aux2 = min(dp[0][i-j] + acum[1][i] - acum[1][i-j], aux2);
       }
      
       dp[0][i] = aux1;
       dp[1][i] = aux2; }
       
    printf("%lld\n", min(dp[0][m], dp[1][m]));
	return 0; 
}
