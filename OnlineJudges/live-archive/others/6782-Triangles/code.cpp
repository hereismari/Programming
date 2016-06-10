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

#define MAX 1100  
#define INF 1000000000

int n, m, x, y;

struct triangle {
    
    int l[4];
    double color;

    triangle(int l1, int l2, int l3, double c) {
        l[1] = l1; l[2] = l2; l[3] = l3; color = c;
    }

    bool operator < (const triangle &o) const {
        return color < o.color;
    };
};


vector<triangle> v;
int dp[MAX][4];
void reset() {
    v.clear();
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j <= 3; j++)
            dp[i][j] = 0;
}

int solve(int index, int used = 0) {
   
    if(index >= n) return 1;
    if(dp[index][used]) return dp[index][used];
    
    int res = 1;
    for(int i = index+1; i < n; i++)
        for(int j = 1; j <= 3; j++)
            for(int k = 1; k <= 3; k++)
                if(j != used && v[i].color != v[index].color && v[index].l[j] == v[i].l[k]) {
                    res = max(res, solve(i, k) + 1);
                }
    return dp[index][used] = res;
}

int main() {
 
    while(scanf("%d", &n) != EOF) {

        reset();
        int l1, l2, l3;
        double c;

        for(int i = 0; i < n; i++) {
            scanf("%d %d %d %lf", &l1, &l2, &l3, &c);
            v.pb(triangle(l1, l2, l3, c));
        }
        
        sort(v.begin(), v.end());
        int ans = 0;
        for(int i = 0; i < n; i++)
            ans = max(ans, solve(i));
        printf("%d\n", ans);
    }

	return 0; 
}
