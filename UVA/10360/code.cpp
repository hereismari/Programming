#include <bits/stdc++.h> 

#define MAX 1030 
#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

int n, m, x, y, p, d;
int mat[MAX][MAX];

int main() {
 
    scanf("%d", &n);

    while(n--) {

        memset(mat, 0 , sizeof mat);
        
        scanf("%d %d", &d, &m);
        for(int k = 0; k < m; k++){
            scanf("%d %d %d", &x ,&y, &p);
            for(int i = max(0, x - d); i <= min(MAX-1, x + d); i++)
                for(int j = max(0, y - d); j <= min(MAX-1, y + d); j++)
                    mat[i][j] += p;
        }

        int ans = 0;
        int res_x = 0, res_y = 0;
        for(int i = 0; i < MAX; i++)
            for(int j = 0; j < MAX; j++){
                if(mat[i][j] > ans){
                    ans = mat[i][j];
                    res_x = i;
                    res_y = j;
                }
            }

        printf("%d %d %d\n", res_x, res_y, ans);
    }

	return 0; 
}
