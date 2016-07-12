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

#define MAX 200100  
#define INF 100000000

int n, m, x, y, cont;
int d[MAX];
vector<int> adj[MAX];
int vis[MAX];

void bfs(int i) {

    queue<int> q;

    q.push(i);
    while(!q.empty()) {

        int t = q.front();
        q.pop();
    
        for(int j = 0; j < adj[t].size(); j++) {
            int v = adj[t][j];
            if(d[t] + 1 < d[v]) {
                q.push(v);
                d[v] = d[t] + 1;
            }
        }
    }
}

int main() {

    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &x);

        adj[i].pb(x);
        adj[i].pb(i-1);
        adj[i-1].pb(i);
        
        d[i] = i - 1;
    }

    for(int i = 1; i <= n; i++) bfs(i);
    for(int i = 1; i <= n; i++) printf("%d ", d[i]);

	return 0; 
}
