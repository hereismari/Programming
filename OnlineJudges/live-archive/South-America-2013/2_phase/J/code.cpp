#include <bits/stdc++.h> 

#define MAX 40320 
#define EPS 1e-7

#define ll unsigned long long
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

int n, m, x, y, aux;
vi adj_n[MAX], adj_m[MAX];
int dist_n[MAX], dist_m[MAX];
int p1_n, p2_n, p1_m, p2_m, len_n, len_m, max_len;
bool vis_n[MAX], vis_m[MAX];

void clearEverything() {

    for(int i = 0; i <= n; i++) { adj_n[i].clear(); }
    for(int i = 0; i <= m; i++) { adj_m[i].clear(); }

    memset(dist_n, 0, sizeof dist_n);
    memset(dist_m, 0, sizeof dist_m);
}

void dfsN(int node, int dist=0, int type=1, bool flag=false) {
    dist_n[node] = max(dist_n[node], dist);
    vis_n[node] = true;
    if(dist > aux && flag) { 
        aux = dist; 
        if(type == 1) p1_n = node;
        else p2_n = node; 
    }
    for(int i = 0; i < adj_n[node].size(); i++) {
        int v = adj_n[node][i];
        if(!vis_n[v]) dfsN(v, dist + 1, type, flag);
    }
}

void dfsM(int node, int dist=0, int type=1, bool flag=false) {
    dist_m[node] = max(dist, dist_m[node]);
    vis_m[node] = true;
    if(dist > aux && flag) { 
        aux = dist; 
        if(type == 1) p1_m = node;
        else p2_m = node; 
    }
    for(int i = 0; i < adj_m[node].size(); i++) {
        int v = adj_m[node][i];
        if(!vis_m[v]) dfsM(v, dist + 1, type, flag);
    }
}

void getTreeLengthN() {
    aux = -1;
    memset(vis_n, false, sizeof vis_n);
    dfsN(1, 0, 1, true);
    memset(vis_n, false, sizeof vis_n);
    aux = -1;
    memset(vis_n, false, sizeof vis_n);
    dfsN(p1_n, 0, 2, true);
    memset(vis_n, false, sizeof vis_n);
    dfsN(p2_n);

    len_n = -1;
    for(int i = 1; i <= n; i++) if(dist_n[i] > len_n) len_n = dist_n[i]; 
}

void getTreeLengthM() {
    aux = -1;
    memset(vis_m, false, sizeof vis_m);
    dfsM(1, 0, 1, true);
    memset(vis_m, false, sizeof vis_m);
    aux = -1;
    dfsM(p1_m, 0, 2, true);
    memset(vis_m, false, sizeof vis_m);
    dfsM(p2_m);

    len_m = -1;
    for(int i = 1; i <= m; i++) if(dist_m[i] > len_m) len_m = dist_m[i]; 
}

int main() {
 
    while(scanf("%d %d",&n, &m) != EOF){
        if(n == 1 && m == 1) { printf("%.3f\n", 1.0); continue; } 
        clearEverything();
        
        for(int i = 0; i < n-1; i++) {
            scanf("%d %d", &x, &y);
            adj_n[x].pb(y);
            adj_n[y].pb(x);
        }
        
        for(int i = 0; i < m-1; i++) {
            scanf("%d %d", &x, &y); 
            adj_m[x].pb(y);
            adj_m[y].pb(x);
        }

        getTreeLengthN();
        getTreeLengthM();
	for(int i = 1; i <= n; i++) dist_n[i]++;
        
        sort(dist_m, dist_m + m + 1);
        sort(dist_n, dist_n + n + 1); 

        ll sum_acum[m+1];
        sum_acum[0] = 0;
        for(int i = 1; i <= m; i++) sum_acum[i] = sum_acum[i-1] + dist_m[i];

        double ans = 0;
        int index = m+1;
        max_len = max(len_n, len_m);
        for(int i = 1; i <= n; i++) {
            while(index - 1 >= 1 && dist_n[i] + dist_m[index-1] >= max_len)
                index--;
            if(index == 1) ans += sum_acum[m] + m*dist_n[i];
            else if(index == m+1) ans += (double) max_len * m;
            else {
                ans += (double) max_len * (index-1);
                ans += (double) sum_acum[m] - sum_acum[index-1] + (m-index+1) * dist_n[i];
                }
        }
        printf("%.3lf\n", ans/n/m);
    }

	return 0; 
}
