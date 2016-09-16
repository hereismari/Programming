#include <bits/stdc++.h>

using namespace std;

#define MAX 60

char mat[MAX][MAX];
int memo[MAX][MAX];

int aux_x[] = {1, 1, 1, 0, 0, 0, -1, -1, -1};
int aux_y[] = {1, -1, 0, 1, -1, 0, 1, -1, 0};

int n, m;

bool valid(int i, int j, int v) {
    return i >= 0 && i < n && j >= 0 && j < m && (mat[i][j] - 'A' == v + 1);
}

int solve(int i, int j) {
    
    if(memo[i][j] != -1) return memo[i][j];

    int res = 1;
    for(int k = 0; k < 9; k++) {
        if(valid(i + aux_x[k], j + aux_y[k], mat[i][j] - 'A'))
            res = max(res, 1 + solve(i + aux_x[k], j + aux_y[k]));
    }

    return memo[i][j] = res;
}

int main() {

    int cont = 1;
    while(scanf("%d %d", &n, &m) != EOF && n > 0 && m > 0) {
        
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) {
                scanf("\n%c", &mat[i][j]);
                memo[i][j] = -1;
            }
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++)
                ans = mat[i][j] == 'A' ? max(ans, solve(i,j)) : ans;
        }
        
        printf("Case %d: %d\n", cont++, ans);
    }
    return 0;
}
