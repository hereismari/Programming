#include <bits/stdc++.h>
#define MAX 2000
#define pb push_back
#define WHITE 0
#define BLACK 1

using namespace std;

vector<int> adj[MAX];
int color[MAX];
int num[MAX], low[MAX];
int n,m,x,y;
int counter, ans;

void calculate(int k, int par) {
    color[k] = BLACK;
    num[k] = low[k] = counter++;

    for(int i = 0; i < adj[k].size(); i++){
        int v = adj[k][i];
        if(color[v] == WHITE){
            calculate(v,k);
            if(num[k] < low[v])
                ans++;
            low[k] = min(low[v],low[k]);
        }
        else if(v != par) low[k] = min(low[k], num[v]);
    }
}

void bridges() {
    for(int i = 1; i <= n; i++){
        if(color[i] == WHITE)
            calculate(i,i);
       // printf("%d %d\n",num[i],low[i]);
    }
}

int main() {

    while(scanf("%d %d",&n,&m) != EOF) {

        ans = 0;
        counter = 0;
        for(int i = 0; i <= n; i++) adj[i].clear();
        memset(color, WHITE, sizeof color);
        for(int i = 0; i < m; i++){
            scanf("%d %d",&x,&y);
            adj[x].pb(y);
            adj[y].pb(x);
        }

        bridges();
        printf("%d\n",ans);

    }

    return 0;
}
