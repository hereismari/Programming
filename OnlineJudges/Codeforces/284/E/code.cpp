#include <bits/stdc++.h>

using namespace std;

#define MAX 100020
#define MAX_SIEVE 1e9
#define MAX_FLOW 3300
#define pb push_back
#define ll long long int
#define vll vector<ll, ll>

vll prime;
bool vis[MAX] = {0};

void generatePrimes() {
	ll n = sqrt(MAX_SIEVE) + 1;
	for(int i = 2; i <= n; i++)
	 if(!vis[i]) {
		prime.pb(i);
		for(ll k = i*i; k <= n; k += i ) vis[k] = 1;
	 }
}


ll a[MAX_FLOW] = {0}, node[MAX_FLOW] = {0};
vll adj[MAX_FLOW];
vll v[MAX_FLOW];

int flow[MAX_FLOW][MAX_FLOW] = {0};
ll par[MAX_FLOW] = {0}, match[MAX_FLOW] = {0};
bool seen[MAX_FLOW] = {0};
int id;

bool dfs(ll x) {
	
	for(ll p : v[x])
	  if(!seen[p]) {
		seen[p] = true;
		if(match[p] == -1 || dfs(match[p])) {
			match[p] = x;
			return true;
		}
	  }

	return false;
}

ll solve() {
	memset(match, -1, sizeof match);
	ll ans = 0;
	for(int i = 1; i <= id; i++) {
		memset(seen, false, sizeof seen);
	 	ans += dfs(i);
	}
	return ans;
}

int main() {

	generatePrimes();
	
	ll n, m;
	cin >> n >> m;
	
	id = 0;

	for(int i = 1; i <= n; i++) {

		cin >> a[i];
		ll num = a[i];
		
		for(ll p : prime)
			while(num % p == 0 ) {
				num /= p;
				adj[i].pb(++id);
				node[id] = p;
			}

		// se o numero for primo
		if(num > 1) { adj[i].pb(++id); node[id] = num; }
	}
	
	for(int i = 1; i <= m; i++) {
		ll x, y;
		cin >> x >> y;
		
		if(x % 2) swap(x,y);
		for(ll q : adj[x])
		 for(ll p : adj[y])
			if(node[q] == node[p]) v[q].pb(p);
	}
	
	cout << solve();
	
 }
