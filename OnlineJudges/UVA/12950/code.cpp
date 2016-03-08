#include <bits/stdc++.h>

#define pii pair<int, ll>

#define mp make_pair 
#define F first
#define S second
#define pb push_back 
#define MAX 15000
#define INF 530000000
#define ll long long int

using namespace std;

int n, m;
vector< pii > adj[MAX];
ll x, y, w;
ll dist[2][MAX];

struct aux {
    
    ll from, dist, even;
    
    aux(ll f, ll d, ll e){
        from = f;
        dist = d;
        even = e;
    }

    bool operator < (const aux & a) const {
        return dist > a.dist;
    }
};

ll dijkstra(){

    priority_queue<aux> q;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j <= n; j++)
            dist[i][j] = INF;

    q.push(aux(1,0,0));
    dist[0][1] = 0;

    while(!q.empty()){
        aux top = q.top(); q.pop();
        for(int i = 0; i < adj[top.from].size(); i++){
            int v = adj[top.from][i].F;
            ll w = adj[top.from][i].S;
//            printf("%d\n", w);
            if(dist[top.even][top.from] + w < dist[(top.even + 1) % 2][v]){
                dist[(top.even + 1) % 2][v] = dist[top.even][top.from] + w;
                q.push(aux(v, dist[top.even][top.from] + w, (top.even + 1) % 2));
            }
       }
    }

    return dist[0][n] == INF ? -1 : dist[0][n];
}

int main() {

    while(scanf("%d %d",&n, &m) != EOF) {
    
        for(int i = 0; i <= n; i++) adj[i].clear();

        for(int i = 0; i < m; i++) {
            scanf("%lld %lld %lld",&x,&y,&w);
            adj[x].pb(mp(y,w));
            adj[y].pb(mp(x,w));
        }

        printf("%lld\n", dijkstra());
    }

    return 0;
}
