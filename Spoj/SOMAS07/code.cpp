#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

#define BLACK 1
#define WHITE 0
#define MAX 100110
#define ll long long int
#define pb push_back

using namespace std;

ll n,m;
ll a[MAX], v[MAX];
vector<ll> adj[MAX];
vector<ll> black;
vector<ll> white;
bool visited[MAX];
int color[MAX];
bool flag;

void bfs(ll x){
	
	queue<ll> q;
	q.push(x);
	visited[x] = true;
	black.pb(a[x]);
	color[x] = BLACK;
	
	while(!q.empty()){
		int top = q.front(); q.pop();
		for(int i = 0; i < adj[top].size(); i++){
			int p = adj[top][i];
			if(!visited[p]){
				if(color[top] == BLACK){ color[p] = WHITE; white.pb(a[p]);
				}else { color[p] = BLACK; black.pb(a[p]); }
				visited[p] = true;
				q.push(p);
			}
			else if(color[p] == color[top]){ flag= false; break;}
		}
			
	}
	
}

int main() {

	scanf("%lld %lld",&n,&m);
	for(int i = 0 ; i < n; i++) scanf("%lld",&a[i]);
	for(int i = 0 ; i < m; i++) scanf("%lld",&v[i]);
	
	sort(a,a+n);
	sort(v,v+m);
	
	for(int i = m-1; i >= 0; i--){
		for(int j=0,k=n-1; j < k;){
			if(a[j] + a[k] > v[i]) k--;
			else if(a[j]+ a[k] < v[i]) j++;
			else {adj[j].pb(k); adj[k].pb(j); j++; k--;}
		}
	}

	flag = true;
	black.clear(); white.clear();
	for(int i = 0; i < n; i++){
		
		if(!flag) break;
		if(!visited[i])
		//	printf("%d %d\n",i,adj[i].size());
			bfs(i);
	}
	if(!flag) printf("-1\n-1\n");
	else{
		sort(black.begin(),black.end());
		sort(white.begin(),white.end());
		printf("%d",black.size());
		for(int i = 0; i < black.size(); i++) printf(" %lld",black[i]);
		printf("\n%d",white.size());
		for(int i = 0; i < white.size(); i++) printf(" %lld",white[i]);
		printf("\n");
	}
		
	return 0;
}
