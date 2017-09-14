#include <bits/stdc++.h>

using namespace std;

#define MAX 10010

vector<pair<int, int> > graph[MAX+1];
int e[MAX+1];
bool visitado[MAX+1];

long long int ans;

void dfs(int no, int c, int dist=0) {

	visitado[no] = true;
	
	for(int i = 0; i < graph[no].size(); i++) {
		int v = graph[no][i].first, d = graph[no][i].second;
		if(!visitado[v]) {
			ans += d;
			dfs(v, c, d);
			e[no] += e[v];
		}
	}

	// printf("** no=%d ans=%d\n", no, ans);	
	if(e[no]/(c * 1.0) <= 1)
		ans += dist;
	else if(e[no] % c == 0) 
		ans += (((e[no]/c) - 1) * 2 + 1) * dist;
	else {
		// printf("here");
		ans += (1 + ((e[no]/c) * 2)) * dist;
	}
	// printf("** updated: no=%d ans=%d\n", no, ans);	
}

int main() {
	
	
	int n, c;
	scanf("%d %d", &n, &c);
	
	for(int i = 1; i <= n; i++) {
		scanf(" %d", &e[i]);
		visitado[i] = false;
	}
	
	for(int i = 0; i < n-1; i++) {
		int from, to, dist;
		scanf("%d %d %d", &from, &to, &dist);
		graph[from].push_back(make_pair(to, dist));
		graph[to].push_back(make_pair(from, dist));
	}
	
	ans = 0;
	dfs(1, c);

	printf("%lld\n", ans);
	
	return 0;
}



