#include <bits/stdc++.h>
#define MAX 2100
#define mi map<string,int>
#define pb push_back
#define vs vector<string>
#define vi vector<int>
#define mp make_pair
#define F first
#define S second

using namespace std;

vi adj[MAX];
vs nomes;
mi nome_id;
int n;
string x, y;

int bfs(int a, int b) {

    int ans = 0;
    bool vis[MAX]; memset(vis, false, sizeof vis);
    vis[a] = true;
    queue< pair<int,int> > q;
    q.push(mp(a,0));

    while(!q.empty()) {
        int top = q.front().F;
        int dist = q.front().S;
        q.pop();
        for(int i = 0; i < adj[top].size(); i++){
            int v = adj[top][i];
            if(v == b) return dist + 1;
            else if(!vis[v]){
                vis[v] = true; q.push(mp(v,dist+1));
            }
        }
    }
    return ans;
}


int main() {

    scanf("%d", &n);
    int aux = 1;

    //montando o grafo
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        if(nome_id.find(x) == nome_id.end()) nome_id[x] = aux++, nomes.pb(x);
        if(nome_id.find(y) == nome_id.end()) nome_id[y] = aux++, nomes.pb(y);
        adj[nome_id[x]].pb(nome_id[y]);
    }

    sort(nomes.begin(), nomes.end());
    for(int i = 1; i < nomes.size(); i++){
        adj[nome_id[nomes[i-1]]].pb(nome_id[nomes[i]]);
        adj[nome_id[nomes[i]]].pb(nome_id[nomes[i-1]]);
    }

    cin >> x >> y;
    printf("%d\n",bfs(nome_id[x], nome_id[y]));
    return 0;
}
