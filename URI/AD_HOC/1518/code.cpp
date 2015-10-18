#include <bits/stdc++.h> 

#define MAX 1000100 
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

int n, m, x, y, aux_x, aux_y;
int t_x[3], t_y[3];
char t_dir[3];

int solve(int f, int m, int l) {

    //BFS

}

int main() {
 
    while(scanf("%d %d", &x, &y) && (x || y)){
        for(int i = 0; i < 3; i++)
            scanf("%d %d %c", &t_x[i], &t_y[i], &t_dir[i]);
        
        int ans = INT_MAX;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                for(int k = 0; k < 3; k++)
                    if(i != j && i != k && j != k) ans = min(ans, solve(i,j,k));


        printf("%d\n", ans);
    }

	return 0; 
}
