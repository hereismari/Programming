#include <bits/stdc++.h>
using namespace std;

#define range(i,n) for(int i=0; i<n; ++i)
#define mp(a,b) make_pair(a,b)
#define F first
#define S second
#define pii pair <int,int>
#define pb push_back
#define MAX 1020

typedef long long ll;

struct Ans {
	ll num, den;
	int mov;
	Ans(ll n=0, ll d=0, ll m=0) { num = n; den = d; mov = m; }
};

int n, m;
ll x[MAX], y[MAX], r[MAX];
Ans ans[MAX];
string mov[3];
vector<int> adj[MAX];
bool vis[MAX];

bool verify(int i, int j) { return ((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])* (y[i]-y[j])) == (r[i] + r[j]) * (r[i] + r[j]); } 

void modify(int i, int j) {
	
	ans[i].den = ans[j].den * r[i];
	ans[i].num = ans[j].num * r[j];
	
	int g = __gcd(ans[i].den, ans[i].num);
	ans[i].den /= g;
	ans[i].num /= g;
	
	if(ans[j].mov == 1) ans[i].mov = 2;
	else ans[i].mov = 1;
}

void dfs(int node) {
	vis[node] = true;
	for(int i = 0; i < (int)adj[node].size(); i++){
		int v = adj[node][i];
		if(!vis[v]) { modify(v, node); dfs(v); }
	}
}

int main() {
	
	mov[0] = "not moving";
	mov[1] = "clockwise";
	mov[2] = "counterclockwise";
	
	scanf("%d", &n);
	while(n--) {
		
		scanf("%d", &m);
		
		for(int i = 0; i < m; i++) { adj[i].clear(); ans[i].mov = 0; ans[i].num = 1; ans[i].den = 1;}
		memset(vis, false, sizeof vis);
		ans[0].num = ans[0].den = ans[0].mov = 1;
		
		range(i,m) cin >> x[i] >> y[i] >> r[i];
		
		for(int i = 0; i < m; i++){
			for(int j = i+1; j < m; j++)
				if(verify(i,j)) { adj[i].pb(j); adj[j].pb(i); }
		}
		
		dfs(0);
		for(int i = 0; i < m; i++) {
			if(ans[i].mov == 0) cout << mov[ans[i].mov] << endl;
			else if(ans[i].den == 1) cout << ans[i].num << ' ' << mov[ans[i].mov] << endl;
			else cout << ans[i].num << '/' << ans[i].den << ' ' << mov[ans[i].mov] << endl;
		}	
	}
	
	
	return 0;
}
