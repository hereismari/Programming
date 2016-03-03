#include <bits/stdc++.h> 

#define MAX_1 22
#define MAX_2 1200

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

int n, m, x, y, k, z, max_time;
bool take[MAX_1][MAX_1][MAX_2];
int dp[MAX_1][MAX_1][MAX_2];

int solve(int posx, int posy, int time) {

    if(time > max_time) return 0;
    if(posx > n || posx < 0 || posy > m || posy < 0) return 0;

    if(dp[posx][posy][time] != -1) return dp[posx][posy][time];

    bool valid = take[posx][posy][time];
    int result = valid;

    result = max(result, solve(posx + 1, posy, time + 1) + valid);
    result = max(result, solve(posx - 1, posy, time + 1) + valid);
    result = max(result, solve(posx, posy + 1, time + 1) + valid);
    result = max(result, solve(posx, posy - 1, time + 1) + valid);
    result = max(result, solve(posx + 1, posy, time + 1) + valid);
    result = max(result, solve(posx + 1, posy + 1, time + 1) + valid);
    result = max(result, solve(posx + 1, posy - 1, time + 1) + valid);
    result = max(result, solve(posx - 1, posy + 1, time + 1) + valid);
    result = max(result, solve(posx - 1, posy - 1, time + 1) + valid);
    result = max(result, solve(posx, posy, time + 1) + valid);

    return dp[posx][posy][time] = result;
}

int main() {
 
    while(true) {

        scanf("%d %d %d", &n, &m, &k);

        if(n == 0 && m == 0 && k == 0) break;
        
        max_time = 0;
        memset(dp, -1, sizeof dp);
        memset(take, false, sizeof take);

        for(int i = 0; i < k; i++) {
            scanf("%d %d %d", &x, &y, &z);
            take[x][y][z] = true;
            max_time = max(z, max_time);
        }

        scanf("%d %d", &x, &y);

        printf("%d\n", solve(x, y, 0));
    }

	return 0; 
}
