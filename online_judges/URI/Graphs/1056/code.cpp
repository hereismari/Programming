#include <bits/stdc++.h>

using namespace std;

#define MAX 300

#define pb push_back
#define ll long long int

int n;

vector<int> adj[MAX];
int married[MAX];
bool vis[MAX];

ll a[MAX], b[MAX];
int size_a, size_b; 

void make_edge(int i, int j) {
  adj[i].pb(j); adj[j].pb(i);
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
    for(int i = 0; i < size_a; i++) {
        for(int j = 0; j < MAX; j++) vis[j] = false;
        ans += augment(i);
    }
    return ans;
}

int main() {

  scanf("%d", &n);
  for(int k = 1; k <= n; k++) {
    
    for(int i = 0; i < MAX; i++) {
      adj[i].clear();
      married[i] = -1;
    }

    scanf("%d", &size_a);
    for(int i = 0; i < size_a; i++) {
      scanf("%lld", &a[i]);
    }
    
    scanf("%d", &size_b);
    for(int i = 0; i < size_b; i++) {
      scanf("%lld", &b[i]);
    }
    
    for(int i = 0; i < size_a; i++) {
      for(int j = 0; j < size_b; j++) {
        if((a[i] == 0 && b[j] == 0) || (a[i] != 0 && b[j] % a[i] == 0)) make_edge(i, j + size_a);
      }
    }
    
    int ans = max_match();

    printf("Case %d: %d\n", k, ans);
  }

  return 0;
}

