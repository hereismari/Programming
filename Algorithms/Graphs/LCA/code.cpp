#include <bits/stdc++.h>
#define ll long long int
#define MAX 10020

using namespace std;

ll parent[1001];
bool visited[1001];
ll t,n,m,q,x,y,k;

ll lca(ll x, ll y, ll n){

	for(int i = 1;i <=n ;i++) visited[i] = false;

	visited[x] = true;

	while(parent[x]!=x){
		visited[x] = true;
		x = parent[x];
	}

	visited[x] = true;

	while(!visited[y]) y = parent[y];

	return y;
}

int main() {
	scanf("%lld",&t);
	for(int i = 1; i <= t; i++){
		scanf("%lld",&n);
		for(int j = 1;j <= n;j++) parent[k] = k;
	
		for(int j = 1;j <= n;j++){
			scanf("%lld",&m);
			while(m--){
				scanf("%lld",&k);
				parent[k] = i;
			}
		}
		
		printf("Case %d:\n",i);
		scanf("%lld",&q);
		while(q--){
			scanf("%lld %lld",&x,&y);
			printf("%lld\n",lca(x,y,n));
		}
	}
	return 0;
}
