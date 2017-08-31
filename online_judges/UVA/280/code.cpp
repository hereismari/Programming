#include <bits/stdc++.h>
#define MAX 111
using namespace std;

bool visited[MAX];
vector<int> adj[MAX];

void init(int n, bool all){
	for(int i = 0; i < n; i++){
		visited[i] = false;
		if(all)
			adj[i].clear();
	}
}

void dfs(int x){
	for(int i = 0; i < adj[x].size(); i++)
		if(!visited[adj[x][i]]){
			visited[adj[x][i]] = true;
			dfs(adj[x][i]);
		}
}

void answer(int x, int n){

	init(n + 1,false);
	bool printed = false;
	dfs(x);

	int cont = 0;
	for(int i = 1; i <= n; i++)
		if(!visited[i])
			cont++;

	printf("%d",cont);

	for(int i = 1; i <= n; i++){
		if(!visited[i])
			printf(" %d",i);
	}
	printf("\n");
}

int main() {

	int n, x, y;
	int num;
	while(true){

		scanf("%d",&n);
		if(n == 0) break;
		init(n+1,true);	
		while(true){

			scanf("%d",&x);
			if(x == 0)
				break;

			while(true){
				scanf("%d",&y);
				if(y == 0) break;
				adj[x].push_back(y);
			}


		}

		scanf("%d",&num);
		for(int i = 0; i < num; i++)
		{
			scanf("%d",&x);
			answer(x,n);
		}

	}

	return 0;
}
