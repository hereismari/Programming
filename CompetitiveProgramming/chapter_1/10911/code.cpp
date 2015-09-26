#include <bits/stdc++.h> 

#define MAX 16
#define INF 4000*4000
#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

struct PT {
    int x, y;
    PT(int a=0, int b=0) { x = a; y = b; }
    double dist(PT p) { return sqrt((x - p.x)*(x - p.x) + (y - p.y)*(y - p.y)); }
};

string s;
int n,m,x,y;
vector<PT> v; 
double dp[1 << MAX];
double dist[MAX+2][MAX+2];

double solve(int k) {

    if(k >= ((1 << n) - 1)) return dp[k]=0;
    if(dp[k] >= 0) return dp[k];
    double ans = INF;
    for(int i = 0; i < n; i++){
        if(!(k & (1 << i)))
            for(int j = i + 1; j < n; j++){
                    if(!(k & (1 << j)))
                        ans = min(ans, solve(k | (1 << i) | (1 << j)) + dist[i][j]);
            }
    }
    return dp[k] = ans;
}

int main() {
 
    int cont = 1;
    while(scanf("%d",&n) && n != 0){
        
        v.clear();
        n *= 2;
        memset(dp, -1, sizeof dp);

        for(int i = 0; i < n; i++){
            cin >> s >> x >> y;
            v.pb(PT(x,y));
        }

        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++){
                dist[i][j] = dist[j][i] = v[i].dist(v[j]);
            }

        printf("Case %d: %.2f\n", cont++, solve(0));
    }
	return 0; 
}
