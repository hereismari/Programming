#include <bits/stdc++.h> 

#define MAX 100010 
#define EPS 1e-7

#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

int n, m, x, y;
vector<int> adj[MAX];
ll maxSize[MAX], value[MAX];

void dp() {

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < adj[i].size(); j++) {
            int v = adj[i][j];
            if(maxSize[i] + 1 > maxSize[v])
                maxSize[v] = maxSize[i] + 1;
        }
    }
}

int main() {
 
    while(scanf("%d %d", &n, &m) != EOF){

        memset(maxSize, 0, sizeof maxSize);
        memset(value, 0, sizeof value);

        for(int i = 0; i < m; i++) {
            scanf("%d %d", &x, &y);
            if(x > y) { int aux = x; x = y; y = aux; }
            adj[x].pb(y); value[x]++; value[y]++;
        }

        dp();

        ll ans = 1;
        for(int i = n; i >= 1; i--) {
           ll aux = ((maxSize[i] + 1) * value[i]);
           if (aux > ans) ans = aux;
        }
        
        printf("%lld\n", ans);

    }

	return 0; 
}
