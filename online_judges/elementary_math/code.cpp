#include <bits/stdc++.h>

using namespace std;

#define MAX 91500

#define pb push_back
#define ll long long int

int n;
int cont;

vector<int> adj[MAX];
map<ll, int> m;

int married[MAX];
bool vis[MAX];

void make_edges(int i, ll v1, ll v2) {
    
    if(m.find(v1 + v2) == m.end()) m[v1 + v2] = ++cont;
    if(m.find(v1 - v2) == m.end()) m[v1 - v2] = ++cont;
    if(m.find(v1 * v2) == m.end()) m[v1 * v2] = ++cont;
   
    adj[i].pb(m[v1 + v2]); adj[m[v1 + v2]].pb(i);
    adj[i].pb(m[v1 - v2]); adj[m[v1 - v2]].pb(i);
    adj[i].pb(m[v1 * v2]); adj[m[v1 * v2]].pb(i);
}

ll get_matchI(int i, ll v1, ll v2) {
    if(married[i] == m[v1 + v2]) return v1 + v2;
    if(married[i] == m[v1 - v2]) return v1 - v2;
    if(married[i] == m[v1 * v2]) return v1 * v2;
}

char get_matchII(int i, ll v1, ll v2) {
    if(married[i] == m[v1 + v2]) return '+';
    if(married[i] == m[v1 - v2]) return '-';
    if(married[i] == m[v1 * v2]) return '*';
}

bool augment(int id) {

    vis[id] = true;

    for(int i = 0; i < adj[id].size(); i++) {

        int v = adj[id][i];
        if(vis[v]) continue;
        vis[v] = true;

        if(married[v] == -1) {
            married[v] = id; married[id] = v;
            return true;
        }
        else if(married[v] != id && augment(married[v])) {
            married[id] = v; married[v] = id;
            return true;
        }
    }

    return false;
}


int max_match() {
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < MAX; j++) vis[j] = false;
        ans += augment(i);

    }
    return ans;
}

int main() {

    for(int i = 0; i < MAX; i++) married[i] = -1;

    scanf("%d", &n);
    
    cont = n;
    ll x[n+1], y[n+1];
    
    for(int i = 1; i <= n; i++) {
        scanf("%lld %lld", &x[i], &y[i]);
        make_edges(i, x[i], y[i]);
    }

    int ans = max_match();

    if(ans == n) {
        for(int i = 1; i <= n; i++)
            printf("%lld %c %lld = %lld\n", x[i], get_matchII(i, x[i], y[i]), y[i], get_matchI(i, x[i], y[i]));
    }
    else {
        printf("impossible\n");
    }

    return 0;
}

