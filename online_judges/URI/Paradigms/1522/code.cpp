#include <bits/stdc++.h> 

#define MAX 110 
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

struct lvl {
    int x, y, z;
    lvl(int x = 0, int y = 0, int z = 0) {
        this-> x = x;
        this-> y = y;
        this-> z = z;
    }
};

int n, m, x, y, z;
lvl a[MAX];
int dp[MAX][MAX][MAX];

bool solve(int x, int y, int z) {

    if(x >= n && y >= n && z >= n) return true;

    if(dp[x][y][z] != -1) return dp[x][y][z];

    bool result = false;

    // all of them
    if(x < n && y < n && z < n)
        result |= (((a[x].x + a[y].y + a[z].z) % 3 == 0) && solve(x+1, y+1, z+1));
    
    // make a pair
    if(x < n && y < n)
        result |= (((a[x].x + a[y].y) % 3 == 0) && solve(x+1, y+1, z));
    if(x < n && z < n)
        result |= (((a[x].x + a[z].z) % 3 == 0) && solve(x+1, y, z+1));
    if(y < n && z < n)
        result |= (((a[y].y + a[z].z) % 3 == 0) && solve(x, y+1, z+1));
    
    // just 1 
    if(x < n)
        result |= (a[x].x % 3 == 0) && solve(x+1, y, z);
    if(y < n)
        result |= (a[y].y % 3 == 0) && solve(x, y+1, z);
    if(z < n) 
        result |= (a[z].z % 3 == 0) && solve(x, y, z+1);
    
    return dp[x][y][z] = result;

}

int main() {
 
    while(scanf("%d",&n) != EOF){

        memset(dp, -1, sizeof dp);
        if(n == 0) break;
        for(int i = 0; i < n; i++) {
            scanf("%d %d %d", &x, &y, &z);
            a[i] = lvl(x, y, z);
        }

        printf("%d\n", solve(0, 0, 0));
    }

	return 0; 
}
