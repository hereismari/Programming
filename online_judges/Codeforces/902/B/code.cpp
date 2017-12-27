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

#define MAX 10010  
#define INF 1000000000

int n, m, x, y, res;
int graph[MAX], color[MAX];
vector<int> g[MAX];

int dfs(int node) {

    if(color[node] != color[graph[node]]) res++;

    for(int i = 0; i < g[node].size(); i++) {
        if(g[node][i] != graph[node])
            dfs(g[node][i]);
    }
}

int main() {

    res = 1; 
    while(scanf("%d", &n) != EOF) {
       for(int i = 2; i <= n; i++) {
            scanf("%d", &graph[i]);
            g[graph[i]].pb(i);
       }
       graph[1] = 1;

        for(int i = 1; i <= n; i++) scanf("%d", &color[i]);
    
        dfs(1);
        printf("%d\n", res);
    }

	return 0; 
}
