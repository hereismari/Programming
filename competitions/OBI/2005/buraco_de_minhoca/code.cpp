#include <bits/stdc++.h>
#define MAX 3010
#define pb push_back

using namespace std;

stack<int> s;
vector<int> adj[MAX];
int id[MAX], min_id[MAX];
int n, m, a, b;
bool visited[MAX];
int size, cont;
void StrongComponent(int x) {

    visited[x] = true;
    s.push(x);
    id[x] = min_id[x] = cont++;
    for(int i = 0; i < adj[x].size(); i++){
        int v = adj[x][i];
        if(!visited[v]){
            StrongComponent(v);
            min_id[x] = min(min_id[v], min_id[x]);
        }
        else min_id[x] = min(min_id[x], id[v]);
    }
    if(min_id[x] == id[x]) {
        while(s.top() != x) {s.pop(); size++;}
        size++;
        return;
    }
}

int main() {

    int teste = 1;
    while(scanf("%d %d",&n,&m) == 2 && n > 0) {

        for(int i = 0; i <= n; i++) {adj[i].clear(); visited[i] = false;}
        memset(visited, false,sizeof visited);
        size = cont = 0;
        while(!s.empty()) s.pop();
        for(int i = 0; i < m; i++){
            scanf("%d %d",&a,&b);
            adj[a].pb(b);
        }

        StrongComponent(1);
        printf("Teste %d\n%c\n\n",teste++, (size == n) ? 'S' : 'N');
    }

    return 0;
}
