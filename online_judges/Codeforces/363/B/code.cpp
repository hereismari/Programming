#include <bits/stdc++.h> 

using namespace std; 

#define EPS 1e-7
#define MOD 1000000007

#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >

#define MAX 1000100  
#define INF 1000000000

int n, m, x, y;

int main() {

    scanf("%d %d", &n, &m);

    char mat[n][m];

    int r[n], c[m], bombs = 0;
    
    memset(r, 0, sizeof r);
    memset(c, 0, sizeof c);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            scanf("\n%c", &mat[i][j]);
            if(mat[i][j] == '*') { 
                r[i]++;
                c[j]++;
                bombs++;
            }
        }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if((r[i] + c[j] - (mat[i][j] == '*')) == bombs) {
                printf("YES\n%d %d\n", i+1, j+1);
                return 0;
            }
    printf("NO\n");

	return 0; 
}
